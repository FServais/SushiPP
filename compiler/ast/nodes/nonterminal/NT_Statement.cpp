#include "NT_Statement.hpp"

using namespace ast::nodes::nonterminals::nt_statement;
using ast::nodes::nonterminals::NonTerminal;

/** Constant base class */
NT_Statement::NT_Statement(const std::string& node_name) : NonTerminal(node_name) {}

NT_Statement::NT_Statement(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Statement::NT_Statement(const std::string& node_name, const NodeLocation& loc)
	: NonTerminal(node_name, node_loc)
{

}

/** (NT_)Program derived classes **/

/* Statement */
Statement::Statement() : NT_FunctionCall("statement") { }

Statement::Statement(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("statement", first_line, last_line, first_column, last_column)
{

}

Statement::Statement(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("statement", node_loc)
{

}

/* Return */
Return::Return() : NT_FunctionCall("return") { }

Return::Return(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("return", first_line, last_line, first_column, last_column)
{

}

Return::Return(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("return", node_loc)
{

}

/* Menu */
Menu::Menu() : NT_FunctionCall("menu") { }

Menu::Menu(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("menu", first_line, last_line, first_column, last_column)
{

}

Menu::Menu(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("menu", node_loc)
{

}

/* MenuDef */
MenuDef::MenuDef() : NT_FunctionCall("menudef") { }

MenuDef::MenuDef(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("menudef", first_line, last_line, first_column, last_column)
{

}

MenuDef::MenuDef(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("menudef", node_loc)
{

}

/* Loop */
Loop::Loop() : NT_FunctionCall("loop") { }

Loop::Loop(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("loop", first_line, last_line, first_column, last_column)
{

}

Loop::Loop(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("loop", node_loc)
{

}

/* Roll */
Roll::Roll() : NT_FunctionCall("roll") { }

Roll::Roll(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("roll", first_line, last_line, first_column, last_column)
{

}

Roll::Roll(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("roll", node_loc)
{

}

/* Foreach */
Foreach::Foreach() : NT_FunctionCall("foreach") { }

Foreach::Foreach(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("foreach", first_line, last_line, first_column, last_column)
{

}

Foreach::Foreach(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("foreach", node_loc)
{

}

/* For */
For::For() : NT_FunctionCall("for") { }

For::For(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("for", first_line, last_line, first_column, last_column)
{

}

For::For(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("for", node_loc)
{

}

/* ForInitializer */
ForInitializer::ForInitializer() : NT_FunctionCall("forinitializer") { }

ForInitializer::ForInitializer(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("forinitializer", first_line, last_line, first_column, last_column)
{

}

ForInitializer::ForInitializer(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("forinitializer", node_loc)
{

}

/* ForUpdate */
ForUpdate::ForUpdate() : NT_FunctionCall("forupdate") { }

ForUpdate::ForUpdate(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("forupdate", first_line, last_line, first_column, last_column)
{

}

ForUpdate::ForUpdate(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("forupdate", node_loc)
{

}

/* Conditional */
Conditional::Conditional() : NT_FunctionCall("conditional") { }

Conditional::Conditional(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("conditional", first_line, last_line, first_column, last_column)
{

}

Conditional::Conditional(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("conditional", node_loc)
{

}

/* Elseif */
Elseif::Elseif() : NT_FunctionCall("elseif") { }

Elseif::Elseif(int first_line, int last_line, int first_column, int last_column) 
	: NT_FunctionCall("elseif", first_line, last_line, first_column, last_column)
{

}

Elseif::Elseif(const ast::nodes::NodeLocation& node_loc) : NT_FunctionCall("elseif", node_loc)
{

}
