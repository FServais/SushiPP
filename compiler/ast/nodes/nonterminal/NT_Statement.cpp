#include "NT_Statement.hpp"
#include "../../visitor/ASTVisitor.hpp"
#include "../../../exceptions/Exceptions.hpp"

using namespace ast;
using namespace except;

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

void NT_Statement::accept(visitor::ASTVisitor& visitor)
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

void Statement::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

ASTNode& Statement::get_statement()
{
	return *children[0];
}
		
/* Return */
Return::Return(Expression* return_expression) : NT_Statement("Return") 
{ 
	add_child(return_expression);
}

Return::Return(Expression* return_expression, int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Return", first_line, last_line, first_column, last_column)
{
	add_child(return_expression);
}

Return::Return(Expression* return_expression, const NodeLocation& node_loc) : NT_Statement("Return", node_loc)
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
	
Expression& Return::get_returned_expression()
{
	if(empty_nori())
		throw NoSuchChildException(" this nori is an empty nori");
	return *dynamic_cast<Expression*>(children[0]);
}

void Return::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}


#include <iostream>
/* Menu */
Menu::Menu(MenuBody* body, Expression* expr) : NT_Statement("Menu") 
{ 
	add_child(expr);
	add_child(body);
}

Menu::Menu(MenuBody* body, Expression* expr, int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Menu", first_line, last_line, first_column, last_column)
{
	add_child(expr);
	add_child(body);
}

Menu::Menu(MenuBody* body, Expression* expr, const NodeLocation& node_loc) : NT_Statement("Menu", node_loc)
{
	add_child(expr);
	add_child(body);
}

MenuBody& Menu::get_body()
{
	return *dynamic_cast<MenuBody*>(children[1]);
}

Expression& Menu::get_expression()
{
	return *dynamic_cast<Expression*>(children[0]);
}

void Menu::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* MenuBody */
MenuBody::MenuBody(MenuDef* default_case) 
  : NT_Statement("Menu body"), 
    has_default(true)
{
	add_child(default_case);
}

MenuBody::MenuBody(MenuDef* default_case, int first_line, int last_line, int first_column, int last_column)
  : NT_Statement("Menu body", first_line, last_line, first_column, last_column),
	has_default(true)
{
	add_child(default_case);
}

MenuBody::MenuBody(MenuDef* default_case, const NodeLocation& node_loc) 
  : NT_Statement("Menu body", node_loc), 
	has_default(true)
{
	add_child(default_case);
}

MenuBody::MenuBody(MenuCase* menu_case) 
  : NT_Statement("Menu body"),
  	has_default(false)
{
	add_child(menu_case);
}

MenuBody::MenuBody(MenuCase* menu_case, int first_line, int last_line, int first_column, int last_column)
  : NT_Statement("Menu body", first_line, last_line, first_column, last_column),
  	has_default(false)
{
	add_child(menu_case);
}

MenuBody::MenuBody(MenuCase* menu_case, const NodeLocation& node_loc) 
  : NT_Statement("Menu body", node_loc),
  	has_default(false)
{
	add_child(menu_case);
}

void MenuBody::add_case(MenuCase* menu_case)
{
	add_child_first(menu_case);
}

MenuDef& MenuBody::get_default_case()
{
	if(!contains_default())
		throw NoSuchChildException("this menu body contains no default case child");
	return *dynamic_cast<MenuDef*>(children.back());
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

void MenuBody::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* MenuCase */
MenuCase::MenuCase(Scope* scope, Expression* expr) : NT_Statement("Case") 
{
	add_child(scope);
	add_child(expr);
}

MenuCase::MenuCase(Scope* scope, Expression* expr, int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Case", first_line, last_line, first_column, last_column)
{
	add_child(scope);
	add_child(expr);
}

MenuCase::MenuCase(Scope* scope, Expression* expr, const NodeLocation& node_loc) : NT_Statement("Case", node_loc)
{
	add_child(scope);
	add_child(expr);
}

Scope& MenuCase::get_scope()
{
	return *dynamic_cast<Scope*>(children[0]);
}

Expression& MenuCase::get_expression()
{
	return *dynamic_cast<Expression*>(children[1]);
}


void MenuCase::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* MenuDef */
MenuDef::MenuDef(Scope* scope) : NT_Statement("Default case") 
{ 
	add_child(scope);
}

MenuDef::MenuDef(Scope* scope, int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Default case", first_line, last_line, first_column, last_column)
{
	add_child(scope);
}

MenuDef::MenuDef(Scope* scope, const NodeLocation& node_loc) : NT_Statement("Default case", node_loc)
{
	add_child(scope);
}


Scope& MenuDef::get_scope()
{
	return *dynamic_cast<Scope*>(children[0]);
}


void MenuDef::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* Roll */
Roll::Roll(Expression* expr, Scope* scope) : NT_Statement("Roll") 
{ 
	add_child(expr);
	add_child(scope);
}

Roll::Roll(Expression* expr, Scope* scope, int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Roll", first_line, last_line, first_column, last_column)
{
	add_child(expr);
	add_child(scope);
}

Roll::Roll(Expression* expr, Scope* scope, const NodeLocation& node_loc) : NT_Statement("Roll", node_loc)
{
	add_child(expr);
	add_child(scope);
}

Scope& Roll::get_scope()
{
	return *dynamic_cast<Scope*>(children[1]);
}

Expression& Roll::get_expression()
{
	return *dynamic_cast<Expression*>(children[0]);
}

void Roll::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* Foreach */
Foreach::Foreach(Expression* expr, Identifier* id, Scope* scope) : NT_Statement("Foreach") 
{
	add_child(expr);
	add_child(id);
	add_child(scope);
}

Foreach::Foreach(Expression* expr, Identifier* id, Scope* scope, int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("Foreach", first_line, last_line, first_column, last_column)
{
	add_child(expr);
	add_child(id);
	add_child(scope);
}

Foreach::Foreach(Expression* expr, Identifier* id, Scope* scope, const NodeLocation& node_loc) : NT_Statement("Foreach", node_loc)
{
	add_child(expr);
	add_child(id);
	add_child(scope);
}

Expression& Foreach::get_expression()
{
	return *dynamic_cast<Expression*>(children[0]);
}

Identifier& Foreach::get_identifier()
{
	return *dynamic_cast<Identifier*>(children[1]);
}

Scope& Foreach::get_scope()
{
	return *dynamic_cast<Scope*>(children[2]);
}
		
void Foreach::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* For */
For::For(ForInitializer* init, Expression* expr, ForUpdate* update, Scope* scope) 
  : NT_Statement("For"),
  	has_initializer(init != nullptr),
  	has_update(update != nullptr)
{ 
	if(init)
		add_child(init);
	
	add_child(expr);
	
	if(update)
		add_child(update);
	
	add_child(scope);
}

For::For(ForInitializer* init, Expression* expr, ForUpdate* update, Scope* scope, int first_line, int last_line, int first_column, int last_column)
  : NT_Statement("For", first_line, last_line, first_column, last_column),
  	has_initializer(init != nullptr),
  	has_update(update != nullptr)
{
	if(init)
		add_child(init);
	
	add_child(expr);
	
	if(update)
		add_child(update);
	
	add_child(scope);
}

For::For(ForInitializer* init, Expression* expr, ForUpdate* update, Scope* scope, const NodeLocation& node_loc) 
  : NT_Statement("For", node_loc),
  	has_initializer(init != nullptr),
  	has_update(update != nullptr)
{
	if(init)
		add_child(init);
	
	add_child(expr);
	
	if(update)
		add_child(update);
	
	add_child(scope);
}

void For::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

ForInitializer& For::get_initializer()
{
	if(empty_initializer())
		throw NoSuchChildException("empty for initializer section");
	return *dynamic_cast<ForInitializer*>(children[0]);
}

Expression& For::get_expression()
{
	if(empty_initializer())
		return *dynamic_cast<Expression*>(children[0]);
	else
		return *dynamic_cast<Expression*>(children[1]);
}

ForUpdate& For::get_update()
{
	if(empty_update())
		throw NoSuchChildException("empty for initializer section");

	if(empty_initializer())
		return *dynamic_cast<ForUpdate*>(children[1]);
	else
		return *dynamic_cast<ForUpdate*>(children[2]);
}

Scope& For::get_scope()
{
	if(empty_initializer() && empty_update())
		return *dynamic_cast<Scope*>(children[1]);
	else if(empty_initializer() || empty_update())
		return *dynamic_cast<Scope*>(children[2]);
	else
		return *dynamic_cast<Scope*>(children[3]);
}

/* ForInitializer */
ForInitializer::ForInitializer(ASTNode* expr) : NT_Statement("For initializer") 
{
	add_child(expr);
}

ForInitializer::ForInitializer(ASTNode* expr, int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("For initializer", first_line, last_line, first_column, last_column)
{
	add_child(expr);
}

ForInitializer::ForInitializer(ASTNode* expr, const NodeLocation& node_loc) : NT_Statement("For initializer", node_loc)
{
	add_child(expr);
}

ASTNode& ForInitializer::get_expression()
{
	return *children[0];
}

void ForInitializer::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}


/* ForUpdate */
ForUpdate::ForUpdate(ASTNode* expr) : NT_Statement("For update") 
{ 
	add_child(expr);
}

ForUpdate::ForUpdate(ASTNode* expr, int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("For update", first_line, last_line, first_column, last_column)
{
	add_child(expr);
}

ForUpdate::ForUpdate(ASTNode* expr, const NodeLocation& node_loc) : NT_Statement("For update", node_loc)
{
	add_child(expr);
}

ASTNode& ForUpdate::get_expression()
{
	return *children[0];
}

void ForUpdate::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* Conditional */
Conditional::Conditional(If* if_node, const std::list<Elseif*>& elseifs, Else* else_node)
  : NT_Statement("Conditional"),
	has_else(else_node != nullptr)
{ 
	add_child(if_node);

	for(auto elseif : elseifs)
		add_child(elseif);
	
	if(else_node)
		add_child(else_node);
}

Conditional::Conditional(If* if_node, const std::list<Elseif*>& elseifs, Else* else_node,
							int first_line, int last_line, int first_column, int last_column)
  : NT_Statement("Conditional", first_line, last_line, first_column, last_column),
  	has_else(else_node != nullptr)
{
	add_child(if_node);

	for(auto elseif : elseifs)
		add_child(elseif);

	if(else_node)
		add_child(else_node);
}

Conditional::Conditional(If* if_node, const std::list<Elseif*>& elseifs, Else* else_node,
							const NodeLocation& node_loc) 
  : NT_Statement("Conditional", node_loc),
  	has_else(else_node != nullptr)
{
	add_child(if_node);
	
	for(auto elseif : elseifs)
		add_child(elseif);

	if(else_node)
		add_child(else_node);
}

size_t Conditional::count_elseif() const
{
	return contains_else() ? children.size() - 2 : children.size() - 1;
}

Elseif& Conditional::get_nth_elseif(size_t n)
{
	if(n >= count_elseif())
		throw NoSuchChildException("the given index does not refer to an elseif node");
	return *dynamic_cast<Elseif*>(children[n + 1]);
}

If& Conditional::get_if()
{
	return *dynamic_cast<If*>(children[0]);
}

Else& Conditional::get_else()
{
	if(!contains_else())
		throw NoSuchChildException("this conditional node has no else child node");
	return *dynamic_cast<Else*>(children.back());
}

void Conditional::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* If */
If::If(Expression* expr, Scope* scope) 
  : NT_Statement("If") 
{ 
	add_child(expr);
	add_child(scope);
}

If::If(Expression* expr, Scope* scope, int first_line, int last_line, int first_column, int last_column)
	: NT_Statement("If", first_line, last_line, first_column, last_column)
{
	add_child(expr);
	add_child(scope);
}

If::If(Expression* expr, Scope* scope, const NodeLocation& node_loc) 
  : NT_Statement("If", node_loc)
{
	add_child(expr);
	add_child(scope);
}

void If::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
} 

Scope& If::get_scope()
{
	return *dynamic_cast<Scope*>(children[1]);
}

Expression& If::get_expression()
{
	return *dynamic_cast<Expression*>(children[0]);
}

/* Elseif */
Elseif::Elseif(Expression* expr, Scope* scope) 
  : NT_Statement("Elseif") 
{ 
	add_child(expr);
	add_child(scope);
}

Elseif::Elseif(Expression* expr, Scope* scope, int first_line, int last_line, int first_column, int last_column)
  : NT_Statement("Elseif", first_line, last_line, first_column, last_column)
{
	add_child(expr);
	add_child(scope);
}

Elseif::Elseif(Expression* expr, Scope* scope, const NodeLocation& node_loc) 
  : NT_Statement("Elseif", node_loc)
{
	add_child(expr);
	add_child(scope);
}

void Elseif::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

Scope& Elseif::get_scope()
{
	return *dynamic_cast<Scope*>(children[1]);
}

Expression& Elseif::get_expression()
{
	return *dynamic_cast<Expression*>(children[0]);
}

/** Else */
Else::Else(Scope* scope) 
  : NT_Statement("Else") 
{ 
	add_child(scope);
}

Else::Else(Scope* scope, int first_line, int last_line, int first_column, int last_column)
  : NT_Statement("Else", first_line, last_line, first_column, last_column)
{
	add_child(scope);
}

Else::Else(Scope* scope, const NodeLocation& node_loc) 
  : NT_Statement("Else", node_loc)
{
	add_child(scope);
}

Scope& Else::get_scope()
{
	return *dynamic_cast<Scope*>(children[0]);
}

void Else::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}
