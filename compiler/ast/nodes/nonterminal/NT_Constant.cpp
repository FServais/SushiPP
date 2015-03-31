#include "NT_Constant.hpp"

using namespace ast::nodes::nonterminals::nt_constant;
using ast::nodes::nonterminals::NonTerminal;

/** Constant class */
NT_Constant::NT_Constant(const std::string& node_name) : NonTerminal(node_name) {}

NT_Constant::NT_Constant(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Constant::NT_Constant(const std::string& node_name, const NodeLocation& loc)
	: NonTerminal(node_name, node_loc)
{

}

