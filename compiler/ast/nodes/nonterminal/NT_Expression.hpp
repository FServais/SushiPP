#ifndef NT_EXPRESSION_HPP_DEFINED
#define NT_EXPRESSION_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals::nt_expression
{
	/**********************************************
	 * Intermediate NT_Expression node base class *
	 **********************************************/
	class NT_Expression : public NonTerminal
	{
	public:
		// Constructors
		NT_Expression();
		NT_Expression(int,int,int,int);
		NT_Expression(const ast::nodes::NodeLocation&);
	};

	/************************************
	 * Expression rules node base class *
	 ************************************/
	class Expression : public NT_Expression
	{
	public:
		// Constructors
		Expression();
		Expression(int,int,int,int);
		Expression(const ast::nodes::NodeLocation&);
	};

	class IncrExpression : public NT_Expression
	{
	public:
		// Constructors
		IncrExpression();
		IncrExpression(int,int,int,int);
		IncrExpression(const ast::nodes::NodeLocation&);
	};

	class Assignment : public NT_Expression
	{
	public:
		// Constructors
		Assignment();
		Assignment(int,int,int,int);
		Assignment(const ast::nodes::NodeLocation&);
	};

	class ModifyingExpression : public NT_Expression
	{
	public:
		// Constructors
		ModifyingExpression();
		ModifyingExpression(int,int,int,int);
		ModifyingExpression(const ast::nodes::NodeLocation&);
	};

	class AssignableExpression : public NT_Expression
	{
	public:
		// Constructors
		AssignableExpression();
		AssignableExpression(int,int,int,int);
		AssignableExpression(const ast::nodes::NodeLocation&);
	};

	class DatastructureAccess : public NT_Expression
	{
	public:
		// Constructors
		DatastructureAccess();
		DatastructureAccess(int,int,int,int);
		DatastructureAccess(const ast::nodes::NodeLocation&);
	};
}

#endif
