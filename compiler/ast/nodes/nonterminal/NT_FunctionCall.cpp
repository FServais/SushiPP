#include "NT_FunctionCall.hpp"
#include "../../visitor/ASTVisitor.hpp"
#include "../../../exceptions/Exceptions.hpp"

using namespace ast;
using namespace except;
using namespace std; 

/** Constant base class */
NT_FunctionCall::NT_FunctionCall(const string& node_name) : NonTerminal(node_name) {}

NT_FunctionCall::NT_FunctionCall(const string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_FunctionCall::NT_FunctionCall(const string& node_name, const NodeLocation& node_loc)
	: NonTerminal(node_name, node_loc)
{

}

void NT_FunctionCall::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}


/** (NT_)FunctionCall derived classes **/

/* FuncCall */
FuncCall::FuncCall(ASTNode* id, ArgList* arg_list) 
  : NT_FunctionCall("Function call"),
  	has_arglist(arg_list != nullptr)
{
	add_child(id);
	if(arg_list)
		add_child(arg_list);
}

FuncCall::FuncCall(ASTNode* id, ArgList* arg_list, int first_line, int last_line, int first_column, int last_column)
  : NT_FunctionCall("Function call", first_line, last_line, first_column, last_column),
  	has_arglist(arg_list != nullptr)
{
	add_child(id);
	if(arg_list)
		add_child(arg_list);
}

FuncCall::FuncCall(ASTNode* id, ArgList* arg_list, const NodeLocation& node_loc) 
  : NT_FunctionCall("Function call", node_loc),
  	has_arglist(arg_list != nullptr)
{
	add_child(id);
	if(arg_list)
		add_child(arg_list);
}

void FuncCall::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

ASTNode& FuncCall::get_function()
{
	return *children[0];
}

ArgList& FuncCall::get_arg_list()
{
	if(!contains_arglist())
		throw NoSuchChildException("this function call has no argument list");
	return *dynamic_cast<ArgList*>(children[1]);
}

std::string& FuncCall::get_function_name()
{
	if(Identifier* v = dynamic_cast<Identifier*>(children[0]))
		return v->id();

	else
		return dynamic_cast<SoyFunc*>(children[0])->get_name();

}

/* ArgList */
ArgList::ArgList(Argument* arg) : NT_FunctionCall("Argument list") 
{
	add_child(arg);
}

ArgList::ArgList(Argument* arg, int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("Argument list", first_line, last_line, first_column, last_column)
{
	add_child(arg);
}

ArgList::ArgList(Argument* arg, const NodeLocation& node_loc) : NT_FunctionCall("Argument list", node_loc)
{
	add_child(arg);
}

void ArgList::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

void ArgList::add_argument(Argument* arg)
{
	add_child_first(arg);
}

size_t ArgList::nb_args() const
{
	return children.size();
}

Argument& ArgList::get_arg(size_t index)
{
	if(index >= nb_args())
		throw NoSuchChildException("the given index does not refers to an existing case");
	return *dynamic_cast<Argument*>(children[index]);
}

/* Argument */
Argument::Argument(ASTNode* arg) : NT_FunctionCall("Argument") 
{
	add_child(arg);
}

Argument::Argument(ASTNode* arg, int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("Argument", first_line, last_line, first_column, last_column)
{
	add_child(arg);
}

Argument::Argument(ASTNode* arg, const NodeLocation& node_loc) : NT_FunctionCall("Argument", node_loc)
{
	add_child(arg);
}

void Argument::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

ASTNode& Argument::get_child()
{
	return *children[0];
}
