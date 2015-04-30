#include "NT_Expression.hpp"
#include "../../visitor/ASTVisitor.hpp"
#include "../../../exceptions/Exceptions.hpp"

using namespace ast;

/** Constant base class */
NT_Expression::NT_Expression(const std::string& node_name) : NonTerminal(node_name) {}

NT_Expression::NT_Expression(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: NonTerminal(node_name, first_line, last_line, first_column, last_column)
{

}

NT_Expression::NT_Expression(const std::string& node_name, const NodeLocation& node_loc)
	: NonTerminal(node_name, node_loc)
{

}

void NT_Expression::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/** (NT_)Expression derived classes **/

/* Expression */
Expression::Expression(ASTNode* child) : NT_Expression("Expression")
{
	add_child(child);
}

Expression::Expression(ASTNode* child, int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("Expression", first_line, last_line, first_column, last_column)
{
	add_child(child);
}

Expression::Expression(ASTNode* child, const NodeLocation& node_loc) : NT_Expression("Expression", node_loc)
{
	add_child(child);
}

ASTNode& Expression::get_child()
{
	return *children[0];
}

void Expression::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* ModifyingExpression */
ModifyingExpression::ModifyingExpression(ASTNode* child) : NT_Expression("Modifying expression")
{
	add_child(child);
}

ModifyingExpression::ModifyingExpression(ASTNode* child, int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("Modifying expression", first_line, last_line, first_column, last_column)
{
	add_child(child);
}

ModifyingExpression::ModifyingExpression(ASTNode* child, const NodeLocation& node_loc) : NT_Expression("Modifying expression", node_loc)
{
	add_child(child);
}

ASTNode& ModifyingExpression::get_child()
{
	return *children[0];
}

void ModifyingExpression::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* DatastructureAccess */
DatastructureAccess::DatastructureAccess(Identifier* id, Expression* index) : NT_Expression("Datastructure access")
{
	add_child(id);
	add_child(index);
}

DatastructureAccess::DatastructureAccess(Identifier* id, Expression* index, int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("Datastructure access", first_line, last_line, first_column, last_column)
{
	add_child(id);
	add_child(index);
}

DatastructureAccess::DatastructureAccess(Identifier* id, Expression* index, const NodeLocation& node_loc) : NT_Expression("Datastructure access", node_loc)
{
	add_child(id);
	add_child(index);
}

Identifier& DatastructureAccess::get_id()
{
	return *dynamic_cast<Identifier*>(children[0]);
}

Expression& DatastructureAccess::get_index()
{
	return *dynamic_cast<Expression*>(children[1]);
}

void DatastructureAccess::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* ExpressionList */
ExpressionList::ExpressionList(Expression* exp) : NT_Expression("Expression list")
{
	add_child(exp);
}

ExpressionList::ExpressionList(Expression* exp, int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("Expression list", first_line, last_line, first_column, last_column)
{
	add_child(exp);
}

ExpressionList::ExpressionList(Expression* exp, const NodeLocation& node_loc) : NT_Expression("Expression list", node_loc)
{
	add_child(exp);
}

void ExpressionList::add_expression(Expression* expression)
{
	add_child_first(expression);
}

void ExpressionList::accept(visitor::ASTVisitor& visitor)
{
	visitor.visit(*this);

}

Expression& ExpressionList::get_nth_expression(size_t n)
{
	if(nb_expressions() <= n)
		throw except::NoSuchChildException("there is any " + std::to_string(n + 1) + "th child (only " + std::to_string(nb_expressions()) + ")");

	return *dynamic_cast<Expression*>(children[n]);
}

const Expression& ExpressionList::get_nth_expression(size_t n) const
{
	if(nb_expressions() <= n)
		throw except::NoSuchChildException("there is any " + std::to_string(n + 1) + "th child (only " + std::to_string(nb_expressions()) + ")");

	return *dynamic_cast<Expression*>(children[n]);
}

