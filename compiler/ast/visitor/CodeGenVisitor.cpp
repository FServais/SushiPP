#include "CodeGenVisitor.hpp"

using namespace std;
using namespace visitor;
using namespace llvm;

CodeGenVisitor::CodeGenVisitor() : out_(cout), builder(getGlobalContext())
{
	LLVMContext &context = getGlobalContext();
	the_module = new Module("SushiPPModule", context);

}

CodeGenVisitor::CodeGenVisitor(std::ostream& out) : out_(out), builder(getGlobalContext())
{
	LLVMContext &context = getGlobalContext();
	the_module = new Module("SushiPPModule", context);

}


/*****************************
 * 		Identifier token    *
 *****************************/

void CodeGenVisitor::visit( ast::Identifier& token )
{

}


/*************************
 * 		Keyword token    *
 *************************/
void CodeGenVisitor::visit( ast::K_Break& token )
{

}


void CodeGenVisitor::visit( ast::K_Continue& token )
{

}


void CodeGenVisitor::visit( ast::Type_Int& token )
{

}


void CodeGenVisitor::visit( ast::Type_Float& token )
{

}


void CodeGenVisitor::visit( ast::Type_Char& token )
{

}


void CodeGenVisitor::visit( ast::Type_String& token )
{

}


void CodeGenVisitor::visit( ast::Type_Array& token )
{

}


void CodeGenVisitor::visit( ast::Type_List& token )
{

}


void CodeGenVisitor::visit( ast::Type_Bool& token )
{

}



void CodeGenVisitor::visit( ast::Type_Function& token )
{

}


/****************************
 * 		Operator token      *
 ****************************/

void CodeGenVisitor::visit( ast::Op_Plus& token )
{

}


void CodeGenVisitor::visit( ast::Op_Minus& token )
{

}


void CodeGenVisitor::visit( ast::Op_Mult& token )
{

}


void CodeGenVisitor::visit( ast::Op_Div& token )
{

}


void CodeGenVisitor::visit( ast::Op_Modulo& token )
{

}


void CodeGenVisitor::visit( ast::Op_Exponentiation& token )
{

}


void CodeGenVisitor::visit( ast::Op_UnaryMinus& token )
{

}


void CodeGenVisitor::visit( ast::Op_BitwiseOr& token )
{

}


void CodeGenVisitor::visit( ast::Op_BitwiseAnd& token )
{

}


void CodeGenVisitor::visit( ast::Op_BitwiseXor& token )
{

}


void CodeGenVisitor::visit( ast::Op_BitwiseNot& token )
{

}


void CodeGenVisitor::visit( ast::Op_LogicalOr& token )
{

}


void CodeGenVisitor::visit( ast::Op_LogicalAnd& token )
{

}


void CodeGenVisitor::visit( ast::Op_LogicalNot& token )
{

}


void CodeGenVisitor::visit( ast::Op_CompLessThan& token )
{

}


void CodeGenVisitor::visit( ast::Op_CompGreaterThan& token )
{

}


void CodeGenVisitor::visit( ast::Op_CompLessEqual& token )
{

}


void CodeGenVisitor::visit( ast::Op_CompGreaterEqual& token )
{

}


void CodeGenVisitor::visit( ast::Op_CompEqual& token )
{

}


void CodeGenVisitor::visit( ast::Op_CompNotEqual& token )
{

}


void CodeGenVisitor::visit( ast::Op_LeftShift& token )
{

}


void CodeGenVisitor::visit( ast::Op_RightShift& token )
{

}


void CodeGenVisitor::visit( ast::Op_StringConcat& token )
{

}


void CodeGenVisitor::visit( ast::Op_PrefixIncrement& token )
{

}


void CodeGenVisitor::visit( ast::Op_PrefixDecrement& token )
{

}


void CodeGenVisitor::visit( ast::Op_PostfixIncrement& token )
{

}


void CodeGenVisitor::visit( ast::Op_PostfixDecrement& token )
{

}


void CodeGenVisitor::visit( ast::Op_Assignment& token )
{

}


void CodeGenVisitor::visit( ast::Op_AssignPlus& token )
{

}


void CodeGenVisitor::visit( ast::Op_AssignMinus& token )
{

}


void CodeGenVisitor::visit( ast::Op_AssignMult& token )
{

}


void CodeGenVisitor::visit( ast::Op_AssignDiv& token )
{

}


void CodeGenVisitor::visit( ast::Op_AssignExpo& token )
{

}


void CodeGenVisitor::visit( ast::Op_AssignMod& token )
{

}


void CodeGenVisitor::visit( ast::Op_AssignAnd& token )
{

}


void CodeGenVisitor::visit( ast::Op_AssignOr& token )
{

}


void CodeGenVisitor::visit( ast::Op_AssignXor& token )
{

}


void CodeGenVisitor::visit( ast::Op_AssignConcat& token )
{

}


/**************************
 * 		Constant token    *
 **************************/

void CodeGenVisitor::visit( ast::String& token )
{

}


void CodeGenVisitor::visit( ast::Character& token )
{

}

void CodeGenVisitor::visit( ast::Integer& token )
{
	if(token.value())
		return_stack.push(ConstantInt::getTrue(getGlobalContext());
	else
		return_stack.push(ConstantInt::getFalse(getGlobalContext());
}

void CodeGenVisitor::visit( ast::Float& token )
{
	return_stack.push(ConstantFP::get(getGlobalContext(), APFloat(token.value())));
}

void CodeGenVisitor::visit( ast::Bool& token )
{
	return_stack.push(ConstantInt::get(getGlobalContext(), APInt(32, token.value(), true)));
}


/**************************************
 * 		Datastructure non-terminal    *
 **************************************/

void CodeGenVisitor::visit( ast::Array& token )
{

}


void CodeGenVisitor::visit( ast::List& token )
{

}


void CodeGenVisitor::visit( ast::MakeSequenceList& token )
{

}


void CodeGenVisitor::visit( ast::MakeSequenceArray& token )
{

}


/************************************
 * 		Declaration non-terminal    *
 ************************************/

void CodeGenVisitor::visit( ast::DeclFunc& token )
{

}


void CodeGenVisitor::visit( ast::DeclVars& token )
{

}


void CodeGenVisitor::visit( ast::DeclVar& token )
{

}


void CodeGenVisitor::visit( ast::ParamList& token )
{

}


void CodeGenVisitor::visit( ast::Param& token )
{

}



/***********************************
 * 		Expression non-terminal    *
 ***********************************/

void CodeGenVisitor::visit( ast::Expression& token )
{

}


void CodeGenVisitor::visit( ast::ModifyingExpression& token )
{

}


void CodeGenVisitor::visit( ast::DatastructureAccess& token )
{

}



/*************************************
 * 		FunctionCall non-terminal    *
 *************************************/

void CodeGenVisitor::visit( ast::FuncCall& token )
{

}


void CodeGenVisitor::visit( ast::ArgList& token )
{

}


void CodeGenVisitor::visit( ast::Argument& token )
{

}


void CodeGenVisitor::visit( ast::SoyFunc& token )
{

}



/********************************
 * 		Program non-terminal    *
 ********************************/

void CodeGenVisitor::visit( ast::Program& token )
{

}


void CodeGenVisitor::visit( ast::Scope& token )
{

}



/**********************************
 * 		Statement non-terminal    *
 **********************************/

void CodeGenVisitor::visit( ast::Statement& token )
{

}


void CodeGenVisitor::visit( ast::Return& token )
{

}


void CodeGenVisitor::visit( ast::Menu& token )
{

}


void CodeGenVisitor::visit( ast::MenuDef& token )
{

}

void CodeGenVisitor::visit( ast::MenuCase& token )
{

}

void CodeGenVisitor::visit( ast::Roll& token )
{

}


void CodeGenVisitor::visit( ast::Foreach& token )
{

}


void CodeGenVisitor::visit( ast::For& token )
{

}


void CodeGenVisitor::visit( ast::ForInitializer& token )
{

}


void CodeGenVisitor::visit( ast::ForUpdate& token )
{

}


void CodeGenVisitor::visit( ast::Conditional& token )
{

}


void CodeGenVisitor::visit( ast::Elseif& token )
{

}


/************************
 * 		Default case    *
 ************************/
void CodeGenVisitor::visit( ast::ASTNode& token )
{

}
