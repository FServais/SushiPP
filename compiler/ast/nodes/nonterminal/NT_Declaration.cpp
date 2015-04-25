#include "NT_Declaration.hpp"
#include "../tokens/Token.hpp"
#include "../../visitor/ASTVisitor.hpp"
#include "../../../exceptions/Exceptions.hpp"

using namespace ast;
using namespace std;
using namespace except;

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

void NT_Declaration::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* DeclFunc */
DeclFunc::DeclFunc(Identifier* id, ParamList* param_list, Scope* scope) : NT_Declaration("Function declaration") 
{
	add_child(id);
	if(param_list)
		add_child(param_list);
	add_child(scope);
}

DeclFunc::DeclFunc(Identifier* id, ParamList* param_list, Scope* scope, int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Function declaration", first_line, last_line, first_column, last_column)
{
	add_child(id);
	if(param_list)
		add_child(param_list);
	add_child(scope);
}

DeclFunc::DeclFunc(Identifier* id, ParamList* param_list, Scope* scope, const NodeLocation& node_loc) : NT_Declaration("Function declaration", node_loc)
{
	add_child(id);
	if(param_list)
		add_child(param_list);
	add_child(scope);
}

void DeclFunc::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

Identifier& DeclFunc::get_id()
{
	return *dynamic_cast<Identifier*>(children[0]);
}

ParamList& DeclFunc::get_param_list()
{
	if(!contains_params())
		throw NoSuchChildException("the declared function has no parameters");
	return *dynamic_cast<ParamList*>(children[1]);	
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

void DeclVars::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

DeclVar& DeclVars::get_variable(size_t n)
{
	if(n >= nb_variables())
		throw NoSuchChildException("the given index does not refers to an existing variable");
	return *dynamic_cast<DeclVar*>(children[n]);
}

void DeclVars::add_variable(DeclVar* dvar)
{
	add_child_first(dvar);
}

size_t DeclVars::nb_variables() const
{
	return children.size();
} 

/* DeclVar */
DeclVar::DeclVar(Identifier* id) 
  : NT_Declaration("Variable declaration"),
  	has_expression(false)
{
	add_child(id);
}

DeclVar::DeclVar(Identifier* id, int first_line, int last_line, int first_column, int last_column)
  : NT_Declaration("Variable declaration", first_line, last_line, first_column, last_column),
  	has_expression(false)
{
	add_child(id);
}

DeclVar::DeclVar(Identifier* id, const NodeLocation& node_loc) 
  : NT_Declaration("Variable declaration", node_loc),
  	has_expression(false)
{
	add_child(id);
}

DeclVar::DeclVar(Identifier* id, Expression* expr) 
  : NT_Declaration("Variable declaration"),
  	has_expression(expr != nullptr)
{
	add_child(id);
	add_child(expr);
}

DeclVar::DeclVar(Identifier* id,  Expression* expr, int first_line, int last_line, int first_column, int last_column)
  : NT_Declaration("Variable declaration", first_line, last_line, first_column, last_column),
  	has_expression(expr != nullptr)
{
	add_child(id);
	add_child(expr);
}

DeclVar::DeclVar(Identifier* id,  Expression* expr, const NodeLocation& node_loc) 
  : NT_Declaration("Variable declaration", node_loc),
  	has_expression(expr != nullptr)
{
	add_child(id);
	add_child(expr);
}

void DeclVar::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

Identifier& DeclVar::get_identifier()
{
	return *dynamic_cast<Identifier*>(children[0]);
}

Expression& DeclVar::get_expression()
{
	if(!contains_expr())
		throw NoSuchChildException(" there is no expression assigned to this variable declaration !");
	return *dynamic_cast<Expression*>(children[1]);
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

Param::Param(Identifier* id, Type* type) : NT_Declaration("Parameter")
{
	add_child(id);
	add_child(type);
}

Param::Param(Identifier* id, Type* type, int first_line, int last_line, int first_column, int last_column)
	: NT_Declaration("Parameter", first_line, last_line, first_column, last_column)
{
	add_child(id);
	add_child(type);

}

Param::Param(Identifier* id, Type* type,  const NodeLocation& node_loc) : NT_Declaration("Parameter", node_loc)
{
	add_child(id);
	add_child(type);
}

void Param::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

bool Param::has_type() const
{
	return children.size() == 2;
}

symb::Type Param::get_type() const
{
	return get_type_node().get_type();
}

Identifier& Param::get_identifier()
{
	return *dynamic_cast<Identifier*>(children[0]);
}

const Identifier& Param::get_identifier() const
{
	return *dynamic_cast<Identifier*>(children[0]);
}

const Type& Param::get_type_node() const
{
	if(!has_type())
		throw NoSuchChildException(" this parameter has no specified type");
	return *dynamic_cast<Type*>(children[1]);
}

Type& Param::get_type_node()
{
	if(!has_type())
		throw NoSuchChildException(" this parameter has no specified type");
	return *dynamic_cast<Type*>(children[1]);
}

const std::string& Param::get_param_name() const
{
	return get_identifier().id();
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

void ParamList::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

void ParamList::add_param(Param* param)
{
	add_child(param);
}

size_t ParamList::nb_params() const
{
	return children.size();
}

Param& ParamList::get_param(size_t n)
{
	if(n >= nb_params())
		throw NoSuchChildException("the given index does not refers to an existing case");
	return *dynamic_cast<Param*>(children[n]);
}


/* SoyFunc */
SoyFunc::SoyFunc(ParamList* param_list, Scope* scope) 
  : NT_Declaration("Soy function"),
  	has_params(param_list != nullptr)
{
	if(param_list)
		add_child(param_list);
	add_child(scope);
}

SoyFunc::SoyFunc(ParamList* param_list, Scope* scope,int first_line, int last_line, int first_column, int last_column)
  : NT_Declaration("Soy function", first_line, last_line, first_column, last_column),
  	has_params(param_list != nullptr)
{
	if(param_list)
		add_child(param_list);
	add_child(scope);
}

SoyFunc::SoyFunc(ParamList* param_list, Scope* scope, const NodeLocation& node_loc) 
  : NT_Declaration("Soy function", node_loc),
  	has_params(param_list != nullptr)
{
	if(param_list)
		add_child(param_list);
	add_child(scope);
}

void SoyFunc::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

ParamList& SoyFunc::get_params()
{
	if(!contains_params())
		throw NoSuchChildException("this soy function has no argument");
	return *dynamic_cast<ParamList*>(children[0]);
}

Scope& SoyFunc::get_scope()
{
	return *dynamic_cast<Scope*>(children[1]);
}