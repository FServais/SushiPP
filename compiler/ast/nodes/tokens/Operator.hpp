#ifndef OPERATOR_HPP_DEFINED
#define OPERATOR_HPP_DEFINED

#include <string>
#include "Token.hpp"
#include "../NodeLocation.hpp"

namespace ast
{
	/** operator base class */
	class Operator : public Token
	{
	public:
		// constructors
		Operator(const std::string&);
		Operator(const std::string&,int,int,int,int);
		Operator(const std::string&,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class BinaryOperator : public Operator
	{
	public:
		// constructors
		// name, left operand, right operand
		BinaryOperator(const std::string&,ASTNode*,ASTNode*);
		// name, left operand, right operand, first line, last line, first col, last col
		BinaryOperator(const std::string&,ASTNode*,ASTNode*,int,int,int,int);
		// name, left operand, right operand, node location object
		BinaryOperator(const std::string&,ASTNode*,ASTNode*,const NodeLocation&);

		// get child node : operands expressions
		ASTNode& get_left_operand();
		ASTNode& get_right_operand();

	private:
	};

	class UnaryOperator : public Operator
	{
	public:
		// constructors
		// name, operand
		UnaryOperator(const std::string&,ASTNode*);
		// name, operand, first line, last line, first col, last col
		UnaryOperator(const std::string&,ASTNode*,int,int,int,int);
		// name, operand, node location object
		UnaryOperator(const std::string&,ASTNode*,const NodeLocation&);

		// get child node : operand expression
		ASTNode& get_operand();

	private:
	};

	/** operator derived class */
	class Op_Plus : public BinaryOperator
	{
	public:
		// constructors
		Op_Plus(ASTNode*,ASTNode*);
		Op_Plus(ASTNode*,ASTNode*,int,int,int,int);
		Op_Plus(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_Minus : public BinaryOperator
	{
	public:
		// constructors
		Op_Minus(ASTNode*,ASTNode*);
		Op_Minus(ASTNode*,ASTNode*,int,int,int,int);
		Op_Minus(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_Mult : public BinaryOperator
	{
	public:
		// constructors
		Op_Mult(ASTNode*,ASTNode*);
		Op_Mult(ASTNode*,ASTNode*,int,int,int,int);
		Op_Mult(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_Div : public BinaryOperator
	{
	public:
		// constructors
		Op_Div(ASTNode*,ASTNode*);
		Op_Div(ASTNode*,ASTNode*,int,int,int,int);
		Op_Div(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_Modulo : public BinaryOperator
	{
	public:
		// constructors
		Op_Modulo(ASTNode*,ASTNode*);
		Op_Modulo(ASTNode*,ASTNode*,int,int,int,int);
		Op_Modulo(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_Exponentiation : public BinaryOperator
	{
	public:
		// constructors
		Op_Exponentiation(ASTNode*,ASTNode*);
		Op_Exponentiation(ASTNode*,ASTNode*,int,int,int,int);
		Op_Exponentiation(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_UnaryMinus : public UnaryOperator
	{
	public:
		// constructors
		Op_UnaryMinus(ASTNode*);
		Op_UnaryMinus(ASTNode*,int,int,int,int);
		Op_UnaryMinus(ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_BitwiseOr : public BinaryOperator
	{
	public:
		// constructors
		Op_BitwiseOr(ASTNode*,ASTNode*);
		Op_BitwiseOr(ASTNode*,ASTNode*,int,int,int,int);
		Op_BitwiseOr(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_BitwiseAnd : public BinaryOperator
	{
	public:
		// constructors
		Op_BitwiseAnd(ASTNode*,ASTNode*);
		Op_BitwiseAnd(ASTNode*,ASTNode*,int,int,int,int);
		Op_BitwiseAnd(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_BitwiseXor : public BinaryOperator
	{
	public:
		// constructors
		Op_BitwiseXor(ASTNode*,ASTNode*);
		Op_BitwiseXor(ASTNode*,ASTNode*,int,int,int,int);
		Op_BitwiseXor(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_BitwiseNot : public UnaryOperator
	{
	public:
		// constructors
		Op_BitwiseNot(ASTNode*);
		Op_BitwiseNot(ASTNode*,int,int,int,int);
		Op_BitwiseNot(ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_LogicalOr : public BinaryOperator
	{
	public:
		// constructors
		Op_LogicalOr(ASTNode*,ASTNode*);
		Op_LogicalOr(ASTNode*,ASTNode*,int,int,int,int);
		Op_LogicalOr(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_LogicalAnd : public BinaryOperator
	{
	public:
		// constructors
		Op_LogicalAnd(ASTNode*,ASTNode*);
		Op_LogicalAnd(ASTNode*,ASTNode*,int,int,int,int);
		Op_LogicalAnd(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_LogicalNot : public UnaryOperator
	{
	public:
		// constructors
		Op_LogicalNot(ASTNode*);
		Op_LogicalNot(ASTNode*,int,int,int,int);
		Op_LogicalNot(ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_CompLessThan : public BinaryOperator
	{
	public:
		// constructors
		Op_CompLessThan(ASTNode*,ASTNode*);
		Op_CompLessThan(ASTNode*,ASTNode*,int,int,int,int);
		Op_CompLessThan(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_CompGreaterThan : public BinaryOperator
	{
	public:
		// constructors
		Op_CompGreaterThan(ASTNode*,ASTNode*);
		Op_CompGreaterThan(ASTNode*,ASTNode*,int,int,int,int);
		Op_CompGreaterThan(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_CompLessEqual : public BinaryOperator
	{
	public:
		// constructors
		Op_CompLessEqual(ASTNode*,ASTNode*);
		Op_CompLessEqual(ASTNode*,ASTNode*,int,int,int,int);
		Op_CompLessEqual(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_CompGreaterEqual : public BinaryOperator
	{
	public:
		// constructors
		Op_CompGreaterEqual(ASTNode*,ASTNode*);
		Op_CompGreaterEqual(ASTNode*,ASTNode*,int,int,int,int);
		Op_CompGreaterEqual(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_CompEqual : public BinaryOperator
	{
	public:
		// constructors
		Op_CompEqual(ASTNode*,ASTNode*);
		Op_CompEqual(ASTNode*,ASTNode*,int,int,int,int);
		Op_CompEqual(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_CompNotEqual : public BinaryOperator
	{
	public:
		// constructors
		Op_CompNotEqual(ASTNode*,ASTNode*);
		Op_CompNotEqual(ASTNode*,ASTNode*,int,int,int,int);
		Op_CompNotEqual(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_LeftShift : public BinaryOperator
	{
	public:
		// constructors
		Op_LeftShift(ASTNode*,ASTNode*);
		Op_LeftShift(ASTNode*,ASTNode*,int,int,int,int);
		Op_LeftShift(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_RightShift : public BinaryOperator
	{
	public:
		// constructors
		Op_RightShift(ASTNode*,ASTNode*);
		Op_RightShift(ASTNode*,ASTNode*,int,int,int,int);
		Op_RightShift(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_StringConcat : public BinaryOperator
	{
	public:
		// constructors
		Op_StringConcat(ASTNode*,ASTNode*);
		Op_StringConcat(ASTNode*,ASTNode*,int,int,int,int);
		Op_StringConcat(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_PrefixIncrement : public UnaryOperator
	{
	public:
		// constructors
		Op_PrefixIncrement(ASTNode*);
		Op_PrefixIncrement(ASTNode*,int,int,int,int);
		Op_PrefixIncrement(ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_PrefixDecrement : public UnaryOperator
	{
	public:
		// constructors
		Op_PrefixDecrement(ASTNode*);
		Op_PrefixDecrement(ASTNode*,int,int,int,int);
		Op_PrefixDecrement(ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_PostfixIncrement : public UnaryOperator
	{
	public:
		// constructors
		Op_PostfixIncrement(ASTNode*);
		Op_PostfixIncrement(ASTNode*,int,int,int,int);
		Op_PostfixIncrement(ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_PostfixDecrement : public UnaryOperator
	{
	public:
		// constructors
		Op_PostfixDecrement(ASTNode*);
		Op_PostfixDecrement(ASTNode*,int,int,int,int);
		Op_PostfixDecrement(ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_Assignment : public BinaryOperator
	{
	public:
		// constructors
		Op_Assignment(ASTNode*,ASTNode*);
		Op_Assignment(ASTNode*,ASTNode*,int,int,int,int);
		Op_Assignment(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignPlus : public BinaryOperator
	{
	public:
		// constructors
		Op_AssignPlus(ASTNode*,ASTNode*);
		Op_AssignPlus(ASTNode*,ASTNode*,int,int,int,int);
		Op_AssignPlus(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignMinus : public BinaryOperator
	{
	public:
		// constructors
		Op_AssignMinus(ASTNode*,ASTNode*);
		Op_AssignMinus(ASTNode*,ASTNode*,int,int,int,int);
		Op_AssignMinus(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignMult : public BinaryOperator
	{
	public:
		// constructors
		Op_AssignMult(ASTNode*,ASTNode*);
		Op_AssignMult(ASTNode*,ASTNode*,int,int,int,int);
		Op_AssignMult(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignDiv : public BinaryOperator
	{
	public:
		// constructors
		Op_AssignDiv(ASTNode*,ASTNode*);
		Op_AssignDiv(ASTNode*,ASTNode*,int,int,int,int);
		Op_AssignDiv(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignExpo : public BinaryOperator
	{
	public:
		// constructors
		Op_AssignExpo(ASTNode*,ASTNode*);
		Op_AssignExpo(ASTNode*,ASTNode*,int,int,int,int);
		Op_AssignExpo(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignMod : public BinaryOperator
	{
	public:
		// constructors
		Op_AssignMod(ASTNode*,ASTNode*);
		Op_AssignMod(ASTNode*,ASTNode*,int,int,int,int);
		Op_AssignMod(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignAnd : public BinaryOperator
	{
	public:
		// constructors
		Op_AssignAnd(ASTNode*,ASTNode*);
		Op_AssignAnd(ASTNode*,ASTNode*,int,int,int,int);
		Op_AssignAnd(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignOr : public BinaryOperator
	{
	public:
		// constructors
		Op_AssignOr(ASTNode*,ASTNode*);
		Op_AssignOr(ASTNode*,ASTNode*,int,int,int,int);
		Op_AssignOr(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignXor : public BinaryOperator
	{
	public:
		// constructors
		Op_AssignXor(ASTNode*,ASTNode*);
		Op_AssignXor(ASTNode*,ASTNode*,int,int,int,int);
		Op_AssignXor(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignConcat : public BinaryOperator
	{
	public:
		// constructors
		Op_AssignConcat(ASTNode*,ASTNode*);
		Op_AssignConcat(ASTNode*,ASTNode*,int,int,int,int);
		Op_AssignConcat(ASTNode*,ASTNode*,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};
}
#endif
