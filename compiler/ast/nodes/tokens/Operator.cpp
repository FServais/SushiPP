#include "Operator.hpp"
#include "../../visitor/ASTVisitor.hpp"

using namespace ast;

/** Operator base class */
Operator::Operator(const std::string& node_name) : Token(node_name) {}

Operator::Operator(const std::string& node_name, int first_line, int last_line, int first_column, int last_column)
	: Token(node_name, first_line, last_line, first_column, last_column)
{

}

Operator::Operator(const std::string& node_name, const NodeLocation& node_loc)
	: Token(node_name, node_loc)
{

}

void Operator::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

BinaryOperator::BinaryOperator(const std::string& node_name, ASTNode* left, ASTNode* right)
  : Operator(node_name)
{
	add_child(left);
	add_child(right);
}

BinaryOperator::BinaryOperator(const std::string& node_name, ASTNode* left, ASTNode* right, 
								int first_line, int last_line, int first_column, int last_column)
  : Operator(node_name, first_line, last_line, first_column, last_column)
{
	add_child(left);
	add_child(right);
}

BinaryOperator::BinaryOperator(const std::string& node_name, ASTNode* left, ASTNode* right, const NodeLocation& node_loc)
  : Operator(node_name, node_loc)
{
	add_child(left);
	add_child(right);
}

ASTNode& BinaryOperator::get_left_operand()
{
	return *children[0];
}

ASTNode& BinaryOperator::get_right_operand()
{
	return *children[1];
}


UnaryOperator::UnaryOperator(const std::string& node_name, ASTNode* operand)
  : Operator(node_name)
{
	add_child(operand);
}

UnaryOperator::UnaryOperator(const std::string& node_name, ASTNode* operand , 
								int first_line, int last_line, int first_column, int last_column)
  : Operator(node_name, first_line, last_line, first_column, last_column)
{
	add_child(operand);
}

UnaryOperator::UnaryOperator(const std::string& node_name, ASTNode* operand , const NodeLocation& node_loc)
  : Operator(node_name, node_loc)
{
	add_child(operand);
}

ASTNode& UnaryOperator::get_operand()
{
	return *children[0];
}

/** Operator derived classes */
/* Operator : + */
Op_Plus::Op_Plus(ASTNode* left, ASTNode* right) : BinaryOperator("+", left, right) { }

Op_Plus::Op_Plus(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("+", left, right, first_line, last_line, first_column, last_column)
{

}

Op_Plus::Op_Plus(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("+", left, right, node_loc)
{

}

void Op_Plus::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* Operator : - */
Op_Minus::Op_Minus(ASTNode* left, ASTNode* right) : BinaryOperator("-", left, right) { }

Op_Minus::Op_Minus(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("-", left, right, first_line, last_line, first_column, last_column)
{

}

Op_Minus::Op_Minus(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("-", left, right, node_loc)
{

}

void Op_Minus::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* Operator : * */
Op_Mult::Op_Mult(ASTNode* left, ASTNode* right) : BinaryOperator("*", left, right) { }

Op_Mult::Op_Mult(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("*", left, right, first_line, last_line, first_column, last_column)
{

}

Op_Mult::Op_Mult(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("*", left, right, node_loc)
{

}

void Op_Mult::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* Operator : / */
Op_Div::Op_Div(ASTNode* left, ASTNode* right) : BinaryOperator("/", left, right) { }

Op_Div::Op_Div(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("/", left, right, first_line, last_line, first_column, last_column)
{

}

Op_Div::Op_Div(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("/", left, right, node_loc)
{

}

void Op_Div::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : % */
Op_Modulo::Op_Modulo(ASTNode* left, ASTNode* right) : BinaryOperator("%", left, right) { }

Op_Modulo::Op_Modulo(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("%", left, right, first_line, last_line, first_column, last_column)
{

}

Op_Modulo::Op_Modulo(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("%", left, right, node_loc)
{

}

void Op_Modulo::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
}

/* Operator : ** */
Op_Exponentiation::Op_Exponentiation(ASTNode* left, ASTNode* right) : BinaryOperator("**", left, right) { }

Op_Exponentiation::Op_Exponentiation(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("**", left, right, first_line, last_line, first_column, last_column)
{

}

Op_Exponentiation::Op_Exponentiation(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("**", left, right, node_loc)
{

}

void Op_Exponentiation::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : -1 */
Op_UnaryMinus::Op_UnaryMinus(ASTNode* operand) : UnaryOperator("-", operand) { }

Op_UnaryMinus::Op_UnaryMinus(ASTNode* operand, int first_line, int last_line, int first_column, int last_column)
	: UnaryOperator("-", operand, first_line, last_line, first_column, last_column)
{

}

Op_UnaryMinus::Op_UnaryMinus(ASTNode* operand, const NodeLocation& node_loc) : UnaryOperator("-", operand, node_loc)
{

}

void Op_UnaryMinus::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator :| */
Op_BitwiseOr::Op_BitwiseOr(ASTNode* left, ASTNode* right) : BinaryOperator("|", left, right) { }

Op_BitwiseOr::Op_BitwiseOr(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("|", left, right, first_line, last_line, first_column, last_column)
{

}

Op_BitwiseOr::Op_BitwiseOr(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("|", left, right, node_loc)
{

}

void Op_BitwiseOr::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : & */
Op_BitwiseAnd::Op_BitwiseAnd(ASTNode* left, ASTNode* right) : BinaryOperator("&", left, right) { }

Op_BitwiseAnd::Op_BitwiseAnd(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("&", left, right, first_line, last_line, first_column, last_column)
{

}

Op_BitwiseAnd::Op_BitwiseAnd(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("&", left, right, node_loc)
{

}

void Op_BitwiseAnd::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : ^*/
Op_BitwiseXor::Op_BitwiseXor(ASTNode* left, ASTNode* right) : BinaryOperator("^", left, right) { }

Op_BitwiseXor::Op_BitwiseXor(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("^", left, right, first_line, last_line, first_column, last_column)
{

}

Op_BitwiseXor::Op_BitwiseXor(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("^", left, right, node_loc)
{

}

void Op_BitwiseXor::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : ~ */
Op_BitwiseNot::Op_BitwiseNot(ASTNode* operand) : UnaryOperator("~", operand) { }

Op_BitwiseNot::Op_BitwiseNot(ASTNode* operand, int first_line, int last_line, int first_column, int last_column)
	: UnaryOperator("~", operand, first_line, last_line, first_column, last_column)
{

}

Op_BitwiseNot::Op_BitwiseNot(ASTNode* operand, const NodeLocation& node_loc) : UnaryOperator("~", operand, node_loc)
{

}

void Op_BitwiseNot::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : || */
Op_LogicalOr::Op_LogicalOr(ASTNode* left, ASTNode* right) : BinaryOperator("||", left, right) { }

Op_LogicalOr::Op_LogicalOr(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("||", left, right, first_line, last_line, first_column, last_column)
{

}

Op_LogicalOr::Op_LogicalOr(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("||", left, right, node_loc)
{

}

void Op_LogicalOr::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : && */
Op_LogicalAnd::Op_LogicalAnd(ASTNode* left, ASTNode* right) : BinaryOperator("&&", left, right) { }

Op_LogicalAnd::Op_LogicalAnd(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("&&", left, right, first_line, last_line, first_column, last_column)
{

}

Op_LogicalAnd::Op_LogicalAnd(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("&&", left, right, node_loc)
{

}

void Op_LogicalAnd::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : ! */
Op_LogicalNot::Op_LogicalNot(ASTNode* operand) : UnaryOperator("!", operand) { }

Op_LogicalNot::Op_LogicalNot(ASTNode* operand, int first_line, int last_line, int first_column, int last_column)
	: UnaryOperator("!", operand, first_line, last_line, first_column, last_column)
{

}

Op_LogicalNot::Op_LogicalNot(ASTNode* operand, const NodeLocation& node_loc) : UnaryOperator("!", operand, node_loc)
{

}

void Op_LogicalNot::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : < */
Op_CompLessThan::Op_CompLessThan(ASTNode* left, ASTNode* right) : BinaryOperator("<", left, right) { }

Op_CompLessThan::Op_CompLessThan(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("<", left, right, first_line, last_line, first_column, last_column)
{

}

Op_CompLessThan::Op_CompLessThan(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("<", left, right, node_loc)
{

}

void Op_CompLessThan::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : > */
Op_CompGreaterThan::Op_CompGreaterThan(ASTNode* left, ASTNode* right) : BinaryOperator(">", left, right) { }

Op_CompGreaterThan::Op_CompGreaterThan(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator(">", left, right, first_line, last_line, first_column, last_column)
{

}

Op_CompGreaterThan::Op_CompGreaterThan(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator(">", left, right, node_loc)
{

}

void Op_CompGreaterThan::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : <= */
Op_CompLessEqual::Op_CompLessEqual(ASTNode* left, ASTNode* right) : BinaryOperator("<=", left, right) { }

Op_CompLessEqual::Op_CompLessEqual(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("<=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_CompLessEqual::Op_CompLessEqual(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("<=", left, right, node_loc)
{

}

void Op_CompLessEqual::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : >= */
Op_CompGreaterEqual::Op_CompGreaterEqual(ASTNode* left, ASTNode* right) : BinaryOperator(">=", left, right) { }

Op_CompGreaterEqual::Op_CompGreaterEqual(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator(">=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_CompGreaterEqual::Op_CompGreaterEqual(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator(">=", left, right, node_loc)
{

}

void Op_CompGreaterEqual::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : == */
Op_CompEqual::Op_CompEqual(ASTNode* left, ASTNode* right) : BinaryOperator("==", left, right) { }

Op_CompEqual::Op_CompEqual(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("==", left, right, first_line, last_line, first_column, last_column)
{

}

Op_CompEqual::Op_CompEqual(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("==", left, right, node_loc)
{

}

void Op_CompEqual::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : != */
Op_CompNotEqual::Op_CompNotEqual(ASTNode* left, ASTNode* right) : BinaryOperator("!=", left, right) { }

Op_CompNotEqual::Op_CompNotEqual(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("!=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_CompNotEqual::Op_CompNotEqual(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("!=", left, right, node_loc)
{

}

void Op_CompNotEqual::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : << */
Op_LeftShift::Op_LeftShift(ASTNode* left, ASTNode* right) : BinaryOperator("<<", left, right) { }

Op_LeftShift::Op_LeftShift(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("<<", left, right, first_line, last_line, first_column, last_column)
{

}

Op_LeftShift::Op_LeftShift(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("<<", left, right, node_loc)
{

}

void Op_LeftShift::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : >> */
Op_RightShift::Op_RightShift(ASTNode* left, ASTNode* right) : BinaryOperator(">>", left, right) { }

Op_RightShift::Op_RightShift(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator(">>", left, right, first_line, last_line, first_column, last_column)
{

}

Op_RightShift::Op_RightShift(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator(">>", left, right, node_loc)
{

}

void Op_RightShift::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : . */
Op_StringConcat::Op_StringConcat(ASTNode* left, ASTNode* right) : BinaryOperator(".", left, right) { }

Op_StringConcat::Op_StringConcat(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator(".", left, right, first_line, last_line, first_column, last_column)
{

}

Op_StringConcat::Op_StringConcat(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator(".", left, right, node_loc)
{

}

void Op_StringConcat::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : ++ prefix */
Op_PrefixIncrement::Op_PrefixIncrement(ASTNode* operand) : UnaryOperator("++", operand) { }

Op_PrefixIncrement::Op_PrefixIncrement(ASTNode* operand, int first_line, int last_line, int first_column, int last_column)
	: UnaryOperator("++", operand, first_line, last_line, first_column, last_column)
{

}

Op_PrefixIncrement::Op_PrefixIncrement(ASTNode* operand, const NodeLocation& node_loc) : UnaryOperator("++", operand, node_loc)
{

}

void Op_PrefixIncrement::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : -- prefix*/
Op_PrefixDecrement::Op_PrefixDecrement(ASTNode* operand) : UnaryOperator("--", operand) { }

Op_PrefixDecrement::Op_PrefixDecrement(ASTNode* operand, int first_line, int last_line, int first_column, int last_column)
	: UnaryOperator("--", operand, first_line, last_line, first_column, last_column)
{

}

Op_PrefixDecrement::Op_PrefixDecrement(ASTNode* operand, const NodeLocation& node_loc) : UnaryOperator("--", operand, node_loc)
{

}

void Op_PrefixDecrement::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : ++ postfix */
Op_PostfixIncrement::Op_PostfixIncrement(ASTNode* operand) : UnaryOperator("++", operand) { }

Op_PostfixIncrement::Op_PostfixIncrement(ASTNode* operand, int first_line, int last_line, int first_column, int last_column)
	: UnaryOperator("++", operand, first_line, last_line, first_column, last_column)
{

}

Op_PostfixIncrement::Op_PostfixIncrement(ASTNode* operand, const NodeLocation& node_loc) : UnaryOperator("++", operand, node_loc)
{

}

void Op_PostfixIncrement::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : -- postfix */
Op_PostfixDecrement::Op_PostfixDecrement(ASTNode* operand) : UnaryOperator("--", operand) { }

Op_PostfixDecrement::Op_PostfixDecrement(ASTNode* operand, int first_line, int last_line, int first_column, int last_column)
	: UnaryOperator("--", operand, first_line, last_line, first_column, last_column)
{

}

Op_PostfixDecrement::Op_PostfixDecrement(ASTNode* operand, const NodeLocation& node_loc) : UnaryOperator("--", operand, node_loc)
{

}

void Op_PostfixDecrement::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : = */
Op_Assignment::Op_Assignment(ASTNode* left, ASTNode* right) : BinaryOperator("=", left, right) { }

Op_Assignment::Op_Assignment(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_Assignment::Op_Assignment(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("=", left, right, node_loc)
{

}

void Op_Assignment::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : += */
Op_AssignPlus::Op_AssignPlus(ASTNode* left, ASTNode* right) : BinaryOperator("+=", left, right) { }

Op_AssignPlus::Op_AssignPlus(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("+=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_AssignPlus::Op_AssignPlus(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("+=", left, right, node_loc)
{

}

void Op_AssignPlus::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : -= */
Op_AssignMinus::Op_AssignMinus(ASTNode* left, ASTNode* right) : BinaryOperator("-=", left, right) { }

Op_AssignMinus::Op_AssignMinus(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("-=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_AssignMinus::Op_AssignMinus(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("-=", left, right, node_loc)
{

}

void Op_AssignMinus::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : *= */
Op_AssignMult::Op_AssignMult(ASTNode* left, ASTNode* right) : BinaryOperator("*=", left, right) { }

Op_AssignMult::Op_AssignMult(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("*=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_AssignMult::Op_AssignMult(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("*=", left, right, node_loc)
{

}

void Op_AssignMult::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : /= */
Op_AssignDiv::Op_AssignDiv(ASTNode* left, ASTNode* right) : BinaryOperator("/=", left, right) { }

Op_AssignDiv::Op_AssignDiv(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("/=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_AssignDiv::Op_AssignDiv(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("/=", left, right, node_loc)
{

}

void Op_AssignDiv::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : **= */
Op_AssignExpo::Op_AssignExpo(ASTNode* left, ASTNode* right) : BinaryOperator("**=", left, right) { }

Op_AssignExpo::Op_AssignExpo(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("**=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_AssignExpo::Op_AssignExpo(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("**=", left, right, node_loc)
{

}

void Op_AssignExpo::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : %= */
Op_AssignMod::Op_AssignMod(ASTNode* left, ASTNode* right) : BinaryOperator("%=", left, right) { }

Op_AssignMod::Op_AssignMod(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("%=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_AssignMod::Op_AssignMod(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("%=", left, right, node_loc)
{

}

void Op_AssignMod::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : &= */
Op_AssignAnd::Op_AssignAnd(ASTNode* left, ASTNode* right) : BinaryOperator("&=", left, right) { }

Op_AssignAnd::Op_AssignAnd(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("&=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_AssignAnd::Op_AssignAnd(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("&=", left, right, node_loc)
{

}

void Op_AssignAnd::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : |= */
Op_AssignOr::Op_AssignOr(ASTNode* left, ASTNode* right) : BinaryOperator("|=", left, right) { }

Op_AssignOr::Op_AssignOr(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("|=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_AssignOr::Op_AssignOr(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("|=", left, right, node_loc)
{

}

void Op_AssignOr::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : ^= */
Op_AssignXor::Op_AssignXor(ASTNode* left, ASTNode* right) : BinaryOperator("^=", left, right) { }

Op_AssignXor::Op_AssignXor(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator("^=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_AssignXor::Op_AssignXor(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator("^=", left, right, node_loc)
{

}

void Op_AssignXor::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);

}

/* Operator : .= */
Op_AssignConcat::Op_AssignConcat(ASTNode* left, ASTNode* right) : BinaryOperator(".=", left, right) { }

Op_AssignConcat::Op_AssignConcat(ASTNode* left, ASTNode* right, int first_line, int last_line, int first_column, int last_column)
	: BinaryOperator(".=", left, right, first_line, last_line, first_column, last_column)
{

}

Op_AssignConcat::Op_AssignConcat(ASTNode* left, ASTNode* right, const NodeLocation& node_loc) : BinaryOperator(".=", left, right, node_loc)
{

}

void Op_AssignConcat::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);	 
}

/* Operator : : */
Op_AssignFunc::Op_AssignFunc() : Operator(":") { }

Op_AssignFunc::Op_AssignFunc(int first_line, int last_line, int first_column, int last_column)
	: Operator(":", first_line, last_line, first_column, last_column)
{

}

Op_AssignFunc::Op_AssignFunc(const NodeLocation& node_loc) : Operator(":", node_loc)
{

}

void Op_AssignFunc::accept(ASTVisitor& visitor)
{
	visitor.visit(*this);
	 
}

