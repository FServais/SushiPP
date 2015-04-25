#include "Constant.hpp"
#include "../../visitor/ASTVisitor.hpp"

using namespace ast;
/** NT_Contant derived classes **/
/* Constant */
Constant::Constant(ASTNode* constant) : NonTerminal("Constant") 
{ 
	add_child(constant);
}

Constant::Constant(ASTNode* constant, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal("Constant", first_line, last_line, first_column, last_column)
{
	add_child(constant);
}

Constant::Constant(ASTNode* constant, const NodeLocation& node_loc) : NonTerminal("Constant", node_loc)
{
	add_child(constant);
}

ASTNode& Constant::get_constant()
{
	return *children[0];
}

void Constant::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

