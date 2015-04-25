#include "FunctionTableVisitor.hpp"

using namespace std;
using namespace visitor;

// Constructor
FunctionTableVisitor::FunctionTableVisitor(symb::SymbolTable<symb::FunctionInfo>& fct_tab){ function_table =  fct_tab;}





/************************************
 * 		Declaration non-terminal    *
 ************************************/


void FunctionTableVisitor::visit( ast::DeclFunc& token )
{
	std::vector<ASTNode*> children = token.get_children();
	// first child is a identifier
	std::string id = children[0]->id();
	// second child is a param list whose children are params
	std::vector<ASTNode*> params = children[1].get_children();
	std::vector<VariableInfo> param_list;

	// create a VariableInfo for each parameter of the function
	for(auto it = params.begin(); it != params.end(); it++)
	{
			std::vector<ASTNode*> param_children = (*it).get_children();
			std:: string param_name = param_children[0]->id();
			symb::Type type = param_children[1]->get_type();
			VariableInfo param(param_name, type);
			param_list.push_back(param);

	}

	FunctionInfo fct_info(id, param_list, UNDEFINED);
	function_table.add_symbol(id, fct_info);

	for(auto it = (children.begin()+2); it != children.end(); it++)
	{
		(*it)->accept(*this);
	}
}

void FunctionTableVisitor::visit( ast::SoyFunc& token )
{
	std::vector<ASTNode*> children = token.get_children();
	
	// first child is a param list whose children are params
	std::vector<ASTNode*> params = children[0].get_children();
	std::vector<VariableInfo> param_list;

	// create a VariableInfo for each parameter of the function
	for(auto it = params.begin(); it != params.end(); it++)
	{
			std::vector<ASTNode*> param_children = (*it).get_children();
			std:: string param_name = param_children[0]->id();
			symb::Type type = param_children[1]->get_type();
			VariableInfo param(param_name, type);
			param_list.push_back(param);

	}

	FunctionInfo fct_info(param_list, UNDEFINED);
	std::string name = random_string();
	while(function_table.symbol_exists(name))
		name = random_string();

	function_table.add_symbol(name, fct_info);

	for(auto it = (children.begin()+1); it != children.end(); it++)
	{
		(*it)->accept(*this);
	}
}


/********************************
 * 		Program non-terminal    *
 ********************************/



void FunctionTableVisitor::visit( ast::Scope& token )
{

	int id_scope = function_table.add_scope();
	function_table.move_to_scope(id_scope);
	for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);
	function_table.move_to_oarent_scope();

}


/************************
 * 		Default case    *
 ************************/
void FunctionTableVisitor::visit( ast::ASTNode& token )
{
	for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);
}

