#ifndef NT_EXPRESSION_HPP_DEFINED
#define NT_EXPRESSION_HPP_DEFINED

#include "NonTerminal.hpp"
#include "../tokens/Token.hpp"

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

		virtual void accept(visitor::ASTVisitor&);
	};

	/************************************
	 * Expression rules node base class *
	 ************************************/
	class Expression : public NT_Expression
	{
	public:
		// Constructors
		Expression(ASTNode*);
		Expression(ASTNode*,int,int,int,int);
		Expression(ASTNode*,const NodeLocation&);

		ASTNode& get_child();

		virtual void accept(visitor::ASTVisitor&);
	};

	class ModifyingExpression : public NT_Expression
	{
	public:
		// Constructors
		ModifyingExpression(ASTNode*);
		ModifyingExpression(ASTNode*,int,int,int,int);
		ModifyingExpression(ASTNode*,const NodeLocation&);

		ASTNode& get_child();

		virtual void accept(visitor::ASTVisitor&);
	};

	class DatastructureAccess : public NT_Expression
	{
	public:
		// Constructors
		// name of the datastructure, index
		DatastructureAccess(Identifier*,Expression*);
		DatastructureAccess(Identifier*,Expression*,int,int,int,int);
		DatastructureAccess(Identifier*,Expression*,const NodeLocation&);

		Identifier& get_id();
		Expression& get_index();

		virtual void accept(visitor::ASTVisitor&);
	};

	class ExpressionList : public NT_Expression
	{
	public:
		// Constructors
		ExpressionList(Expression*);
		ExpressionList(Expression*,int,int,int,int);
		ExpressionList(Expression*,const NodeLocation&);

		/** 
		 * @brief Adds an expression to the case list (insert it as the first one)
		 * @param Expression* expression The expression to add
		 */
		void add_expression(Expression*);

		/**
		 * @brief Return the nth_expression of the expression list
		 * @oaram size_t n The parameter index
		 */
		Expression& get_nth_expression(size_t);
		const Expression& get_nth_expression(size_t) const;

		size_t nb_expressions() const { return children.size(); }; 

		virtual void accept(visitor::ASTVisitor&);
	};
}

#endif

