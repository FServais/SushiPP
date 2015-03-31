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
	};

	class IncrExpression : public NT_Expression
	{
	public:
		// Constructors
		IncrExpression();
		IncrExpression(int,int,int,int);
		IncrExpression(const NodeLocation&);
	};

	class Assignment : public NT_Expression
	{
	public:
		// Constructors
		Assignment();
		Assignment(int,int,int,int);
		Assignment(const NodeLocation&);
	};

	class ModifyingExpression : public NT_Expression
	{
	public:
		// Constructors
		ModifyingExpression();
		ModifyingExpression(int,int,int,int);
		ModifyingExpression(const NodeLocation&);
	};

	class AssignableExpression : public NT_Expression
	{
	public:
		// Constructors
		AssignableExpression();
		AssignableExpression(int,int,int,int);
		AssignableExpression(const NodeLocation&);
	};

	class DatastructureAccess : public NT_Expression
	{
	public:
		// Constructors
		DatastructureAccess();
		DatastructureAccess(int,int,int,int);
		DatastructureAccess(const NodeLocation&);
	};
}

#endif
