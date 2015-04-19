#ifndef ASTVisitor_HPP_DEFINED
#define ASTVisitor_HPP_DEFINED

#include "../nodes/ASTNode.hpp"

#include "../nodes/tokens/ConstantToken.hpp"
#include "../nodes/tokens/Keyword.hpp"
#include "../nodes/tokens/Operator.hpp"
#include "../nodes/tokens/Token.hpp"

#include "../nodes/nonterminal/NT_Constant.hpp"
#include "../nodes/nonterminal/NT_Datastructure.hpp"
#include "../nodes/nonterminal/NT_Declaration.hpp"
#include "../nodes/nonterminal/NT_Expression.hpp"
#include "../nodes/nonterminal/NT_FunctionCall.hpp"
#include "../nodes/nonterminal/NT_Program.hpp"
#include "../nodes/nonterminal/NT_Statement.hpp"
#include "../nodes/nonterminal/NonTerminal.hpp"

class ASTVisitor
{
public:

	virtual void visit( ast::ASTNode& ) = 0;

	/******************************
	 * 		Identifier token    *
	 ******************************/
	 
	virtual void visit( ast::Identifier& ) = 0;

	/*************************
	 * 		Keyword token    *
	 *************************/

	virtual void visit( ast::K_Continue& ) = 0;
	virtual void visit( ast::K_Break& ) = 0;
	virtual void visit( ast::Type_Int& ) = 0;
	virtual void visit( ast::Type_Float& ) = 0;
	virtual void visit( ast::Type_Char& ) = 0;
	virtual void visit( ast::Type_String& ) = 0;
	virtual void visit( ast::Type_Array& ) = 0;
	virtual void visit( ast::Type_List& ) = 0;
	virtual void visit( ast::Type_Bool& ) = 0;

	/**************************
	 * 		Operator token    *
	 **************************/
	
	virtual void visit( ast::Op_Plus& ) = 0;
	virtual void visit( ast::Op_Minus& ) = 0;
	virtual void visit( ast::Op_Mult& ) = 0;
	virtual void visit( ast::Op_Div& ) = 0;
	virtual void visit( ast::Op_Modulo& ) = 0;
	virtual void visit( ast::Op_Exponentiation& ) = 0;
	virtual void visit( ast::Op_UnaryMinus& ) = 0;
	virtual void visit( ast::Op_BitwiseOr& ) = 0;
	virtual void visit( ast::Op_BitwiseAnd& ) = 0;
	virtual void visit( ast::Op_BitwiseXor& ) = 0;
	virtual void visit( ast::Op_BitwiseNot& ) = 0;
	virtual void visit( ast::Op_LogicalOr& ) = 0;
	virtual void visit( ast::Op_LogicalAnd& ) = 0;
	virtual void visit( ast::Op_LogicalNot& ) = 0;
	virtual void visit( ast::Op_CompLessThan& ) = 0;
	virtual void visit( ast::Op_CompGreaterThan& ) = 0;
	virtual void visit( ast::Op_CompLessEqual& ) = 0;
	virtual void visit( ast::Op_CompGreaterEqual& ) = 0;
	virtual void visit( ast::Op_CompEqual& ) = 0;
	virtual void visit( ast::Op_CompNotEqual& ) = 0;
	virtual void visit( ast::Op_LeftShift& ) = 0;
	virtual void visit( ast::Op_RightShift& ) = 0;
	virtual void visit( ast::Op_StringConcat& ) = 0;
	virtual void visit( ast::Op_PrefixIncrement& ) = 0;
	virtual void visit( ast::Op_PrefixDecrement& ) = 0;
	virtual void visit( ast::Op_PostfixIncrement& ) = 0;
	virtual void visit( ast::Op_PostfixDecrement& ) = 0;
	virtual void visit( ast::Op_Assignment& ) = 0;
	virtual void visit( ast::Op_AssignPlus& ) = 0;
	virtual void visit( ast::Op_AssignMinus& ) = 0;
	virtual void visit( ast::Op_AssignMult& ) = 0;
	virtual void visit( ast::Op_AssignDiv& ) = 0;
	virtual void visit( ast::Op_AssignExpo& ) = 0;
	virtual void visit( ast::Op_AssignMod& ) = 0;
	virtual void visit( ast::Op_AssignAnd& ) = 0;
	virtual void visit( ast::Op_AssignOr& ) = 0;
	virtual void visit( ast::Op_AssignXor& ) = 0;
	virtual void visit( ast::Op_AssignConcat& ) = 0;
	
	/**************************
	 * 		Constant token    *
	 **************************/

	virtual void visit( ast::String& ) = 0;
	virtual void visit( ast::Character& ) = 0;
	virtual void visit( ast::Integer& ) = 0;
	virtual void visit( ast::Float& ) = 0;
	virtual void visit( ast::Bool& ) = 0;

	/**************************************
	 * 		Datastructure non-terminal    *
	 **************************************/

	virtual void visit( ast::Array& ) = 0;
	virtual void visit( ast::List& ) = 0;
	virtual void visit( ast::MakeSequenceList& ) = 0;
	virtual void visit( ast::MakeSequenceArray& ) = 0;

	/************************************
	 * 		Declaration non-terminal    *
	 ************************************/

	virtual void visit( ast::DeclFunc& ) = 0;
	virtual void visit( ast::DeclVars& ) = 0;
	virtual void visit( ast::DeclVar& ) = 0;
	virtual void visit( ast::ParamList& ) = 0;
	virtual void visit( ast::Param& ) = 0;

	/***********************************
	 * 		Expression non-terminal    *
	 ***********************************/

	virtual void visit( ast::Expression& ) = 0;
	virtual void visit( ast::ModifyingExpression& ) = 0;
	virtual void visit( ast::DatastructureAccess& ) = 0;

	/*************************************
	 * 		FunctionCall non-terminal    *
	 *************************************/

	virtual void visit( ast::FuncCall& ) = 0;
	virtual void visit( ast::ArgList& ) = 0;
	virtual void visit( ast::Argument& ) = 0;
	virtual void visit( ast::SoyFunc& ) = 0;

	/********************************
	 * 		Program non-terminal    *
	 ********************************/

	virtual void visit( ast::Program& ) = 0;
	virtual void visit( ast::Scope& ) = 0;

	/**********************************
	 * 		Statement non-terminal    *
	 **********************************/

	virtual void visit( ast::Statement& ) = 0;
	virtual void visit( ast::Return& ) = 0;
	virtual void visit( ast::Menu& ) = 0;
	virtual void visit( ast::MenuDef& ) = 0;
	virtual void visit( ast::Roll& ) = 0;
	virtual void visit( ast::Foreach& ) = 0;
	virtual void visit( ast::For& ) = 0;
	virtual void visit( ast::ForInitializer& ) = 0;
	virtual void visit( ast::ForUpdate& ) = 0;
	virtual void visit( ast::Conditional& ) = 0;
	virtual void visit( ast::Elseif& ) = 0;

};

#endif
