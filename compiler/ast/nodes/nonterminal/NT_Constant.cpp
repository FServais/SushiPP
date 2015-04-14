#include "NT_Constant.hpp"
#include "../../visitor/ASTVisitor.hpp"

using namespace ast;
/** NT_Contant derived classes **/
/* NT_Constant */
NT_Constant::NT_Constant() : NonTerminal("Constant") { }

NT_Constant::NT_Constant(int first_line, int last_line, int first_column, int last_column)
	: NonTerminal("Constant", first_line, last_line, first_column, last_column)
{

}

NT_Constant::NT_Constant(const NodeLocation& node_loc) : NonTerminal("Constant", node_loc)
{

}

void NT_Constant::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

