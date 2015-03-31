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
		NT_Expression(const std::string&);
		NT_Expression(const std::string&,int,int,int,int);
		NT_Expression(const std::string&,const ast::nodes::NodeLocation&);
	};

	/************************************
	 * Expression rules node base class *
	 ************************************/
	class Expression : public NT_Expression
	{
	public:
		// Constructors
		Expression(const std::string&);
		Expression(const std::string&,int,int,int,int);
		Expression(const std::string&,const ast::nodes::NodeLocation&);
	};

	class IncrExpression : public NT_Expression
	{
	public:
		// Constructors
		IncrExpression(const std::string&);
		IncrExpression(const std::string&,int,int,int,int);
		IncrExpression(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Assignment : public NT_Expression
	{
	public:
		// Constructors
		Assignment(const std::string&);
		Assignment(const std::string&,int,int,int,int);
		Assignment(const std::string&,const ast::nodes::NodeLocation&);
	};

	class ModifyingExpression : public NT_Expression
	{
	public:
		// Constructors
		ModifyingExpression(const std::string&);
		ModifyingExpression(const std::string&,int,int,int,int);
		ModifyingExpression(const std::string&,const ast::nodes::NodeLocation&);
	};

	class AssignableExpression : public NT_Expression
	{
	public:
		// Constructors
		AssignableExpression(const std::string&);
		AssignableExpression(const std::string&,int,int,int,int);
		AssignableExpression(const std::string&,const ast::nodes::NodeLocation&);
	};

	class DatastructureAccess : public NT_Expression
	{
	public:
		// Constructors
		DatastructureAccess(const std::string&);
		DatastructureAccess(const std::string&,int,int,int,int);
		DatastructureAccess(const std::string&,const ast::nodes::NodeLocation&);
	};
}

#endif
