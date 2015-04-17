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
FuncCall::FuncCall() : NT_FunctionCall("Function call") { }

FuncCall::FuncCall(int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("Function call", first_line, last_line, first_column, last_column)
{

}

FuncCall::FuncCall(const NodeLocation& node_loc) : NT_FunctionCall("Function call", node_loc)
{

}

void FuncCall::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}


/* ArgList */
ArgList::ArgList() : NT_FunctionCall("Argument list") { }

ArgList::ArgList(int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("Argument list", first_line, last_line, first_column, last_column)
{

}

ArgList::ArgList(const NodeLocation& node_loc) : NT_FunctionCall("Argument list", node_loc)
{

}

void ArgList::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}



/* Argument */
Argument::Argument() : NT_FunctionCall("Argument") { }

Argument::Argument(int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("Argument", first_line, last_line, first_column, last_column)
{

}

Argument::Argument(const NodeLocation& node_loc) : NT_FunctionCall("Argument", node_loc)
{

}

void Argument::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* SoyFunc */
SoyFunc::SoyFunc() : NT_FunctionCall("Soy function") { }

SoyFunc::SoyFunc(int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("Soy function", first_line, last_line, first_column, last_column)
{

}

SoyFunc::SoyFunc(const NodeLocation& node_loc) : NT_FunctionCall("Soy function", node_loc)
{

}


void SoyFunc::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}
