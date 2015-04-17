#include "NT_Declaration.hpp"
#include "../tokens/Token.hpp"
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
}

const std::string& Param::get_param_name() const
{
	Identifier* identifier = dynamic_cast<Identifier*>(children[0]);
	return identifier->id();
}

bool Param::has_type() const
{
	return children.size() == 2;
}

symb::Type Param::get_type() const
{
	Type* type_node = dynamic_cast<Type*>(children[1]);
	return type_node->get_type();
}

