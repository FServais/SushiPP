#include "SymbolTableVisitor.hpp"

using namespace visitor;

SymbolTableVisitor::SymbolTableVisitor(symb::SymbolTable<symb::FunctionInfo>& fct_tab, symb::SymbolTable<symb::VariableInfo>& var_tab)
: function_table(fct_tab), variable_table(var_tab)
{
	
}

void SymbolTableVisitor::visit(ast::ASTNode& token)
{
	visit_children(token);
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

	visit_children(token);
	
	function_table.move_to_parent_scope();
	variable_table.move_to_parent_scope();
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

void SymbolTableVisitor::visit( ast::DeclFunc& token )
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

void SymbolTableVisitor::visit( ast::SoyFunc& token )
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

void SymbolTableVisitor::visit( ast::Foreach& token )
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

void SymbolTableVisitor::visit_children( ast::ASTNode& token )
{
	for(auto child : token.get_children())
		child->accept(*this);
}