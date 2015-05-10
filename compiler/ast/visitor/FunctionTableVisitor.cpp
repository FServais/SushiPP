#include "FunctionTableVisitor.hpp"

#include <tuple>
#include <iterator>

using namespace visitor;

// Constructor
FunctionTableVisitor::FunctionTableVisitor( symb::SymbolTable<symb::FunctionInfo>& fct_tab, symb::SymbolTable<symb::VariableInfo>& var_tab,
	errors::ErrorHandler& err_han, settings::BuiltInFunctions& built_in)
 : function_table(fct_tab), variable_table(var_tab), error_handler(err_han)
{ 
	counter = 0;

	// add built in functions
	for(auto& function : built_in)
	{
		std::vector<symb::VariableInfo> vars;
		transform(std::get<1>(function.second).begin(), std::get<1>(function.second).end(),
				  back_inserter(vars), 
				  [](const std::string& varname) { return symb::VariableInfo(varname); });
		function_table.add_symbol(function.first, symb::FunctionInfo(function.first, vars));
	}
}

/************************************
 * 		Declaration non-terminal    *
 ************************************/
void FunctionTableVisitor::visit( ast::DeclFunc& token )
{
	if(counter > 1)
		error_handler.add_sem_error(" ", token.get_location().first_line(), token.get_location().first_column(), "Dead code in the function");

	// first child is a identifier
	std::string id = token.get_id().id();

	if(variable_table.symbol_exists(id) || function_table.symbol_exists(id))
		error_handler.add_sem_error(" ",token.get_location().first_line(), token.get_location().first_column(), " Redefined function : "+id);
	// second child is a param list whose children are params
	std::vector<symb::VariableInfo> params;

	if( token.contains_params())
	{
		ast::ParamList& param_list = token.get_param_list();
		// create a VariableInfo for each parameter of the function
		for(int i = 0; i < param_list.nb_params(); i++)
		{
			ast::Param& param = param_list.get_param(i);
			std::string param_name = param.get_param_name();
			symb::VariableInfo parameter(param_name, param.get_location());
			params.push_back(parameter);

		}
	}
	
	symb::FunctionInfo fct_info(id, params, token.get_location());
	function_table.add_symbol(id, fct_info);

	
	is_there_a_return_gen = false;
	is_there_an_empty_return_gen = false;
	ret = true;
	counter = 0;

	token.get_scope().accept(*this);

	if(is_there_a_return_gen & !ret)
	{
		//find the last statement, which must return in any case
		error_handler.add_sem_error(" ", token.get_location().first_line(), token.get_location().first_column(), "Wrong termination");

	}

	if(is_there_a_return_gen && is_there_an_empty_return_gen)
		error_handler.add_sem_error(" ", token.get_location().first_line(), token.get_location().first_column(), "Non uniform returns");
			
	counter = 0;
	variable_table.move_to_scope(token.get_scope().get_scope_id());

	for(symb::VariableInfo v : params)
	{
		variable_table.add_symbol(v.name(), v);	
	}
		

	variable_table.move_to_parent_scope();
}

void FunctionTableVisitor::visit( ast::SoyFunc& token )
{
	// second child is a param list whose children are params
	
	std::vector<symb::VariableInfo> params;

	if(token.contains_params())
	{
		ast::ParamList& param_list = token.get_params();
		// create a VariableInfo for each parameter of the function
		for(int i = 0; i < param_list.nb_params(); i++)
		{
			ast::Param& param = param_list.get_param(i);
			std::string param_name = param.get_param_name();

			symb::VariableInfo parameter(param_name, param.get_location());
			params.push_back(parameter);
			
		}
	}

	symb::FunctionInfo fct_info(params, token.get_location());

	std::string name = util::random_string(10)+"$";
	
	
	token.set_name(name);

	function_table.add_symbol(name, fct_info);
	// continue visiting deeper
	is_there_a_return_gen = false;
	is_there_an_empty_return_gen = false;
	ret = true;
	counter = 0;
	token.get_scope().accept(*this);

	if(is_there_a_return_gen & !ret)
	{
		//find the last statement, which must return in any case
		error_handler.add_sem_error(" ", token.get_location().first_line(), token.get_location().first_column(), "Wrong function termination");

	}
	
	if(is_there_a_return_gen && is_there_an_empty_return_gen)
		error_handler.add_sem_error(" ", token.get_location().first_line(), token.get_location().first_column(), "Non uniform returns");


	counter = 0;

	variable_table.move_to_scope(token.get_scope().get_scope_id());

	for(symb::VariableInfo v : params)
		variable_table.add_symbol(v.name(), v);

	variable_table.move_to_parent_scope();

}


/********************************
 * 		Program non-terminal    *
 ********************************/
void FunctionTableVisitor::visit( ast::Scope& token )
{
	size_t id_scope = function_table.add_scope();
	variable_table.add_scope(id_scope);

	function_table.move_to_scope(id_scope);
	variable_table.move_to_scope(id_scope);
	token.set_scope_id(id_scope);
	counter = 0;
	prev_ret = ret; 
	ret = true;

	for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);

	// if ret is false, it should stay false, otherwise restore old value
	if(ret)
		ret = prev_ret;
	prev_ret = true;
	counter = 0;

	if(!function_table.is_root())
		function_table.move_to_parent_scope();

	if(!variable_table.is_root())
		variable_table.move_to_parent_scope();
	

}

void FunctionTableVisitor::visit( ast::Return& token )
{
	if(!token.empty_nori())
	{
		is_there_a_return_loc = true;
		is_there_a_return_gen = true;
	}
	else 
		is_there_an_empty_return_gen = true;
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Statement& token )
{
	if(counter > 0)
	{
		error_handler.add_sem_error(" ", token.get_location().first_line(), token.get_location().first_column(), "Dead code in the function");
	}
	ret = true;
	visit_children(token);
	if(ret)
		counter++;
} 

void FunctionTableVisitor::visit( ast::Conditional& token )
{
	def_case = false;
	visit_children(token);
	if(!def_case)
		ret = false;
} 

void FunctionTableVisitor::visit( ast::Elseif& token )
{
	is_there_a_return_loc = false;
	visit_children(token);
	if(!is_there_a_return_loc)
		ret = false;
} 

void FunctionTableVisitor::visit( ast::If& token )
{
	is_there_a_return_loc = false;
	visit_children(token);
	if(!is_there_a_return_loc)
		ret = false;
}

void FunctionTableVisitor::visit( ast::Else& token )
{
	def_case = true;
	is_there_a_return_loc = false;
	visit_children(token);
	if(!is_there_a_return_loc)
		ret = false;
}


void FunctionTableVisitor::visit( ast::Menu& token )
{
	def_case = false;
	visit_children(token);
	if(!def_case)
		ret = false;
} 

void FunctionTableVisitor::visit( ast::MenuDef& token )
{
	def_case = true;
	is_there_a_return_loc = false;
	visit_children(token);
	if(!is_there_a_return_loc)
		ret = false;

} 

void FunctionTableVisitor::visit( ast::MenuCase& token )
{
	is_there_a_return_loc = false;
	visit_children(token);
	if(!is_there_a_return_loc)
		ret = false;
} 

void FunctionTableVisitor::visit( ast::MenuBody& token) 
{
	visit_children(token);
}

void FunctionTableVisitor::visit( ast::Roll& token )
{
	visit_children(token);
	ret = false;
} 

void FunctionTableVisitor::visit( ast::Foreach& token )
{
	visit_children(token);
	ret = false;
} 

void FunctionTableVisitor::visit( ast::For& token )
{
	visit_children(token);
	ret = false;
} 


/************************
 * 		Default case    *
 ************************/

void FunctionTableVisitor::visit_children( ast::ASTNode& token )
{ 
	for(auto child : token.get_children()) 
		child->accept(*this); 
}


void FunctionTableVisitor::visit( ast::ASTNode& token )
{
	visit_children(token);
}

void FunctionTableVisitor::visit( ast::Identifier& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::K_Continue& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::K_Break& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Type_Int& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Type_Float& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Type_Char& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Type_String& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Type_Array& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Type_List& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Type_Bool& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_Plus& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_Minus& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_Mult& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_Div& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_Modulo& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_Exponentiation& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_UnaryMinus& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_BitwiseOr& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_BitwiseAnd& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_BitwiseXor& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_BitwiseNot& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_LogicalOr& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_LogicalAnd& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_LogicalNot& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_CompLessThan& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_CompGreaterThan& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_CompLessEqual& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_CompGreaterEqual& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_CompEqual& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_CompNotEqual& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_LeftShift& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_RightShift& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_StringConcat& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_PrefixIncrement& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_PrefixDecrement& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_PostfixIncrement& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_PostfixDecrement& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_Assignment& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_AssignPlus& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_AssignMinus& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_AssignMult& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_AssignDiv& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_AssignExpo& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_AssignMod& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_AssignAnd& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_AssignOr& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_AssignXor& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Op_AssignConcat& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::String& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Character& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Integer& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Float& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Bool& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Array& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::List& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::MakeSequenceList& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::MakeSequenceArray& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::DeclVars& token )
{
	if(counter > 0)
		error_handler.add_sem_error(" ", token.get_location().first_line(), token.get_location().first_column(), "Dead code in the function");

	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::DeclVar& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::ParamList& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Param& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Expression& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::ModifyingExpression& token )
{
	if(counter > 0)
		error_handler.add_sem_error(" ", token.get_location().first_line(), token.get_location().first_column(), "Dead code in the function");

	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::DatastructureAccess& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::FuncCall& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::ArgList& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Argument& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::Program& token )
{
	visit_children(token);
} 



void FunctionTableVisitor::visit( ast::ForInitializer& token )
{
	visit_children(token);
} 

void FunctionTableVisitor::visit( ast::ForUpdate& token )
{
	visit_children(token);
} 


