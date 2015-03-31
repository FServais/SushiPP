#include "NT_Statement.hpp"

using namespace ast;

/** Constant base class */
NT_Statement::NT_Statement(const std::string& node_name) : NonTerminal(node_name) {}

NT_Statement::NT_Statement(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Statement::NT_Statement(const std::string& node_name, const NodeLocation& node_loc)
	: NonTerminal(node_name, node_loc)
{

}

/** (NT_)Program derived classes **/

/* Statement */
Statement::Statement() : NT_Statement("statement") { }

Statement::Statement(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("statement", first_line, last_line, first_column, last_column)
{

}

Statement::Statement(const NodeLocation& node_loc) : NT_Statement("statement", node_loc)
{

}

/* Return */
Return::Return() : NT_Statement("return") { }

Return::Return(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("return", first_line, last_line, first_column, last_column)
{

}

Return::Return(const NodeLocation& node_loc) : NT_Statement("return", node_loc)
{

}

/* Menu */
Menu::Menu() : NT_Statement("menu") { }

Menu::Menu(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("menu", first_line, last_line, first_column, last_column)
{

}

Menu::Menu(const NodeLocation& node_loc) : NT_Statement("menu", node_loc)
{

}

/* MenuDef */
MenuDef::MenuDef() : NT_Statement("menudef") { }

MenuDef::MenuDef(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("menudef", first_line, last_line, first_column, last_column)
{

}

MenuDef::MenuDef(const NodeLocation& node_loc) : NT_Statement("menudef", node_loc)
{

}

/* Loop */
Loop::Loop() : NT_Statement("loop") { }

Loop::Loop(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("loop", first_line, last_line, first_column, last_column)
{

}

Loop::Loop(const NodeLocation& node_loc) : NT_Statement("loop", node_loc)
{

}

/* Roll */
Roll::Roll() : NT_Statement("roll") { }

Roll::Roll(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("roll", first_line, last_line, first_column, last_column)
{

}

Roll::Roll(const NodeLocation& node_loc) : NT_Statement("roll", node_loc)
{

}

/* Foreach */
Foreach::Foreach() : NT_Statement("foreach") { }

Foreach::Foreach(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("foreach", first_line, last_line, first_column, last_column)
{

}

Foreach::Foreach(const NodeLocation& node_loc) : NT_Statement("foreach", node_loc)
{

}

/* For */
For::For() : NT_Statement("for") { }

For::For(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("for", first_line, last_line, first_column, last_column)
{

}

For::For(const NodeLocation& node_loc) : NT_Statement("for", node_loc)
{

}

/* ForInitializer */
ForInitializer::ForInitializer() : NT_Statement("forinitializer") { }

ForInitializer::ForInitializer(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("forinitializer", first_line, last_line, first_column, last_column)
{

}

ForInitializer::ForInitializer(const NodeLocation& node_loc) : NT_Statement("forinitializer", node_loc)
{

}

/* ForUpdate */
ForUpdate::ForUpdate() : NT_Statement("forupdate") { }

ForUpdate::ForUpdate(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("forupdate", first_line, last_line, first_column, last_column)
{

}

ForUpdate::ForUpdate(const NodeLocation& node_loc) : NT_Statement("forupdate", node_loc)
{

}

/* Conditional */
Conditional::Conditional() : NT_Statement("conditional") { }

Conditional::Conditional(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("conditional", first_line, last_line, first_column, last_column)
{

}

Conditional::Conditional(const NodeLocation& node_loc) : NT_Statement("conditional", node_loc)
{

}

/* Elseif */
Elseif::Elseif() : NT_Statement("elseif") { }

Elseif::Elseif(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("elseif", first_line, last_line, first_column, last_column)
{

}

Elseif::Elseif(const NodeLocation& node_loc) : NT_Statement("elseif", node_loc)
{

}
