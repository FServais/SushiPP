#include "Operator.hpp"

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

/** Operator derived classes */
/* Operator : + */
Op_Plus::Op_Plus() : Operator("+") { }

Op_Plus::Op_Plus(int first_line, int last_line, int first_column, int last_column)
	: Operator("+", first_line, last_line, first_column, last_column)
{

}

Op_Plus::Op_Plus(const NodeLocation& node_loc) : Operator("+", node_loc)
{

}

/* Operator : - */
Op_Minus::Op_Minus() : Operator("-") { }

Op_Minus::Op_Minus(int first_line, int last_line, int first_column, int last_column)
	: Operator("-", first_line, last_line, first_column, last_column)
{

}

Op_Minus::Op_Minus(const NodeLocation& node_loc) : Operator("-", node_loc)
{

}

/* Operator : * */
Op_Mult::Op_Mult() : Operator("*") { }

Op_Mult::Op_Mult(int first_line, int last_line, int first_column, int last_column)
	: Operator("*", first_line, last_line, first_column, last_column)
{

}

Op_Mult::Op_Mult(const NodeLocation& node_loc) : Operator("*", node_loc)
{

}

/* Operator : / */
Op_Div::Op_Div() : Operator("/") { }

Op_Div::Op_Div(int first_line, int last_line, int first_column, int last_column)
	: Operator("/", first_line, last_line, first_column, last_column)
{

}

Op_Div::Op_Div(const NodeLocation& node_loc) : Operator("/", node_loc)
{

}

/* Operator : % */
Op_Modulo::Op_Modulo() : Operator("%%") { }

Op_Modulo::Op_Modulo(int first_line, int last_line, int first_column, int last_column)
	: Operator("%%", first_line, last_line, first_column, last_column)
{

}

Op_Modulo::Op_Modulo(const NodeLocation& node_loc) : Operator("%%", node_loc)
{

}

/* Operator : ** */
Op_Exponentiation::Op_Exponentiation() : Operator("**") { }

Op_Exponentiation::Op_Exponentiation(int first_line, int last_line, int first_column, int last_column)
	: Operator("**", first_line, last_line, first_column, last_column)
{

}

Op_Exponentiation::Op_Exponentiation(const NodeLocation& node_loc) : Operator("**", node_loc)
{

}

/* Operator : -1 */
Op_UnaryMinus::Op_UnaryMinus() : Operator("-") { }

Op_UnaryMinus::Op_UnaryMinus(int first_line, int last_line, int first_column, int last_column)
	: Operator("-", first_line, last_line, first_column, last_column)
{

}

Op_UnaryMinus::Op_UnaryMinus(const NodeLocation& node_loc) : Operator("-", node_loc)
{

}

/* Operator :| */
Op_BitwiseOr::Op_BitwiseOr() : Operator("|") { }

Op_BitwiseOr::Op_BitwiseOr(int first_line, int last_line, int first_column, int last_column)
	: Operator("|", first_line, last_line, first_column, last_column)
{

}

Op_BitwiseOr::Op_BitwiseOr(const NodeLocation& node_loc) : Operator("|", node_loc)
{

}

/* Operator : & */
Op_BitwiseAnd::Op_BitwiseAnd() : Operator("&") { }

Op_BitwiseAnd::Op_BitwiseAnd(int first_line, int last_line, int first_column, int last_column)
	: Operator("&", first_line, last_line, first_column, last_column)
{

}

Op_BitwiseAnd::Op_BitwiseAnd(const NodeLocation& node_loc) : Operator("&", node_loc)
{

}

/* Operator : ^*/
Op_BitwiseXor::Op_BitwiseXor() : Operator("^") { }

Op_BitwiseXor::Op_BitwiseXor(int first_line, int last_line, int first_column, int last_column)
	: Operator("^", first_line, last_line, first_column, last_column)
{

}

Op_BitwiseXor::Op_BitwiseXor(const NodeLocation& node_loc) : Operator("^", node_loc)
{

}

/* Operator : ~ */
Op_BitwiseNot::Op_BitwiseNot() : Operator("~") { }

Op_BitwiseNot::Op_BitwiseNot(int first_line, int last_line, int first_column, int last_column)
	: Operator("~", first_line, last_line, first_column, last_column)
{

}

Op_BitwiseNot::Op_BitwiseNot(const NodeLocation& node_loc) : Operator("~", node_loc)
{

}

/* Operator : || */
Op_LogicalOr::Op_LogicalOr() : Operator("||") { }

Op_LogicalOr::Op_LogicalOr(int first_line, int last_line, int first_column, int last_column)
	: Operator("||", first_line, last_line, first_column, last_column)
{

}

Op_LogicalOr::Op_LogicalOr(const NodeLocation& node_loc) : Operator("||", node_loc)
{

}

/* Operator : && */
Op_LogicalAnd::Op_LogicalAnd() : Operator("&&") { }

Op_LogicalAnd::Op_LogicalAnd(int first_line, int last_line, int first_column, int last_column)
	: Operator("&&", first_line, last_line, first_column, last_column)
{

}

Op_LogicalAnd::Op_LogicalAnd(const NodeLocation& node_loc) : Operator("&&", node_loc)
{

}

/* Operator : ! */
Op_LogicalNot::Op_LogicalNot() : Operator("!") { }

Op_LogicalNot::Op_LogicalNot(int first_line, int last_line, int first_column, int last_column)
	: Operator("!", first_line, last_line, first_column, last_column)
{

}

Op_LogicalNot::Op_LogicalNot(const NodeLocation& node_loc) : Operator("!", node_loc)
{

}

/* Operator : < */
Op_CompLessThan::Op_CompLessThan() : Operator("<") { }

Op_CompLessThan::Op_CompLessThan(int first_line, int last_line, int first_column, int last_column)
	: Operator("<", first_line, last_line, first_column, last_column)
{

}

Op_CompLessThan::Op_CompLessThan(const NodeLocation& node_loc) : Operator("<", node_loc)
{

}

/* Operator : > */
Op_CompGreaterThan::Op_CompGreaterThan() : Operator(">") { }

Op_CompGreaterThan::Op_CompGreaterThan(int first_line, int last_line, int first_column, int last_column)
	: Operator(">", first_line, last_line, first_column, last_column)
{

}

Op_CompGreaterThan::Op_CompGreaterThan(const NodeLocation& node_loc) : Operator(">", node_loc)
{

}

/* Operator : <= */
Op_CompLessEqual::Op_CompLessEqual() : Operator("<=") { }

Op_CompLessEqual::Op_CompLessEqual(int first_line, int last_line, int first_column, int last_column)
	: Operator("<=", first_line, last_line, first_column, last_column)
{

}

Op_CompLessEqual::Op_CompLessEqual(const NodeLocation& node_loc) : Operator("<=", node_loc)
{

}

/* Operator : >= */
Op_CompGreaterEqual::Op_CompGreaterEqual() : Operator(">=") { }

Op_CompGreaterEqual::Op_CompGreaterEqual(int first_line, int last_line, int first_column, int last_column)
	: Operator(">=", first_line, last_line, first_column, last_column)
{

}

Op_CompGreaterEqual::Op_CompGreaterEqual(const NodeLocation& node_loc) : Operator(">=", node_loc)
{

}

/* Operator : == */
Op_CompEqual::Op_CompEqual() : Operator("==") { }

Op_CompEqual::Op_CompEqual(int first_line, int last_line, int first_column, int last_column)
	: Operator("==", first_line, last_line, first_column, last_column)
{

}

Op_CompEqual::Op_CompEqual(const NodeLocation& node_loc) : Operator("==", node_loc)
{

}

/* Operator : != */
Op_CompNotEqual::Op_CompNotEqual() : Operator("!=") { }

Op_CompNotEqual::Op_CompNotEqual(int first_line, int last_line, int first_column, int last_column)
	: Operator("!=", first_line, last_line, first_column, last_column)
{

}

Op_CompNotEqual::Op_CompNotEqual(const NodeLocation& node_loc) : Operator("!=", node_loc)
{

}

/* Operator : << */
Op_LeftShift::Op_LeftShift() : Operator("<<") { }

Op_LeftShift::Op_LeftShift(int first_line, int last_line, int first_column, int last_column)
	: Operator("<<", first_line, last_line, first_column, last_column)
{

}

Op_LeftShift::Op_LeftShift(const NodeLocation& node_loc) : Operator("<<", node_loc)
{

}

/* Operator : >> */
Op_RightShift::Op_RightShift() : Operator(">>") { }

Op_RightShift::Op_RightShift(int first_line, int last_line, int first_column, int last_column)
	: Operator(">>", first_line, last_line, first_column, last_column)
{

}

Op_RightShift::Op_RightShift(const NodeLocation& node_loc) : Operator(">>", node_loc)
{

}

/* Operator : . */
Op_StringConcat::Op_StringConcat() : Operator(".") { }

Op_StringConcat::Op_StringConcat(int first_line, int last_line, int first_column, int last_column)
	: Operator(".", first_line, last_line, first_column, last_column)
{

}

Op_StringConcat::Op_StringConcat(const NodeLocation& node_loc) : Operator(".", node_loc)
{

}

/* Operator : ++ prefix */
Op_PrefixIncrement::Op_PrefixIncrement() : Operator("++") { }

Op_PrefixIncrement::Op_PrefixIncrement(int first_line, int last_line, int first_column, int last_column)
	: Operator("++", first_line, last_line, first_column, last_column)
{

}

Op_PrefixIncrement::Op_PrefixIncrement(const NodeLocation& node_loc) : Operator("++", node_loc)
{

}

/* Operator : -- prefix*/
Op_PrefixDecrement::Op_PrefixDecrement() : Operator("--") { }

Op_PrefixDecrement::Op_PrefixDecrement(int first_line, int last_line, int first_column, int last_column)
	: Operator("--", first_line, last_line, first_column, last_column)
{

}

Op_PrefixDecrement::Op_PrefixDecrement(const NodeLocation& node_loc) : Operator("--", node_loc)
{

}

/* Operator : ++ postfix */
Op_PostfixIncrement::Op_PostfixIncrement() : Operator("++") { }

Op_PostfixIncrement::Op_PostfixIncrement(int first_line, int last_line, int first_column, int last_column)
	: Operator("++", first_line, last_line, first_column, last_column)
{

}

Op_PostfixIncrement::Op_PostfixIncrement(const NodeLocation& node_loc) : Operator("++", node_loc)
{

}

/* Operator : -- postfix */
Op_PostfixDecrement::Op_PostfixDecrement() : Operator("--") { }

Op_PostfixDecrement::Op_PostfixDecrement(int first_line, int last_line, int first_column, int last_column)
	: Operator("--", first_line, last_line, first_column, last_column)
{

}

Op_PostfixDecrement::Op_PostfixDecrement(const NodeLocation& node_loc) : Operator("--", node_loc)
{

}

/* Operator : = */
Op_Assignment::Op_Assignment() : Operator("=") { }

Op_Assignment::Op_Assignment(int first_line, int last_line, int first_column, int last_column)
	: Operator("=", first_line, last_line, first_column, last_column)
{

}

Op_Assignment::Op_Assignment(const NodeLocation& node_loc) : Operator("=", node_loc)
{

}

/* Operator : += */
Op_AssignPlus::Op_AssignPlus() : Operator("+=") { }

Op_AssignPlus::Op_AssignPlus(int first_line, int last_line, int first_column, int last_column)
	: Operator("+=", first_line, last_line, first_column, last_column)
{

}

Op_AssignPlus::Op_AssignPlus(const NodeLocation& node_loc) : Operator("+=", node_loc)
{

}

/* Operator : -= */
Op_AssignMinus::Op_AssignMinus() : Operator("-=") { }

Op_AssignMinus::Op_AssignMinus(int first_line, int last_line, int first_column, int last_column)
	: Operator("-=", first_line, last_line, first_column, last_column)
{

}

Op_AssignMinus::Op_AssignMinus(const NodeLocation& node_loc) : Operator("-=", node_loc)
{

}

/* Operator : *= */
Op_AssignMult::Op_AssignMult() : Operator("*=") { }

Op_AssignMult::Op_AssignMult(int first_line, int last_line, int first_column, int last_column)
	: Operator("*=", first_line, last_line, first_column, last_column)
{

}

Op_AssignMult::Op_AssignMult(const NodeLocation& node_loc) : Operator("*=", node_loc)
{

}

/* Operator : /= */
Op_AssignDiv::Op_AssignDiv() : Operator("/=") { }

Op_AssignDiv::Op_AssignDiv(int first_line, int last_line, int first_column, int last_column)
	: Operator("/=", first_line, last_line, first_column, last_column)
{

}

Op_AssignDiv::Op_AssignDiv(const NodeLocation& node_loc) : Operator("/=", node_loc)
{

}

/* Operator : **= */
Op_AssignExpo::Op_AssignExpo() : Operator("**=") { }

Op_AssignExpo::Op_AssignExpo(int first_line, int last_line, int first_column, int last_column)
	: Operator("**=", first_line, last_line, first_column, last_column)
{

}

Op_AssignExpo::Op_AssignExpo(const NodeLocation& node_loc) : Operator("**=", node_loc)
{

}

/* Operator : %= */
Op_AssignMod::Op_AssignMod() : Operator("%=") { }

Op_AssignMod::Op_AssignMod(int first_line, int last_line, int first_column, int last_column)
	: Operator("%=", first_line, last_line, first_column, last_column)
{

}

Op_AssignMod::Op_AssignMod(const NodeLocation& node_loc) : Operator("%=", node_loc)
{

}

/* Operator : &= */
Op_AssignAnd::Op_AssignAnd() : Operator("&=") { }

Op_AssignAnd::Op_AssignAnd(int first_line, int last_line, int first_column, int last_column)
	: Operator("&=", first_line, last_line, first_column, last_column)
{

}

Op_AssignAnd::Op_AssignAnd(const NodeLocation& node_loc) : Operator("&=", node_loc)
{

}

/* Operator : |= */
Op_AssignOr::Op_AssignOr() : Operator("|=") { }

Op_AssignOr::Op_AssignOr(int first_line, int last_line, int first_column, int last_column)
	: Operator("|=", first_line, last_line, first_column, last_column)
{

}

Op_AssignOr::Op_AssignOr(const NodeLocation& node_loc) : Operator("|=", node_loc)
{

}

/* Operator : ^= */
Op_AssignXor::Op_AssignXor() : Operator("^=") { }

Op_AssignXor::Op_AssignXor(int first_line, int last_line, int first_column, int last_column)
	: Operator("^=", first_line, last_line, first_column, last_column)
{

}

Op_AssignXor::Op_AssignXor(const NodeLocation& node_loc) : Operator("^=", node_loc)
{

}

/* Operator : .= */
Op_AssignConcat::Op_AssignConcat() : Operator(".=") { }

Op_AssignConcat::Op_AssignConcat(int first_line, int last_line, int first_column, int last_column)
	: Operator(".=", first_line, last_line, first_column, last_column)
{

}

Op_AssignConcat::Op_AssignConcat(const NodeLocation& node_loc) : Operator(".=", node_loc)
{

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

