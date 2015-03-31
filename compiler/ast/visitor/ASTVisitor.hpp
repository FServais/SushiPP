
#ifndef __visitor__ASTVisitor__
#define __visitor__ASTVisitor__

#inclde "../nodes/ASTNode.hpp"

#include "../nodes/tokens/ConstantToken.cpp"
#include "../nodes/tokens/Delimiter.cpp"
#include "../nodes/tokens/Keyword.cpp"
#include "../nodes/tokens/Operator.cpp"
#include "../nodes/tokens/Token.cpp"

#include "../nodes/nonterminal/NT_Constant.cpp"
#include "../nodes/nonterminal/NT_Datastructure.cpp"
#include "../nodes/nonterminal/NT_Declaration.cpp"
#include "../nodes/nonterminal/NT_Expression.cpp"
#include "../nodes/nonterminal/NT_FunctionCall.cpp"
#include "../nodes/nonterminal/NT_Program.cpp"
#include "../nodes/nonterminal/NT_Statement.cpp"
#include "../nodes/nonterminal/NonTerminal.cpp"

class ASTVisitor
{
public:

	virtual ASTVisitor() = 0;

	/*****************************
	 * 		Nonterminal/token    *
	 *****************************/
	virtual void visit( ast::NonTerminal& );
	virtual void visit( ast::Token& );

	/******************************
	 * 		Identifier token    *
	 ******************************/
	virtual void visit( ast::Identifier& );

	/*************************
	 * 		Keyword token    *
	 *************************/
	virtual void visit( ast::Keyword& );

	virtual void visit( ast::K_Maki& );
	virtual void visit( ast::K_To& );
	virtual void visit( ast::K_Soy& );
	virtual void visit( ast::K_Nori& );
	virtual void visit( ast::K_Menu& );
	virtual void visit( ast::K_For& );
	virtual void visit( ast::K_Roll& );
	virtual void visit( ast::K_Break& );
	virtual void visit( ast::K_Continue& );
	virtual void visit( ast::K_Foreach& );
	virtual void visit( ast::K_As& );
	virtual void visit( ast::K_If& );
	virtual void visit( ast::K_Elseif& );
	virtual void visit( ast::K_Else& );
	virtual void visit( ast::Type_Int& );
	virtual void visit( ast::Type_Float& );
	virtual void visit( ast::Type_Char& );
	virtual void visit( ast::Type_String& );
	virtual void visit( ast::Type_Array& );
	virtual void visit( ast::Type_List& );
	virtual void visit( ast::Type_Tuple& );
	virtual void visit( ast::Type_Bool& );

	/**************************
	 * 		Operator token    *
	 **************************/
	virtual void visit( ast::Operator& );

	virtual void visit( ast::Op_Plus& );
	virtual void visit( ast::Op_Minus& );
	virtual void visit( ast::Op_Mult& );
	virtual void visit( ast::Op_Div& );
	virtual void visit( ast::Op_Modulo& );
	virtual void visit( ast::Op_Exponentiation& );
	virtual void visit( ast::Op_UnaryMinus& );
	virtual void visit( ast::Op_BitwiseOr& );
	virtual void visit( ast::Op_BitwiseAnd& );
	virtual void visit( ast::Op_BitwiseXor& );
	virtual void visit( ast::Op_BitwiseNot& );
	virtual void visit( ast::Op_LogicalOr& );
	virtual void visit( ast::Op_LogicalAnd& );
	virtual void visit( ast::Op_LogicalNot& );
	virtual void visit( ast::Op_CompLessThan& );
	virtual void visit( ast::Op_CompGreaterThan& );
	virtual void visit( ast::Op_CompLessEqual& );
	virtual void visit( ast::Op_CompGreaterEqual& );
	virtual void visit( ast::Op_CompEqual& );
	virtual void visit( ast::Op_CompNotEqual& );
	virtual void visit( ast::Op_LeftShift& );
	virtual void visit( ast::Op_RightShift& );
	virtual void visit( ast::Op_StringConcat& );
	virtual void visit( ast::Op_PrefixIncrement& );
	virtual void visit( ast::Op_PrefixDecrement& );
	virtual void visit( ast::Op_PostfixIncrement& );
	virtual void visit( ast::Op_PostfixDecrement& );
	virtual void visit( ast::Op_Assignment& );
	virtual void visit( ast::Op_AssignPlus& );
	virtual void visit( ast::Op_AssignLess& );
	virtual void visit( ast::Op_AssignMult& );
	virtual void visit( ast::Op_AssignDiv& );
	virtual void visit( ast::Op_AssignExpo& );
	virtual void visit( ast::Op_AssignMod& );
	virtual void visit( ast::Op_AssignAnd& );
	virtual void visit( ast::Op_AssignOr& );
	virtual void visit( ast::Op_AssignXor& );
	virtual void visit( ast::Op_AssignConcat& );
	
	/**************************
	 * 		Delimiter token    *
	 **************************/
	virtual void visit( ast::Delimiter& );

	virtual void visit( ast::DelimEol& );
	virtual void visit( ast::DelimEos& );
	virtual void visit( ast::TupleBeg& );
	virtual void visit( ast::TupleEnd& );
	virtual void visit( ast::ArrayBeg& );
	virtual void visit( ast::ArrayEnd& );
	virtual void visit( ast::Arrow& );
	virtual void visit( ast::Virg& );
	virtual void visit( ast::OpenPar& );
	virtual void visit( ast::ClosingPar& );
	virtual void visit( ast::OpenBrace& );
	virtual void visit( ast::ClosingBrace& );
	virtual void visit( ast::OpenAcc& );
	virtual void visit( ast::ClosingAcc& );
	virtual void visit( ast::Underscore& );
	
	/**************************
	 * 		Constant token    *
	 **************************/
	virtual void visit( ast::ConstantToken& );

	virtual void visit( ast::String& );
	virtual void visit( ast::Character& );
	virtual void visit( ast::Integer& );
	virtual void visit( ast::Float& );
	virtual void visit( ast::Bool& );


	/*********************************
	 * 		Constant non-terminal    *
	 *********************************/
	virtual void visit( ast::NT_Constant& );

	/**************************************
	 * 		Datastructure non-terminal    *
	 **************************************/
	virtual void visit( ast::NT_Datastructure& );

	virtual void visit( ast::Datastructure& );
	virtual void visit( ast::Array& );
	virtual void visit( ast::List& );
	virtual void visit( ast::Tuple& );
	virtual void visit( ast::MakeSequence& );
	virtual void visit( ast::MakeSequenceList& );
	virtual void visit( ast::MakeSequenceArray& );
	virtual void visit( ast::SeqExpression& );

	/************************************
	 * 		Declaration non-terminal    *
	 ************************************/
	virtual void visit( ast::NT_Declaration& );

	virtual void visit( ast::Declaration& );
	virtual void visit( ast::DeclFunc& );
	virtual void visit( ast::DeclVars& );
	virtual void visit( ast::DeclVar& );
	virtual void visit( ast::ParamList& );
	virtual void visit( ast::Param& );

	/***********************************
	 * 		Expression non-terminal    *
	 ***********************************/
	virtual void visit( ast::NT_Expression& );

	virtual void visit( ast::Expression& );
	virtual void visit( ast::IncrExpression& );
	virtual void visit( ast::Assignment& );
	virtual void visit( ast::ModifyingExpression& );
	virtual void visit( ast::AssignableExpression& );
	virtual void visit( ast::DatastructureAccess& );

	/*************************************
	 * 		FunctionCall non-terminal    *
	 *************************************/
	virtual void visit( ast::NT_FunctionCall& );

	virtual void visit( ast::FuncCall& );
	virtual void visit( ast::ArgList& );
	virtual void visit( ast::Argument& );
	virtual void visit( ast::BracedFuncCall& );
	virtual void visit( ast::FuncCallEol& );
	virtual void visit( ast::ArgListEol& );
	virtual void visit( ast::SoyExpression& );
	virtual void visit( ast::SoyFunc& );

	/********************************
	 * 		Program non-terminal    *
	 ********************************/
	virtual void visit( ast::NT_Program& );

	virtual void visit( ast::Program& );
	virtual void visit( ast::ScopeBody& );
	virtual void visit( ast::ProgramElement& );
	virtual void visit( ast::Scope& );

	/**********************************
	 * 		Statement non-terminal    *
	 **********************************/
	virtual void visit( ast::NT_Statement& );

	virtual void visit( ast::Statement& );
	virtual void visit( ast::Return& );
	virtual void visit( ast::Menu& );
	virtual void visit( ast::MenuDef& );
	virtual void visit( ast::Loop& );
	virtual void visit( ast::Roll& );
	virtual void visit( ast::Foreach& );
	virtual void visit( ast::For& );
	virtual void visit( ast::ForInitializer& );
	virtual void visit( ast::ForUpdate& );
	virtual void visit( ast::Conditional& );
	virtual void visit( ast::Elseif& );

protected:
	int depth;

};

#endif
