#include "NonTerminal.hpp"

using namespace ast;


/***************************
 * Non-terminal base class *
 ***************************/
NonTerminal::NonTerminal(const std::string& node_name) : ASTNode(node_name) {}

NonTerminal::NonTerminal(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: ASTNode(node_name, first_line, last_line, first_column, last_column)
{

}

NonTerminal::NonTerminal(const std::string& node_name, const NodeLocation& node_loc)
	: ASTNode(node_name, node_loc)
{

}

