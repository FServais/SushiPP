#include "NT_Statement.hpp"
#include "../../visitor/ASTVisitor.hpp"

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

void NT_Statement::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
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

void Statement::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
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

void Return::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
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

void Menu::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}


/* MenuBody */
MenuBody::MenuBody() : NT_Statement("menu body") { }

MenuBody::MenuBody(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("menu body", first_line, last_line, first_column, last_column)
{

}

MenuBody::MenuBody(const NodeLocation& node_loc) : NT_Statement("menu body", node_loc)
{

}

void MenuBody::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}


/* MenuCase */
MenuCase::MenuCase() : NT_Statement("menu case") { }

MenuCase::MenuCase(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("menu case", first_line, last_line, first_column, last_column)
{

}

MenuCase::MenuCase(const NodeLocation& node_loc) : NT_Statement("menu case", node_loc)
{

}

void MenuCase::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
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

void MenuDef::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
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

void Loop::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
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

void Roll::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
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

void Foreach::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
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

void For::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
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

void ForInitializer::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
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

void ForUpdate::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
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

void Conditional::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
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

void Elseif::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

