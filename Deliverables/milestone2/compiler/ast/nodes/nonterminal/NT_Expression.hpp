#ifndef NT_EXPRESSION_HPP_DEFINED
#define NT_EXPRESSION_HPP_DEFINED

#include "NonTerminal.hpp"

namespace ast
{
	/**********************************************
	 * Intermediate NT_Expression node base class *
	 **********************************************/
	class NT_Expression : public NonTerminal
	{
	public:
		// Constructors
		NT_Expression(const std::string&);
		NT_Expression(const std::string&,int,int,int,int);
		NT_Expression(const std::string&,const NodeLocation&);

		virtual void accept(ASTVisitor&);
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
		Expression(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class IncrExpression : public NT_Expression
	{
	public:
		// Constructors
		IncrExpression();
		IncrExpression(int,int,int,int);
		IncrExpression(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Assignment : public NT_Expression
	{
	public:
		// Constructors
		Assignment();
		Assignment(int,int,int,int);
		Assignment(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class ModifyingExpression : public NT_Expression
	{
	public:
		// Constructors
		ModifyingExpression();
		ModifyingExpression(int,int,int,int);
		ModifyingExpression(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class AssignableExpression : public NT_Expression
	{
	public:
		// Constructors
		AssignableExpression();
		AssignableExpression(int,int,int,int);
		AssignableExpression(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class DatastructureAccess : public NT_Expression
	{
	public:
		// Constructors
		DatastructureAccess();
		DatastructureAccess(int,int,int,int);
		DatastructureAccess(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class ExpressionList : public NT_Expression
	{
	public:
		// Constructors
		ExpressionList();
		ExpressionList(int,int,int,int);
		ExpressionList(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};
}

#endif
