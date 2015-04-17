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
DeclFunc::DeclFunc(Identifier* id, ParamList* param_list, Scope* scope) : NT_Declaration("Function declaration") 
{
	add_child(id);
	add_child(param_list);
	add_child(scope);

}

DeclFunc::DeclFunc(Identifier* id, ParamList* param_list, Scope* scope, int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Function declaration", first_line, last_line, first_column, last_column)
{
	add_child(id);
	add_child(param_list);
	add_child(scope);
}

DeclFunc::DeclFunc(Identifier* id, ParamList* param_list, Scope* scope, const NodeLocation& node_loc) : NT_Declaration("Function declaration", node_loc)
{
	add_child(id);
	add_child(param_list);
	add_child(scope);
}

void DeclFunc::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

Identifier& DeclFunc::get_id()
{
	return *dynamic_cast<Identifier*>(children[0]);
}

ArgList& DeclFunc::get_param_list()
{
	return *dynamic_cast<ArgList*>(children[1]);	
}

Scope& DeclFunc::get_scope()
{
	return *dynamic_cast<Scope*>(children[2]);
}

/* DeclVars */
DeclVars::DeclVars(DeclVar* dvar) : NT_Declaration("Variables declaration")
{
	add_child(dvar);
}

DeclVars::DeclVars(DeclVar* dvar, int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Variables declaration", first_line, last_line, first_column, last_column)
{
	add_child(dvar);
}

DeclVars::DeclVars(DeclVar* dvar, const NodeLocation& node_loc) : NT_Declaration("Variables declaration", node_loc)
{
	add_child(dvar);
}

void DeclVars::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

DeclVar& DeclVars::get_decl_var(size_t n)
{
	if(n >= nb_cases())
		throw NoSuchChildException("the given index does not refers to an existing case");
	return *dynamic_cast<DeclVar*>(children[n]);
}

void DeclVars::add_decl_var(DeclVar* dvar)
{
	add_child(dvar);
}

/* DeclVar */
DeclVar::DeclVar(Identifier* id) : NT_Declaration("Variable declaration")
{
	add_child(id);
}

DeclVar::DeclVar(Identifier* id, int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Variable declaration", first_line, last_line, first_column, last_column)
{
	add_child(id);
}

DeclVar::DeclVar(Identifier* id, const NodeLocation& node_loc) : NT_Declaration("Variable declaration", node_loc)
{
	add_child(id);
}

DeclVar::DeclVar(Identifier* id, ASTNode* expr) : NT_Declaration("Variable declaration")
{
	add_child(id);
	add_child(expr);
}

DeclVar::DeclVar(Identifier* id,  ASTNode* exp, int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Variable declaration", first_line, last_line, first_column, last_column)
{
	add_child(id);
	add_child(expr);

}

DeclVar::DeclVar(Identifier* id,  ASTNode* exp, const NodeLocation& node_loc) : NT_Declaration("Variable declaration", node_loc)
{
	add_child(id);
	add_child(expr);

}

void DeclVar::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

Identifier& DeclVar::get_id()
{
	return *dynamic_cast<Identifier*>(children[0]);
}

ASTNode& DeclVar::get_exp()
{
	if(nb_cases() == 1)
		throw NoSuchChildException(" there is no expression assigned to this variable declaration !");
	return *children[1];
}

/* Param */
Param::Param(Identifier* id) : NT_Declaration("Parameter")
{
	add_child(id);
}

Param::Param(Identifier* id, int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Parameter", first_line, last_line, first_column, last_column)
{
	add_child(id);
}

Param::Param(Identifier* id, const NodeLocation& node_loc) : NT_Declaration("Parameter", node_loc)
{
	add_child(id);
}

Param::Param(Identifier* id, ASTNode* type) : NT_Declaration("Parameter")
{
	add_child(id);
	add_child(type);
}

Param::Param(Identifier* id, ASTNode* type, int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Parameter", first_line, last_line, first_column, last_column)
{
	add_child(id);
	add_child(type);

}

Param::Param(Identifier* id, ASTNode* type,  const NodeLocation& node_loc) : NT_Declaration("Parameter", node_loc)
{
	add_child(id);
	add_child(type);

}

void Param::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
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

Identifier& Param::get_id()
{
	return *dynamic_cast<Identifier*>(children[0]);
}

const std::string& Param::get_param_name() const
{
	Identifier* identifier = dynamic_cast<Identifier*>(children[0]);
	return identifier->id();
}

/* ParamList */
ParamList::ParamList(Param* param) : NT_Declaration("Parameter list")
{
	add_child(param);
}

ParamList::ParamList(Param* param, int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Parameter list", first_line, last_line, first_column, last_column)
{
	add_child(param);
}

ParamList::ParamList(Param* param, const NodeLocation& node_loc) : NT_Declaration("Parameter list", node_loc)
{
	add_child(param);
}

void ParamList::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

void ParamList::add_param(Param* param)
{
	add_child(param);
}
Param& ParamList::get_param(size_t n)
{
	if(n >= nb_cases())
		throw NoSuchChildException("the given index does not refers to an existing case");
	return *dynamic_cast<Param*>(children[n]);
}


