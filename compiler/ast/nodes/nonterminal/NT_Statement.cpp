#include "NT_Statement.hpp"
#include "../../visitor/ASTVisitor.hpp"
#include "../../../exceptions/Exceptions.hpp"

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
Statement::Statement(ASTNode* statement) : NT_Statement("Statement") 
{ 
	add_child(statement);	
}

Statement::Statement(ASTNode* statement, int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Statement", first_line, last_line, first_column, last_column)
{
	add_child(statement);
}

Statement::Statement(ASTNode* statement, const NodeLocation& node_loc) : NT_Statement("Statement", node_loc)
{
	add_child(statement);
}

void Statement::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

ASTNode& Statement::get_statement()
{
	return *children[0];
}
		
/* Return */
Return::Return(ASTNode* return_expression) : NT_Statement("Return") 
{ 
	add_child(return_expression);
}

Return::Return(ASTNode* return_expression, int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Return", first_line, last_line, first_column, last_column)
{
	add_child(return_expression);
}

Return::Return(ASTNode* return_expression, const NodeLocation& node_loc) : NT_Statement("Return", node_loc)
{
	add_child(return_expression);
}

Return::Return() : NT_Statement("Return") { }

Return::Return(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Return", first_line, last_line, first_column, last_column)
{

}

Return::Return(const NodeLocation& node_loc) : NT_Statement("Return", node_loc)
{

}
		
bool Return::empty_nori()
{
	return children.size() == 0;
}
	
ASTNode& Return::get_returned_expression()
{
	if(empty_nori())
		throw NoSuchChildException("this nori is an empty nori");
	return *children[0];
}

void Return::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}


/* Menu */
Menu::Menu(MenuBody* body, ASTNode* expr) : NT_Statement("Menu") 
{ 
	add_child(expr);
	add_child(body);
}

Menu::Menu(MenuBody* body, ASTNode* expr, int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Menu", first_line, last_line, first_column, last_column)
{
	add_child(expr);
	add_child(body);
}

Menu::Menu(MenuBody* body, ASTNode* expr, const NodeLocation& node_loc) : NT_Statement("Menu", node_loc)
{
	add_child(expr);
	add_child(body);
}

MenuBody& Menu::get_body()
{
	return *children[1];
}

ASTNode& Menu::get_expression()
{
	return *children[0];
}

void Menu::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* MenuBody */
MenuBody::MenuBody(MenuDef* default_case) 
  : NT_Statement("Menu body"), 
    has_default(true)
{

}

MenuBody::MenuBody(MenuDef* default_case, int first_line, int last_line, int first_column, int last_column)
  : NT_Statement("Menu body", first_line, last_line, first_column, last_column),
	has_default(true)
{

}

MenuBody::MenuBody(MenuDef* default_case, const NodeLocation& node_loc) 
  : NT_Statement("Menu body", node_loc), 
	has_default(true)
{

}

MenuBody::MenuBody(MenuCase* menu_case) 
  : NT_Statement("Menu body"),
  	has_default(false)
{

}

MenuBody::MenuBody(MenuCase* menu_case, int first_line, int last_line, int first_column, int last_column)
  : NT_Statement("Menu body", first_line, last_line, first_column, last_column),
  	has_default(false)
{

}

MenuBody::MenuBody(MenuCase* menu_case, const NodeLocation& node_loc) 
  : NT_Statement("Menu body", node_loc),
  	has_default(false)
{

}

void MenuBody::add_case(MenuCase* menu_case)
{
	children.insert(children.begin(), menu_case);
}

MenuDef& MenuBody::get_default_case()
{
	if(!contains_default())
		throw NoSuchChildException("this menu body contains no default case child");
	return *children.back();
}

size_t MenuBody::nb_cases() const
{
	return contains_default() ? children.size() - 1 : children.size();
}

MenuCase& MenuBody::get_nth_case(size_t n)
{
	if(n >= nb_cases())
		throw NoSuchChildException("the given index does not refers to an existing case");
	return *dynamic_cast<MenuCase*>(children[n]);
}

void MenuBody::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* MenuCase */
MenuCase::MenuCase() : NT_Statement("Case") { }

MenuCase::MenuCase(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Case", first_line, last_line, first_column, last_column)
{

}

MenuCase::MenuCase(const NodeLocation& node_loc) : NT_Statement("Case", node_loc)
{

}

void MenuCase::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}


/* MenuDef */
MenuDef::MenuDef() : NT_Statement("Default case") { }

MenuDef::MenuDef(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Default case", first_line, last_line, first_column, last_column)
{

}

MenuDef::MenuDef(const NodeLocation& node_loc) : NT_Statement("Default case", node_loc)
{

}

void MenuDef::accept(ASTVisitor& visitor)
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

/* If */
If::If() : NT_Statement("If") { }

If::If(int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("If", first_line, last_line, first_column, last_column)
{

}

If::If(const NodeLocation& node_loc) : NT_Statement("If", node_loc)
{

}

void If::accept(ASTVisitor& visitor)
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
}


