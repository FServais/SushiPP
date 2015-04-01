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

	/** operator derived class */
	class Op_Plus : public Operator
	{
	public:
		// constructors
		Op_Plus();
		Op_Plus(int,int,int,int);
		Op_Plus(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_Minus : public Operator
	{
	public:
		// constructors
		Op_Minus();
		Op_Minus(int,int,int,int);
		Op_Minus(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_Mult : public Operator
	{
	public:
		// constructors
		Op_Mult();
		Op_Mult(int,int,int,int);
		Op_Mult(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_Div : public Operator
	{
	public:
		// constructors
		Op_Div();
		Op_Div(int,int,int,int);
		Op_Div(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_Modulo : public Operator
	{
	public:
		// constructors
		Op_Modulo();
		Op_Modulo(int,int,int,int);
		Op_Modulo(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_Exponentiation : public Operator
	{
	public:
		// constructors
		Op_Exponentiation();
		Op_Exponentiation(int,int,int,int);
		Op_Exponentiation(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_UnaryMinus : public Operator
	{
	public:
		// constructors
		Op_UnaryMinus();
		Op_UnaryMinus(int,int,int,int);
		Op_UnaryMinus(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_BitwiseOr : public Operator
	{
	public:
		// constructors
		Op_BitwiseOr();
		Op_BitwiseOr(int,int,int,int);
		Op_BitwiseOr(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_BitwiseAnd : public Operator
	{
	public:
		// constructors
		Op_BitwiseAnd();
		Op_BitwiseAnd(int,int,int,int);
		Op_BitwiseAnd(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_BitwiseXor : public Operator
	{
	public:
		// constructors
		Op_BitwiseXor();
		Op_BitwiseXor(int,int,int,int);
		Op_BitwiseXor(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_BitwiseNot : public Operator
	{
	public:
		// constructors
		Op_BitwiseNot();
		Op_BitwiseNot(int,int,int,int);
		Op_BitwiseNot(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_LogicalOr : public Operator
	{
	public:
		// constructors
		Op_LogicalOr();
		Op_LogicalOr(int,int,int,int);
		Op_LogicalOr(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_LogicalAnd : public Operator
	{
	public:
		// constructors
		Op_LogicalAnd();
		Op_LogicalAnd(int,int,int,int);
		Op_LogicalAnd(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_LogicalNot : public Operator
	{
	public:
		// constructors
		Op_LogicalNot();
		Op_LogicalNot(int,int,int,int);
		Op_LogicalNot(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_CompLessThan : public Operator
	{
	public:
		// constructors
		Op_CompLessThan();
		Op_CompLessThan(int,int,int,int);
		Op_CompLessThan(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_CompGreaterThan : public Operator
	{
	public:
		// constructors
		Op_CompGreaterThan();
		Op_CompGreaterThan(int,int,int,int);
		Op_CompGreaterThan(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_CompLessEqual : public Operator
	{
	public:
		// constructors
		Op_CompLessEqual();
		Op_CompLessEqual(int,int,int,int);
		Op_CompLessEqual(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_CompGreaterEqual : public Operator
	{
	public:
		// constructors
		Op_CompGreaterEqual();
		Op_CompGreaterEqual(int,int,int,int);
		Op_CompGreaterEqual(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_CompEqual : public Operator
	{
	public:
		// constructors
		Op_CompEqual();
		Op_CompEqual(int,int,int,int);
		Op_CompEqual(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_CompNotEqual : public Operator
	{
	public:
		// constructors
		Op_CompNotEqual();
		Op_CompNotEqual(int,int,int,int);
		Op_CompNotEqual(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_LeftShift : public Operator
	{
	public:
		// constructors
		Op_LeftShift();
		Op_LeftShift(int,int,int,int);
		Op_LeftShift(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_RightShift : public Operator
	{
	public:
		// constructors
		Op_RightShift();
		Op_RightShift(int,int,int,int);
		Op_RightShift(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_StringConcat : public Operator
	{
	public:
		// constructors
		Op_StringConcat();
		Op_StringConcat(int,int,int,int);
		Op_StringConcat(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_PrefixIncrement : public Operator
	{
	public:
		// constructors
		Op_PrefixIncrement();
		Op_PrefixIncrement(int,int,int,int);
		Op_PrefixIncrement(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_PrefixDecrement : public Operator
	{
	public:
		// constructors
		Op_PrefixDecrement();
		Op_PrefixDecrement(int,int,int,int);
		Op_PrefixDecrement(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_PostfixIncrement : public Operator
	{
	public:
		// constructors
		Op_PostfixIncrement();
		Op_PostfixIncrement(int,int,int,int);
		Op_PostfixIncrement(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_PostfixDecrement : public Operator
	{
	public:
		// constructors
		Op_PostfixDecrement();
		Op_PostfixDecrement(int,int,int,int);
		Op_PostfixDecrement(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_Assignment : public Operator
	{
	public:
		// constructors
		Op_Assignment();
		Op_Assignment(int,int,int,int);
		Op_Assignment(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignPlus : public Operator
	{
	public:
		// constructors
		Op_AssignPlus();
		Op_AssignPlus(int,int,int,int);
		Op_AssignPlus(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignMinus : public Operator
	{
	public:
		// constructors
		Op_AssignMinus();
		Op_AssignMinus(int,int,int,int);
		Op_AssignMinus(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignMult : public Operator
	{
	public:
		// constructors
		Op_AssignMult();
		Op_AssignMult(int,int,int,int);
		Op_AssignMult(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignDiv : public Operator
	{
	public:
		// constructors
		Op_AssignDiv();
		Op_AssignDiv(int,int,int,int);
		Op_AssignDiv(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignExpo : public Operator
	{
	public:
		// constructors
		Op_AssignExpo();
		Op_AssignExpo(int,int,int,int);
		Op_AssignExpo(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignMod : public Operator
	{
	public:
		// constructors
		Op_AssignMod();
		Op_AssignMod(int,int,int,int);
		Op_AssignMod(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignAnd : public Operator
	{
	public:
		// constructors
		Op_AssignAnd();
		Op_AssignAnd(int,int,int,int);
		Op_AssignAnd(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignOr : public Operator
	{
	public:
		// constructors
		Op_AssignOr();
		Op_AssignOr(int,int,int,int);
		Op_AssignOr(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignXor : public Operator
	{
	public:
		// constructors
		Op_AssignXor();
		Op_AssignXor(int,int,int,int);
		Op_AssignXor(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignConcat : public Operator
	{
	public:
		// constructors
		Op_AssignConcat();
		Op_AssignConcat(int,int,int,int);
		Op_AssignConcat(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Op_AssignFunc : public Operator
	{
	public:
		// constructors
		Op_AssignFunc();
		Op_AssignFunc(int,int,int,int);
		Op_AssignFunc(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};
}
#endif
