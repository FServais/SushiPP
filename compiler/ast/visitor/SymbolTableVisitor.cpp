#include "SymbolTableVisitor.hpp"



SymbolTableVisitor::SymbolTableVisitor(symb::SymbolTable<symb::FunctionInfo>& fct_tab, symb::SymbolTable<symb::VariableInfo>& var_tab)
: function_table(fct_tab), variable_table(var_tab)
{
	
}




void SymbolTableVisitor::visit(ast::ASTNode& token)
{
	for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);
}

void SymbolTableVisitor::visit( ast::DeclVar& token)
{
	std::string name = token.get_identifier().id();
	VariableInfo data(name);
	variable_table.add_symbol(name, data);

	//continue visiting
	if(token.contains_expr())
		token.get_expression().accept(*this);
}


void SymbolTableVisitor::visit( ast::FuncCall& token )
{
	std::string func_name = token.get_function_name();

	if( !function_table.symbol_exists(func_name) )
		throw except::UndefinedSymbolException("Call to an undefined function");

	if( token.contains_arglist() )
	{

		int nb_params = function_table.symbol_info(func_name).nb_params();
		ast::ArgList arg_list = token.get_arg_list();
		int nb_args = arg_list.nb_args();

		if( nb_params != nb_args )
			throw except::BadParameterNumberException("The number of arguments given does not match the function definition");

		arg_list.accept(*this);
	}

	
}


void SymbolTableVisitor::visit( ast::Identifier& token )
{
	std::string id = token.id();

	if( !function_table.symbol_exists(id) && !variable_table.symbol_exists(id) )
		throw except::UndefinedSymbolException(id);
}

void SymbolTableVisitor::visit( ast::Scope& token )
{

	size_t scp_id = token.get_scope_id();
	function_table.move_to_scope(scp_id);

	variable_table.add_scope(scp_id);
	variable_table.move_to_scope(scp_id);

	for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);
	
	function_table.move_to_parent_scope();
	variable_table.move_to_parent_scope();
}