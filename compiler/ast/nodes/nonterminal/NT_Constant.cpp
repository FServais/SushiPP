#include "NT_Constant.hpp"

using namespace ast;
/** NT_Contant derived classes **/
/* NT_Constant */
NT_Constant::NT_Constant() : NonTerminal("constant") { }

NT_Constant::NT_Constant(int first_line, int last_line, int first_column, int last_column)
	: NonTerminal("constant", first_line, last_line, first_column, last_column)
{

}

NT_Constant::NT_Constant(const NodeLocation& node_loc) : NonTerminal("constant", node_loc)
{

}

