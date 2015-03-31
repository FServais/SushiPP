#include "NonTerminal.hpp"

using namespace ast::nodes::nonterminal::NonTerminal;
using ast::nodes::ASTNode;
using ast::nodes::NodeLocation;


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


/******************************************
 * Non-terminal intermediate base classes *
 ******************************************/

/** NT_Program */
NT_Program::NT_Program(const std::string& node_name) : NonTerminal(node_name) {}

NT_Program::NT_Program(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Program::NT_Program(const std::string& node_name, const NodeLocation& loc)
	: NonTerminal(node_name, node_loc)
{

}


/** NT_Declaration */
NT_Declaration::NT_Declaration(const std::string& node_name) : NonTerminal(node_name) {}

NT_Declaration::NT_Declaration(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Declaration::NT_Declaration(const std::string& node_name, const NodeLocation& loc)
	: NonTerminal(node_name, node_loc)
{

}


/** NT_FunctionCall */
NT_FunctionCall::NT_FunctionCall(const std::string& node_name) : NonTerminal(node_name) {}

NT_FunctionCall::NT_FunctionCall(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_FunctionCall::NT_FunctionCall(const std::string& node_name, const NodeLocation& loc)
	: NonTerminal(node_name, node_loc)
{

}


/** NT_Expression */
NT_Expression::NT_Expression(const std::string& node_name) : NonTerminal(node_name) {}

NT_Expression::NT_Expression(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Expression::NT_Expression(const std::string& node_name, const NodeLocation& loc)
	: NonTerminal(node_name, node_loc)
{

}


/** NT_Constant */
NT_Constant::NT_Constant(const std::string& node_name) : NonTerminal(node_name) {}

NT_Constant::NT_Constant(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Constant::NT_Constant(const std::string& node_name, const NodeLocation& loc)
	: NonTerminal(node_name, node_loc)
{

}


/** NT_Datastructure */
NT_Datastructure::NT_Datastructure(const std::string& node_name) : NonTerminal(node_name) {}

NT_Datastructure::NT_Datastructure(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Datastructure::NT_Datastructure(const std::string& node_name, const NodeLocation& loc)
	: NonTerminal(node_name, node_loc)
{

}


/** NT_Statement */
NT_Statement::NT_Statement(const std::string& node_name) : NonTerminal(node_name) {}

NT_Statement::NT_Statement(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Statement::NT_Statement(const std::string& node_name, const NodeLocation& loc)
	: NonTerminal(node_name, node_loc)
{

}
