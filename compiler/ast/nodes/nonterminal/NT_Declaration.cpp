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
Declaration::Declaration() : NT_Declaration("Declaration") { }

Declaration::Declaration(int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Declaration", first_line, last_line, first_column, last_column)
{

}

Declaration::Declaration(const NodeLocation& node_loc) : NT_Declaration("Declaration", node_loc)
{

}

void Declaration::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* DeclFunc */
DeclFunc::DeclFunc() : NT_Declaration("Function declaration") { }

DeclFunc::DeclFunc(int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Function declaration", first_line, last_line, first_column, last_column)
{

}

DeclFunc::DeclFunc(const NodeLocation& node_loc) : NT_Declaration("Function declaration", node_loc)
{

}

void DeclFunc::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}


/* DeclVars */
DeclVars::DeclVars() : NT_Declaration("Variables declaration") { }

DeclVars::DeclVars(int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Variables declaration", first_line, last_line, first_column, last_column)
{

}

DeclVars::DeclVars(const NodeLocation& node_loc) : NT_Declaration("Variables declaration", node_loc)
{

}

void DeclVars::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}


/* DeclVar */
DeclVar::DeclVar() : NT_Declaration("Variable declaration") { }

DeclVar::DeclVar(int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Variable declaration", first_line, last_line, first_column, last_column)
{

}

DeclVar::DeclVar(const NodeLocation& node_loc) : NT_Declaration("Variable declaration", node_loc)
{

}

void DeclVar::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}


/* Param */
Param::Param() : NT_Declaration("Parameter") { }

Param::Param(int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Parameter", first_line, last_line, first_column, last_column)
{

}

Param::Param(const NodeLocation& node_loc) : NT_Declaration("Parameter", node_loc)
{

}

void Param::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}

/* ParamList */
ParamList::ParamList() : NT_Declaration("Parameter list") { }

ParamList::ParamList(int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Parameter list", first_line, last_line, first_column, last_column)
{

}

ParamList::ParamList(const NodeLocation& node_loc) : NT_Declaration("Parameter list", node_loc)
{

}

void ParamList::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	for(auto it = children.begin() ; it != children.end() ; ++it)
		(*it)->accept(visitor);
}
