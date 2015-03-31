#include "NT_FunctionCall.hpp"

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

/** (NT_)FunctionCall derived classes **/

/* FuncCall */
FuncCall::FuncCall() : NT_FunctionCall("funccall") { }

FuncCall::FuncCall(int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("funccall", first_line, last_line, first_column, last_column)
{

}

FuncCall::FuncCall(const NodeLocation& node_loc) : NT_FunctionCall("funccall", node_loc)
{

}

/* ArgList */
ArgList::ArgList() : NT_FunctionCall("arglist") { }

ArgList::ArgList(int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("arglist", first_line, last_line, first_column, last_column)
{

}

ArgList::ArgList(const NodeLocation& node_loc) : NT_FunctionCall("arglist", node_loc)
{

}


/* Argument */
Argument::Argument() : NT_FunctionCall("argument") { }

Argument::Argument(int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("argument", first_line, last_line, first_column, last_column)
{

}

Argument::Argument(const NodeLocation& node_loc) : NT_FunctionCall("argument", node_loc)
{

}

/* BracedFuncCall */
BracedFuncCall::BracedFuncCall() : NT_FunctionCall("bracedfunccall") { }

BracedFuncCall::BracedFuncCall(int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("bracedfunccall", first_line, last_line, first_column, last_column)
{

}

BracedFuncCall::BracedFuncCall(const NodeLocation& node_loc) : NT_FunctionCall("bracedfunccall", node_loc)
{

}

/* FuncCallEol */
FuncCallEol::FuncCallEol() : NT_FunctionCall("funccalleol") { }

FuncCallEol::FuncCallEol(int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("funccalleol", first_line, last_line, first_column, last_column)
{

}

FuncCallEol::FuncCallEol(const NodeLocation& node_loc) : NT_FunctionCall("funccalleol", node_loc)
{

}

/* ArgListEol */
ArgListEol::ArgListEol() : NT_FunctionCall("arglisteol") { }

ArgListEol::ArgListEol(int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("arglisteol", first_line, last_line, first_column, last_column)
{

}

ArgListEol::ArgListEol(const NodeLocation& node_loc) : NT_FunctionCall("arglisteol", node_loc)
{

}

/* SoyExpression */
SoyExpression::SoyExpression() : NT_FunctionCall("soyexpression") { }

SoyExpression::SoyExpression(int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("soyexpression", first_line, last_line, first_column, last_column)
{

}

SoyExpression::SoyExpression(const NodeLocation& node_loc) : NT_FunctionCall("soyexpression", node_loc)
{

}

/* SoyFunc */
SoyFunc::SoyFunc() : NT_FunctionCall("soyfunc") { }

SoyFunc::SoyFunc(int first_line, int last_line, int first_column, int last_column)
	: NT_FunctionCall("soyfunc", first_line, last_line, first_column, last_column)
{

}

SoyFunc::SoyFunc(const NodeLocation& node_loc) : NT_FunctionCall("soyfunc", node_loc)
{

}
