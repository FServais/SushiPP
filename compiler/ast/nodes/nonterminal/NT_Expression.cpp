#include "NT_Expression.hpp"

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

/** (NT_)Expression derived classes **/

/* Expression */
Expression::Expression() : NT_Expression("expression") { }

Expression::Expression(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("expression", first_line, last_line, first_column, last_column)
{

}

Expression::Expression(const NodeLocation& node_loc) : NT_Expression("expression", node_loc)
{

}

/* IncrExpression */
IncrExpression::IncrExpression() : NT_Expression("increxpression") { }

IncrExpression::IncrExpression(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("increxpression", first_line, last_line, first_column, last_column)
{

}

IncrExpression::IncrExpression(const NodeLocation& node_loc) : NT_Expression("increxpression", node_loc)
{

}

/* Assignment */
Assignment::Assignment() : NT_Expression("assignment") { }

Assignment::Assignment(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("assignment", first_line, last_line, first_column, last_column)
{

}

Assignment::Assignment(const NodeLocation& node_loc) : NT_Expression("assignment", node_loc)
{

}

/* ModifyingExpression */
ModifyingExpression::ModifyingExpression() : NT_Expression("modifying expression") { }

ModifyingExpression::ModifyingExpression(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("modifying expression", first_line, last_line, first_column, last_column)
{

}

ModifyingExpression::ModifyingExpression(const NodeLocation& node_loc) : NT_Expression("modifyinge xpression", node_loc)
{

}

/* AssignableExpression */
AssignableExpression::AssignableExpression() : NT_Expression("assignable expression") { }

AssignableExpression::AssignableExpression(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("assignable expression", first_line, last_line, first_column, last_column)
{

}

AssignableExpression::AssignableExpression(const NodeLocation& node_loc) : NT_Expression("assignable expression", node_loc)
{

}

/* DatastructureAccess */
DatastructureAccess::DatastructureAccess() : NT_Expression("datastructure access") { }

DatastructureAccess::DatastructureAccess(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("datastructure access", first_line, last_line, first_column, last_column)
{

}

DatastructureAccess::DatastructureAccess(const NodeLocation& node_loc) : NT_Expression("datastructure access", node_loc)
{

}

/* ExpressionList */
ExpressionList::ExpressionList() : NT_Expression("expression list") { }

ExpressionList::ExpressionList(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("expression list", first_line, last_line, first_column, last_column)
{

}

ExpressionList::ExpressionList(const NodeLocation& node_loc) : NT_Expression("expression list", node_loc)
{

}