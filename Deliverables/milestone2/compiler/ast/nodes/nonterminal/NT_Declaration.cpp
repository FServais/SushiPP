#include "NT_Declaration.hpp"
#include "../../visitor/ASTVisitor.hpp"

using namespace ast;
using namespace std;

/** Constant base class */
NT_Declaration::NT_Declaration(const string& node_name) : NonTerminal(node_name) {}

NT_Declaration::NT_Declaration(const string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Declaration::NT_Declaration(const string& node_name, const NodeLocation& node_loc)
	: NonTerminal(node_name, node_loc)
{

}

void NT_Declaration::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/** (NT_)Declaration derived classes **/
/* Declaration */
Declaration::Declaration() : NT_Declaration("declaration") { }

Declaration::Declaration(int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("declaration", first_line, last_line, first_column, last_column)
{

}

Declaration::Declaration(const NodeLocation& node_loc) : NT_Declaration("declaration", node_loc)
{

}

void Declaration::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* DeclFunc */
DeclFunc::DeclFunc() : NT_Declaration("declfunc") { }

DeclFunc::DeclFunc(int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("declfunc", first_line, last_line, first_column, last_column)
{

}

DeclFunc::DeclFunc(const NodeLocation& node_loc) : NT_Declaration("declfunc", node_loc)
{

}

void DeclFunc::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}


/* DeclVars */
DeclVars::DeclVars() : NT_Declaration("declvars") { }

DeclVars::DeclVars(int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("declvars", first_line, last_line, first_column, last_column)
{

}

DeclVars::DeclVars(const NodeLocation& node_loc) : NT_Declaration("declvars", node_loc)
{

}

void DeclVars::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}


/* DeclVar */
DeclVar::DeclVar() : NT_Declaration("declvar") { }

DeclVar::DeclVar(int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("declvar", first_line, last_line, first_column, last_column)
{

}

DeclVar::DeclVar(const NodeLocation& node_loc) : NT_Declaration("declvar", node_loc)
{

}

void DeclVar::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}


/* Param */
Param::Param() : NT_Declaration("param") { }

Param::Param(int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("param", first_line, last_line, first_column, last_column)
{

}

Param::Param(const NodeLocation& node_loc) : NT_Declaration("param", node_loc)
{

}

void Param::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* ParamList */
ParamList::ParamList() : NT_Declaration("param list") { }

ParamList::ParamList(int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("param list", first_line, last_line, first_column, last_column)
{

}

ParamList::ParamList(const NodeLocation& node_loc) : NT_Declaration("param list", node_loc)
{

}

void ParamList::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}
