#include "FunctionTableVisitor.hpp"


// Constructor
FunctionTableVisitor::FunctionTableVisitor(symb::SymbolTable<symb::FunctionInfo>& fct_tab)
 : function_table(fct_tab)
{ 
	
}





/************************************
 * 		Declaration non-terminal    *
 ************************************/


void FunctionTableVisitor::visit( ast::DeclFunc& token )
{

	// first child is a identifier
	std::string id = token.get_id().id();
	// second child is a param list whose children are params
	
	std::vector<symb::VariableInfo> params;

	if( token.contains_params())
	{
		ast::ParamList param_list = token.get_param_list();
		// create a VariableInfo for each parameter of the function
		for(int i = 0; i < param_list.nb_params(); i++)
		{
			ast::Param param = param_list.get_param(i);
			std::string param_name = param.get_param_name();

			if(param.has_type())
			{
				symb::VariableInfo parameter(param_name);
				params.push_back(parameter);

			}
			else 
			{
				symb::VariableInfo parameter(param_name);
				params.push_back(parameter);
			}


		}

	}
	
	symb::FunctionInfo fct_info(id, params);
	function_table.add_symbol(id, fct_info);
	// continue visiting deeper
	token.get_scope().accept(*this);
	
}

void FunctionTableVisitor::visit( ast::SoyFunc& token )
{

	// second child is a param list whose children are params
	
	std::vector<symb::VariableInfo> params;

	if(token.contains_params())
	{
		ast::ParamList param_list = token.get_params();
		// create a VariableInfo for each parameter of the function
		for(int i = 0; i < param_list.nb_params(); i++)
		{
			ast::Param param = param_list.get_param(i);
			std::string param_name = param.get_param_name();

			if(param.has_type())
			{
				symb::VariableInfo parameter(param_name);
				params.push_back(parameter);
			}
			else 
			{
				symb::VariableInfo parameter(param_name);
				params.push_back(parameter);
			}

		}

	}

	symb::FunctionInfo fct_info(params);

	std::string name = util::random_string(10)+"$";
	
	
	token.set_name(name);

	function_table.add_symbol(name, fct_info);
	// continue visiting deeper
	token.get_scope().accept(*this);
	
}


/********************************
 * 		Program non-terminal    *
 ********************************/



void FunctionTableVisitor::visit( ast::Scope& token )
{


	size_t id_scope = function_table.add_scope();
		std::cout<<"id_scope"<<std::endl;

	function_table.move_to_scope(id_scope);

	token.set_scope_id(id_scope);

	for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);
	function_table.print_table();
	function_table.move_to_parent_scope();
	std::cout<<id_scope<<std::endl;


}


/************************
 * 		Default case    *
 ************************/
void FunctionTableVisitor::visit( ast::ASTNode& token )
{
	for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);
}

