#include "SymbolTableVisitor.hpp"

using namespace visitor;

SymbolTableVisitor::SymbolTableVisitor(symb::SymbolTable<symb::FunctionInfo>& fct_tab, symb::SymbolTable<symb::VariableInfo>& var_tab,
		 errors::ErrorHandler& err_han)
: function_table(fct_tab), variable_table(var_tab), error_handler(err_han)
{
	
}


void SymbolTableVisitor::check_unused(size_t scp_id)
{
	size_t nb_symbol = variable_table.curr_nb_symbol(scp_id);
	for(size_t i = 0 ; i < nb_symbol ; i++)
	{
		VariableInfo v = variable_table.get_symbol(scp_id, i);
		// If a variable is found unused, then an error is created
		if(!v.get_used())
			error_handler.add_sem_error(" ",v.get_line(), v.get_column(), " unused variable : "+v.name());
	}
}

template <class S>
bool SymbolTableVisitor::symbol_exists(std::string& name, symb::SymbolTable<S>& table)
{
	size_t where = table.get_curr_scope_id();

	// check if the scope is allowed and if it contains the symbol
	if(allowed_scopes.count(where) && table.symbol_in_scope(name))
		return true;

	// check if a parent scope is allowed and contains the symbol
	while( !table.is_root() )
	{
		std::cout << "check" << std::endl; 
		table.move_to_parent_scope();
		if(allowed_scopes.count(table.get_curr_scope_id()) && table.symbol_in_scope(name))
		{
			table.move_to_scope(where);
			return true;
		}
			
	}
	table.move_to_scope(where);
	return false;
}

void SymbolTableVisitor::visit( ast::ASTNode& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::DeclVar& token )
{
	std::string name = token.get_identifier().id();
	VariableInfo data(name, token.get_location());

	if(variable_table.symbol_in_scope(name))
		error_handler.add_sem_error(" ",data.get_line(), data.get_column(), " redefined variable : "+name);

	variable_table.add_symbol(name, data);

	//continue visiting
	if(token.contains_expr())
		token.get_expression().accept(*this);
}

void SymbolTableVisitor::visit( ast::FuncCall& token )
{
	std::string func_name = token.get_function_name();

	if( !function_table.symbol_exists(func_name) && !symbol_exists<VariableInfo>(func_name,variable_table))
	{


		error_handler.add_sem_error(" ",token.get_location().first_line(), token.get_location().first_column(), 
			" undefined function : "+func_name);
	}
		
	if(function_table.symbol_exists(func_name))
		function_table.symbol_info(func_name).is_used();

	else if(symbol_exists(func_name, variable_table))
		variable_table.symbol_info(func_name).is_used();

	if(token.contains_arglist())
		token.get_arg_list().accept(*this);
}

void SymbolTableVisitor::visit( ast::Identifier& token )
{
	std::string id = token.id();

	if( function_table.symbol_exists(id) )
		function_table.symbol_info(id).is_used();

	else if(symbol_exists(id, variable_table))
		variable_table.symbol_info(id).is_used();
		
	else 
	{
		error_handler.add_sem_error(" ",token.get_location().first_line(), token.get_location().first_line(), 
			" undefined identifier : "+id);
	}
}

void SymbolTableVisitor::visit( ast::Scope& token )
{
	size_t scp_id = token.get_scope_id();
	allowed_scopes.insert(scp_id);
	// std::cout<<"ENTERING  "<<scp_id<<std::endl;
	// for(size_t scope : allowed_scopes)
	// 	std::cout << "scope  " << scope << std::endl;

	function_table.move_to_scope(scp_id);
	variable_table.move_to_scope(scp_id);

	visit_children(token);
	allowed_scopes.erase(scp_id);

	if(!function_table.is_root())
		function_table.move_to_parent_scope();

	if(!variable_table.is_root())
		variable_table.move_to_parent_scope();

	// std::cout<<"LEAVING  "<<scp_id<<std::endl;
	// for(size_t scope : allowed_scopes)
	// 	std::cout << "scope  " << scope << std::endl;

	check_unused(scp_id);
}

void SymbolTableVisitor::visit( ast::Foreach& token )
{
	token.get_expression().accept(*this);

	std::string id_name = token.get_identifier().id(); 
	symb::VariableInfo v(id_name, token.get_identifier().get_location());

	variable_table.move_to_scope(token.get_scope().get_scope_id());
	variable_table.add_symbol(id_name, v);
	variable_table.move_to_parent_scope();

	token.get_scope().accept(*this);
}

void SymbolTableVisitor::visit( ast::DeclFunc& token )
{
	std::set<size_t> prev_allowed_scopes(allowed_scopes);
	allowed_scopes.clear();
	token.get_scope().accept(*this);
	allowed_scopes = prev_allowed_scopes;
}

void SymbolTableVisitor::visit( ast::SoyFunc& token )
{
	std::set<size_t> prev_allowed_scopes(allowed_scopes);
	allowed_scopes.clear();
	token.get_scope().accept(*this);
	allowed_scopes = prev_allowed_scopes;
}

void SymbolTableVisitor::visit( ast::K_Continue& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::K_Break& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Type_Int& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Type_Float& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Type_Char& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Type_String& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Type_Array& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Type_List& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Type_Bool& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_Plus& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_Minus& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_Mult& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_Div& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_Modulo& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_Exponentiation& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_UnaryMinus& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_BitwiseOr& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_BitwiseAnd& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_BitwiseXor& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_BitwiseNot& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_LogicalOr& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_LogicalAnd& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_LogicalNot& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_CompLessThan& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_CompGreaterThan& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_CompLessEqual& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_CompGreaterEqual& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_CompEqual& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_CompNotEqual& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_LeftShift& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_RightShift& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_StringConcat& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_PrefixIncrement& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_PrefixDecrement& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_PostfixIncrement& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_PostfixDecrement& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_Assignment& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_AssignPlus& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_AssignMinus& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_AssignMult& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_AssignDiv& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_AssignExpo& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_AssignMod& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_AssignAnd& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_AssignOr& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_AssignXor& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Op_AssignConcat& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::String& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Character& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Integer& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Float& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Bool& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Array& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::List& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::MakeSequenceList& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::MakeSequenceArray& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::DeclVars& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::ParamList& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Param& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Expression& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::ExpressionList& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::ModifyingExpression& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::DatastructureAccess& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::ArgList& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Argument& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Program& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Statement& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Return& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Menu& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::MenuBody& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::MenuDef& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::MenuCase& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Roll& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::For& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::ForInitializer& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::ForUpdate& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Conditional& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Elseif& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::If& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit( ast::Else& token )
{
	visit_children(token);
}

void SymbolTableVisitor::visit_children( ast::ASTNode& token )
{
	for(auto child : token.get_children())
		child->accept(*this);
}