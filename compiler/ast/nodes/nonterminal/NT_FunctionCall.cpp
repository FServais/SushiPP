#include "NT_FunctionCall.hpp"
#include "../../visitor/ASTVisitor.hpp"

using namespace ast;

/** Constant base class */
NT_FunctionCall::NT_FunctionCall(const std::string& node_name) : NonTerminal(node_name) {}

NT_FunctionCall::NT_FunctionCall(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_FunctionCall::NT_FunctionCall(const std::string& node_name, const NodeLocation& node_loc)
	: NonTerminal(node_name, node_loc)
{

}

void NT_FunctionCall::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}


/** (NT_)FunctionCall derived classes **/

/* FuncCall */
FuncCall::FuncCall(ast::Identifier* id, ast::ArgList* arg_list) : NT_FunctionCall("Function call")
{
	add_child(id);
	add_child(arg_list);
}

FuncCall::FuncCall(ast::Identifier* id, ast::ArgList* arg_list, int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("Function call", first_line, last_line, first_column, last_column)
{
	add_child(id);
	add_child(arg_list);
}

FuncCall::FuncCall(ast::Identifier* id, ast::ArgList* arg_list, const NodeLocation& node_loc) : NT_FunctionCall("Function call", node_loc)
{
	add_child(id);
	add_child(arg_list);
}

void FuncCall::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

ast::Identifier& FuncCall::get_id()
{
	return *dynamic_cast<Identifier*>(children[0];
}
ast::ArgList& FuncCall::get_arg_list()
{
	return *dynamic_cast<ArgList*>(children[1]);
}

/* ArgList */
ArgList::ArgList(ast::Argument* arg) : NT_FunctionCall("Argument list") 
{
	add_child(arg);
}

ArgList::ArgList(ast::Argument* arg, int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("Argument list", first_line, last_line, first_column, last_column)
{
	add_child(arg);
}

ArgList::ArgList(ast::Argument* arg, const NodeLocation& node_loc) : NT_FunctionCall("Argument list", node_loc)
{
	add_child(arg);
}

void ArgList::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

void ArgList::add_argument(ast::Argument* arg)
{
	add_child(arg);
}

ast::Argument& ArgList::get_arg(size_t index)
{
	if(index >= nb_cases())
		throw NoSuchChildException("the given index does not refers to an existing case");
	return *dynamic_cast<Argument*>(children[index]);
}


/* Argument */
Argument::Argument(ast::ASTNode* arg) : NT_FunctionCall("Argument") 
{
	add_child(arg);
}

Argument::Argument(ast::ASTNode* arg, int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("Argument", first_line, last_line, first_column, last_column)
{
	add_child(arg);
}

Argument::Argument(ast::ASTNode* arg, const NodeLocation& node_loc) : NT_FunctionCall("Argument", node_loc)
{
	add_child(arg);
}

void Argument::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

ast::ASTNode& Argument::get_child()
{
	return *children[0];
}


/* SoyFunc */
SoyFunc::SoyFunc(ast::ArgList* arg_list, ast::Scope* scope) : NT_FunctionCall("Soy function") 
{
	add_child(arg_list);
	add_child(scope);
}

SoyFunc::SoyFunc(ast::ArgList* arg_list, ast::Scope* scope,int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("Soy function", first_line, last_line, first_column, last_column)
{
	add_child(arg_list);
	add_child(scope);
}

SoyFunc::SoyFunc(ast::ArgList* arg_list, ast::Scope* scope, const NodeLocation& node_loc) : NT_FunctionCall("Soy function", node_loc)
{
	add_child(arg_list);
	add_child(scope);
}


void SoyFunc::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

ast::ArgList& SoyFunc::get_arg_list()
{
	return *dynamic_cast<ArgList*>(children[0]);
}
ast::Scope& SoyFunc::get_scope()
{
	return *dynamic_cast<Scope*>(children[1]);
}
