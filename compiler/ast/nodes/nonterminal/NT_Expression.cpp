#include "NT_Expression.hpp"
#include "../../visitor/ASTVisitor.hpp"

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

void NT_Expression::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/** (NT_)Expression derived classes **/

/* Expression */
Expression::Expression() : NT_Expression("Expression") { }

Expression::Expression(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("Expression", first_line, last_line, first_column, last_column)
{

}

Expression::Expression(const NodeLocation& node_loc) : NT_Expression("Expression", node_loc)
{

}

void Expression::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}


/* IncrExpression */
IncrExpression::IncrExpression() : NT_Expression("Incrementation expression") { }

IncrExpression::IncrExpression(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("Incrementation expression", first_line, last_line, first_column, last_column)
{

}

IncrExpression::IncrExpression(const NodeLocation& node_loc) : NT_Expression("Incrementation expression", node_loc)
{

}

void IncrExpression::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* Assignment */
Assignment::Assignment() : NT_Expression("Assignment") { }

Assignment::Assignment(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("Assignment", first_line, last_line, first_column, last_column)
{

}

Assignment::Assignment(const NodeLocation& node_loc) : NT_Expression("Assignment", node_loc)
{

}

void Assignment::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* ModifyingExpression */
ModifyingExpression::ModifyingExpression() : NT_Expression("Modifying expression") { }

ModifyingExpression::ModifyingExpression(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("Modifying expression", first_line, last_line, first_column, last_column)
{

}

ModifyingExpression::ModifyingExpression(const NodeLocation& node_loc) : NT_Expression("Modifying expression", node_loc)
{

}

void ModifyingExpression::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* AssignableExpression */
AssignableExpression::AssignableExpression() : NT_Expression("Assignable expression") { }

AssignableExpression::AssignableExpression(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("Assignable expression", first_line, last_line, first_column, last_column)
{

}

AssignableExpression::AssignableExpression(const NodeLocation& node_loc) : NT_Expression("Assignable expression", node_loc)
{

}

void AssignableExpression::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* DatastructureAccess */
DatastructureAccess::DatastructureAccess() : NT_Expression("Datastructure access") { }

DatastructureAccess::DatastructureAccess(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("Datastructure access", first_line, last_line, first_column, last_column)
{

}

DatastructureAccess::DatastructureAccess(const NodeLocation& node_loc) : NT_Expression("Datastructure access", node_loc)
{

}

void DatastructureAccess::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* ExpressionList */
ExpressionList::ExpressionList() : NT_Expression("Expression list") { }

ExpressionList::ExpressionList(int first_line, int last_line, int first_column, int last_column)
	: NT_Expression("Expression list", first_line, last_line, first_column, last_column)
{

}

ExpressionList::ExpressionList(const NodeLocation& node_loc) : NT_Expression("Expression list", node_loc)
{

}

void ExpressionList::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}
