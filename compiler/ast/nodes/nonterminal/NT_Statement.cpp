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
	 
}


/** (NT_)Program derived classes **/

/* Statement */
Statement::Statement() : NT_Statement("Statement") { }

Statement::Statement(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Statement", first_line, last_line, first_column, last_column)
{

}

Statement::Statement(const NodeLocation& node_loc) : NT_Statement("Statement", node_loc)
{

}

void Statement::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* Return */
Return::Return() : NT_Statement("Return") { }

Return::Return(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Return", first_line, last_line, first_column, last_column)
{

}

Return::Return(const NodeLocation& node_loc) : NT_Statement("Return", node_loc)
{

}

void Return::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* Menu */
Menu::Menu() : NT_Statement("Menu") { }

Menu::Menu(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Menu", first_line, last_line, first_column, last_column)
{

}

Menu::Menu(const NodeLocation& node_loc) : NT_Statement("Menu", node_loc)
{

}

void Menu::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* MenuBody */
MenuBody::MenuBody() : NT_Statement("Menu body") { }

MenuBody::MenuBody(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Menu body", first_line, last_line, first_column, last_column)
{

}

MenuBody::MenuBody(const NodeLocation& node_loc) : NT_Statement("Menu body", node_loc)
{

}

void MenuBody::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* MenuCase */
MenuCase::MenuCase() : NT_Statement("Menu case") { }

MenuCase::MenuCase(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Menu case", first_line, last_line, first_column, last_column)
{

}

MenuCase::MenuCase(const NodeLocation& node_loc) : NT_Statement("Menu case", node_loc)
{

}

void MenuCase::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* MenuDef */
MenuDef::MenuDef() : NT_Statement("Menu case definition") { }

MenuDef::MenuDef(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Menu case definition", first_line, last_line, first_column, last_column)
{

}

MenuDef::MenuDef(const NodeLocation& node_loc) : NT_Statement("Menu case definition", node_loc)
{

}

void MenuDef::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* Loop */
Loop::Loop() : NT_Statement("Loop") { }

Loop::Loop(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Loop", first_line, last_line, first_column, last_column)
{

}

Loop::Loop(const NodeLocation& node_loc) : NT_Statement("Loop", node_loc)
{

}

void Loop::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* Roll */
Roll::Roll() : NT_Statement("Roll") { }

Roll::Roll(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Roll", first_line, last_line, first_column, last_column)
{

}

Roll::Roll(const NodeLocation& node_loc) : NT_Statement("Roll", node_loc)
{

}

void Roll::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* Foreach */
Foreach::Foreach() : NT_Statement("Foreach") { }

Foreach::Foreach(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Foreach", first_line, last_line, first_column, last_column)
{

}

Foreach::Foreach(const NodeLocation& node_loc) : NT_Statement("Foreach", node_loc)
{

}

void Foreach::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* For */
For::For() : NT_Statement("For") { }

For::For(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("For", first_line, last_line, first_column, last_column)
{

}

For::For(const NodeLocation& node_loc) : NT_Statement("For", node_loc)
{

}

void For::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* ForInitializer */
ForInitializer::ForInitializer() : NT_Statement("For initializer") { }

ForInitializer::ForInitializer(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("For initializer", first_line, last_line, first_column, last_column)
{

}

ForInitializer::ForInitializer(const NodeLocation& node_loc) : NT_Statement("For initializer", node_loc)
{

}

void ForInitializer::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* ForUpdate */
ForUpdate::ForUpdate() : NT_Statement("For update") { }

ForUpdate::ForUpdate(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("For update", first_line, last_line, first_column, last_column)
{

}

ForUpdate::ForUpdate(const NodeLocation& node_loc) : NT_Statement("For update", node_loc)
{

}

void ForUpdate::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* Conditional */
Conditional::Conditional() : NT_Statement("Conditional") { }

Conditional::Conditional(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Conditional", first_line, last_line, first_column, last_column)
{

}

Conditional::Conditional(const NodeLocation& node_loc) : NT_Statement("Conditional", node_loc)
{

}

void Conditional::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}


/* Elseif */
Elseif::Elseif() : NT_Statement("Elseif") { }

Elseif::Elseif(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Elseif", first_line, last_line, first_column, last_column)
{

}

Elseif::Elseif(const NodeLocation& node_loc) : NT_Statement("Elseif", node_loc)
{

}

void Elseif::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

Else::Else() : NT_Statement("Else") { }

Else::Else(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Else", first_line, last_line, first_column, last_column)
{

}

Else::Else(const NodeLocation& node_loc) : NT_Statement("Else", node_loc)
{

}

void Else::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}


