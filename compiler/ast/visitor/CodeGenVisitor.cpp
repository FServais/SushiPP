#include "CodeGenVisitor.hpp"

using namespace std;
using namespace visitor;
using namespace llvm;
using namespace error;

CodeGenVisitor::CodeGenVisitor(ErrorHandler& _error_handler, ostream& out = cout) : out_(out), builder(getGlobalContext()), error_handler(_error_handler)
{
	LLVMContext &context = getGlobalContext();
	the_module = new Module("SushiPPModule", context);
}


/*****************************
 * 		Identifier token    *
 *****************************/

void CodeGenVisitor::visit( ast::Identifier& token )
{
	// Check whether it is a variable or a function

	// If variable : return value

	// If function : ???

	// Else : error

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
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// Get type

	// Integer
	//return builder.CreateAdd(lhs, rhs);
	// Float
	//return builder.CreateFAdd(lhs, rhs);

}


void CodeGenVisitor::visit( ast::Op_Minus& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// Get type

	// Integer
	//return builder.CreateSub(lhs, rhs);
	// Float
	//return builder.CreateFSub(lhs, rhs);

}


void CodeGenVisitor::visit( ast::Op_Mult& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// Get type

	// Integer
	//return builder.CreateMul(lhs, rhs);
	// Float
	//return builder.CreateFMul(lhs, rhs);

}


void CodeGenVisitor::visit( ast::Op_Div& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// Get type

}


void CodeGenVisitor::visit( ast::Op_Modulo& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// ???
}


void CodeGenVisitor::visit( ast::Op_Exponentiation& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// ???
}


void CodeGenVisitor::visit( ast::Op_UnaryMinus& token )
{
	token.get_operand().accept(*this);

	Value* value = return_stack.top();
	return_stack.pop();

	if(value == 0) return 0;

	// Get type

	// Integer
	//return builder.CreateSub(0, value);
	// Float
	//return builder.CreateFSub(0, value);
}


void CodeGenVisitor::visit( ast::Op_BitwiseOr& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	//return builder.CreateOr(lhs, rhs);
}


void CodeGenVisitor::visit( ast::Op_BitwiseAnd& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	//return builder.CreateAnd(lhs, rhs);
}


void CodeGenVisitor::visit( ast::Op_BitwiseXor& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	//return builder.CreateXor(lhs, rhs);
}


void CodeGenVisitor::visit( ast::Op_BitwiseNot& token )
{
	token.get_operand().accept(*this);

	Value* value = return_stack.top();
	return_stack.pop();

	if(value == 0) return 0;

	//return builder.CreateNot(lhs, value); ???
}


void CodeGenVisitor::visit( ast::Op_LogicalOr& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// CreateOr : bitwise or logical?
	// return builder.CreateOr(lhs, rhs);
}


void CodeGenVisitor::visit( ast::Op_LogicalAnd& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// CreateOr : bitwise or logical?
	// return builder.CreateOr(lhs, rhs);
}


void CodeGenVisitor::visit( ast::Op_LogicalNot& token )
{
	token.get_operand().accept(*this);

	Value* value = return_stack.top();
	return_stack.pop();

	if(value == 0) return 0;

	//return builder.CreateNot(lhs, value);

}


void CodeGenVisitor::visit( ast::Op_CompLessThan& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// Get type

	// Integer
	// return builder.CreateICmpSLT(lhs, rhs);

	// Float
	// return builder.CreateFCmpOLT(lhs, rhs);

}


void CodeGenVisitor::visit( ast::Op_CompGreaterThan& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// Get type

	// Integer
	// return builder.CreateICmpSGT(lhs, rhs);

	// Float
	// return builder.CreateFCmpOGT(lhs, rhs);
}


void CodeGenVisitor::visit( ast::Op_CompLessEqual& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// Get type

	// Integer
	// return builder.CreateICmpSLE(lhs, rhs);

	// Float
	// return builder.CreateFCmpOLE(lhs, rhs);
}


void CodeGenVisitor::visit( ast::Op_CompGreaterEqual& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// Get type

	// Integer
	// return builder.CreateICmpSGE(lhs, rhs);

	// Float
	// return builder.CreateFCmpOGE(lhs, rhs);
}


void CodeGenVisitor::visit( ast::Op_CompEqual& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// Get type

	// Integer
	// return builder.CreateICmpEQ(lhs, rhs);

	// Float
	// return builder.CreateFCmpOEQ(lhs, rhs);
}


void CodeGenVisitor::visit( ast::Op_CompNotEqual& token )
{
	token.get_right_operand().accept(*this);
	token.get_left_operand().accept(*this);

	Value* lhs = return_stack.top();
	return_stack.pop();

	Value* rhs = return_stack.top();
	return_stack.pop();

	if(lhs == 0 || rhs == 0) return 0;

	// Get type

	// Integer
	// return builder.CreateICmpNEQ(lhs, rhs);

	// Float
	// return builder.CreateFCmpONEQ(lhs, rhs);
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
	// Unsigned 8-bit integer = char
	return_stack.push(ConstantInt::get(getGlobalContext(), APInt(8, token.value(), false)));
}

void CodeGenVisitor::visit( ast::Integer& token )
{
	return_stack.push(ConstantInt::get(getGlobalContext(), APInt(32, token.value(), true)));
}

void CodeGenVisitor::visit( ast::Float& token )
{
	return_stack.push(ConstantFP::get(getGlobalContext(), APFloat(token.value())));
}

void CodeGenVisitor::visit( ast::Bool& token )
{
	if(token.value())
		return_stack.push(ConstantInt::getTrue(getGlobalContext());
	else
		return_stack.push(ConstantInt::getFalse(getGlobalContext());
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
