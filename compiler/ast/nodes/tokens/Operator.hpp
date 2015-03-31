#ifndef OPERATOR_HPP_DEFINED
#define OPERATOR_HPP_DEFINED

#include "Token.hpp"

namespace ast::nodes::tokens::operators
{
	/** operator base class */
	class Operator : public ast::nodes::tokens::Token
	{
	public: 
		// constructors
		Operator();
		Operator(int,int,int,int);
		Operator(const ast::nodes::NodeLocation&);
	};
	
	/** operator derived class */
	class Op_Plus : public Operator
	{
	public: 
		// constructors
		Op_Plus();
		Op_Plus(int,int,int,int);
		Op_Plus(const ast::nodes::NodeLocation&);
	};

	class Op_Minus : public Operator
	{
	public: 
		// constructors
		Op_Minus();
		Op_Minus(int,int,int,int);
		Op_Minus(const ast::nodes::NodeLocation&);
	};

	class Op_Mult : public Operator
	{
	public: 
		// constructors
		Op_Mult();
		Op_Mult(int,int,int,int);
		Op_Mult(const ast::nodes::NodeLocation&);
	};

	class Op_Div : public Operator
	{
	public: 
		// constructors
		Op_Div();
		Op_Div(int,int,int,int);
		Op_Div(const ast::nodes::NodeLocation&);
	};

	class Op_Modulo : public Operator
	{
	public: 
		// constructors
		Op_Modulo();
		Op_Modulo(int,int,int,int);
		Op_Modulo(const ast::nodes::NodeLocation&);
	};

	class Op_Exponentiation : public Operator
	{
	public: 
		// constructors
		Op_Exponentiation();
		Op_Exponentiation(int,int,int,int);
		Op_Exponentiation(const ast::nodes::NodeLocation&);
	};

	class Op_UnaryMinus : public Operator
	{
	public: 
		// constructors
		Op_UnaryMinus();
		Op_UnaryMinus(int,int,int,int);
		Op_UnaryMinus(const ast::nodes::NodeLocation&);
	};

	class Op_BitwiseOr : public Operator
	{
	public: 
		// constructors
		Op_BitwiseOr();
		Op_BitwiseOr(int,int,int,int);
		Op_BitwiseOr(const ast::nodes::NodeLocation&);
	};
	
	class Op_BitwiseAnd : public Operator
	{
	public: 
		// constructors
		Op_BitwiseAnd();
		Op_BitwiseAnd(int,int,int,int);
		Op_BitwiseAnd(const ast::nodes::NodeLocation&);
	};
	
	class Op_BitwiseXor : public Operator
	{
	public: 
		// constructors
		Op_BitwiseXor();
		Op_BitwiseXor(int,int,int,int);
		Op_BitwiseXor(const ast::nodes::NodeLocation&);
	};
	
	class Op_BitwiseNot : public Operator
	{
	public: 
		// constructors
		Op_BitwiseNot();
		Op_BitwiseNot(int,int,int,int);
		Op_BitwiseNot(const ast::nodes::NodeLocation&);
	};
	
	class Op_LogicalOr : public Operator
	{
	public: 
		// constructors
		Op_LogicalOr();
		Op_LogicalOr(int,int,int,int);
		Op_LogicalOr(const ast::nodes::NodeLocation&);
	};
	
	class Op_LogicalAnd : public Operator
	{
	public: 
		// constructors
		Op_LogicalAnd();
		Op_LogicalAnd(int,int,int,int);
		Op_LogicalAnd(const ast::nodes::NodeLocation&);
	};
	
	class Op_LogicalNot : public Operator
	{
	public: 
		// constructors
		Op_LogicalNot();
		Op_LogicalNot(int,int,int,int);
		Op_LogicalNot(const ast::nodes::NodeLocation&);
	};
	
	class Op_CompLessThan : public Operator
	{
	public: 
		// constructors
		Op_CompLessThan();
		Op_CompLessThan(int,int,int,int);
		Op_CompLessThan(const ast::nodes::NodeLocation&);
	};
	
	class Op_CompGreaterThan : public Operator
	{
	public: 
		// constructors
		Op_CompGreaterThan();
		Op_CompGreaterThan(int,int,int,int);
		Op_CompGreaterThan(const ast::nodes::NodeLocation&);
	};

	class Op_CompLessEqual : public Operator
	{
	public: 
		// constructors
		Op_CompLessEqual();
		Op_CompLessEqual(int,int,int,int);
		Op_CompLessEqual(const ast::nodes::NodeLocation&);
	};

	class Op_CompGreaterEqual : public Operator
	{
	public: 
		// constructors
		Op_CompGreaterEqual();
		Op_CompGreaterEqual(int,int,int,int);
		Op_CompGreaterEqual(const ast::nodes::NodeLocation&);
	};
		
	class Op_CompEqual : public Operator
	{
	public: 
		// constructors
		Op_CompEqual();
		Op_CompEqual(int,int,int,int);
		Op_CompEqual(const ast::nodes::NodeLocation&);
	};
		
	class Op_CompNotEqual : public Operator
	{
	public: 
		// constructors
		Op_CompNotEqual();
		Op_CompNotEqual(int,int,int,int);
		Op_CompNotEqual(const ast::nodes::NodeLocation&);
	};
		
	class Op_LeftShift : public Operator
	{
	public: 
		// constructors
		Op_LeftShift();
		Op_LeftShift(int,int,int,int);
		Op_LeftShift(const ast::nodes::NodeLocation&);
	};

	class Op_RightShift : public Operator
	{
	public: 
		// constructors
		Op_RightShift();
		Op_RightShift(int,int,int,int);
		Op_RightShift(const ast::nodes::NodeLocation&);
	};

	class Op_StringConcat : public Operator
	{
	public: 
		// constructors
		Op_StringConcat();
		Op_StringConcat(int,int,int,int);
		Op_StringConcat(const ast::nodes::NodeLocation&);
	};

	class Op_PrefixIncrement : public Operator
	{
	public: 
		// constructors
		Op_PrefixIncrement();
		Op_PrefixIncrement(int,int,int,int);
		Op_PrefixIncrement(const ast::nodes::NodeLocation&);
	};

	class Op_PrefixDecrement : public Operator
	{
	public: 
		// constructors
		Op_PrefixDecrement();
		Op_PrefixDecrement(int,int,int,int);
		Op_PrefixDecrement(const ast::nodes::NodeLocation&);
	};

	class Op_PostfixIncrement : public Operator
	{
	public: 
		// constructors
		Op_PostfixIncrement();
		Op_PostfixIncrement(int,int,int,int);
		Op_PostfixIncrement(const ast::nodes::NodeLocation&);
	};
	
	class Op_PostfixDecrement : public Operator
	{
	public: 
		// constructors
		Op_PostfixDecrement();
		Op_PostfixDecrement(int,int,int,int);
		Op_PostfixDecrement(const ast::nodes::NodeLocation&);
	};
	
	class Op_Assignment : public Operator
	{
	public: 
		// constructors
		Op_Assignment();
		Op_Assignment(int,int,int,int);
		Op_Assignment(const ast::nodes::NodeLocation&);
	};
	
	class Op_AssignPlus : public Operator
	{
	public: 
		// constructors
		Op_AssignPlus();
		Op_AssignPlus(int,int,int,int);
		Op_AssignPlus(const ast::nodes::NodeLocation&);
	};
	
	class Op_AssignLess : public Operator
	{
	public: 
		// constructors
		Op_AssignLess();
		Op_AssignLess(int,int,int,int);
		Op_AssignLess(const ast::nodes::NodeLocation&);
	};
		
	class Op_AssignMult : public Operator
	{
	public: 
		// constructors
		Op_AssignMult();
		Op_AssignMult(int,int,int,int);
		Op_AssignMult(const ast::nodes::NodeLocation&);
	};
		
	class Op_AssignDiv : public Operator
	{
	public: 
		// constructors
		Op_AssignDiv();
		Op_AssignDiv(int,int,int,int);
		Op_AssignDiv(const ast::nodes::NodeLocation&);
	};
		
	class Op_AssignExpo : public Operator
	{
	public: 
		// constructors
		Op_AssignExpo();
		Op_AssignExpo(int,int,int,int);
		Op_AssignExpo(const ast::nodes::NodeLocation&);
	};
		
	class Op_AssignMod : public Operator
	{
	public: 
		// constructors
		Op_AssignMod();
		Op_AssignMod(int,int,int,int);
		Op_AssignMod(const ast::nodes::NodeLocation&);
	};
		
	class Op_AssignAnd : public Operator
	{
	public: 
		// constructors
		Op_AssignAnd();
		Op_AssignAnd(int,int,int,int);
		Op_AssignAnd(const ast::nodes::NodeLocation&);
	};
	
	class Op_AssignOr : public Operator
	{
	public: 
		// constructors
		Op_AssignOr();
		Op_AssignOr(int,int,int,int);
		Op_AssignOr(const ast::nodes::NodeLocation&);
	};
	
	class Op_AssignXor : public Operator
	{
	public: 
		// constructors
		Op_AssignXor();
		Op_AssignXor(int,int,int,int);
		Op_AssignXor(const ast::nodes::NodeLocation&);
	};
	
	class Op_AssignConcat : public Operator
	{
	public: 
		// constructors
		Op_AssignConcat();
		Op_AssignConcat(int,int,int,int);
		Op_AssignConcat(const ast::nodes::NodeLocation&);
	};
}
#endif