#include "NT_Constant.hpp"
#include "../../visitor/ASTVisitor.hpp"

using namespace ast;
/** NT_Contant derived classes **/
/* NT_Constant */
NT_Constant::NT_Constant(ASTNode* type) : NonTerminal("Constant") 
{ 
	add_child(type);
}

NT_Constant::NT_Constant(ASTNode* type, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal("Constant", first_line, last_line, first_column, last_column)
{
	add_child(type);
}

NT_Constant::NT_Constant(ASTNode* type, const NodeLocation& node_loc) : NonTerminal("Constant", node_loc)
{
	add_child(type);
}

ASTNode& NT_Constant::get_type()
{
	return *children[0];
}


void NT_Constant::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

