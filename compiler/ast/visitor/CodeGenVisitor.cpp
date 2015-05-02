#include "CodeGenVisitor.hpp"
#include "../../codegen/Variable.hpp"
#include "../../codegen/ConstantInt.hpp"

using namespace std;
using namespace visitor;
using namespace ast;
using namespace codegen;

CodeGenVisitor::CodeGenVisitor(ostream& out) : out_(out), curr_module(builder.get_curr_module()), curr_func_name("main")
{

}


/*****************************
 * 		Identifier token    *
 *****************************/

void CodeGenVisitor::visit( Identifier& token )
{
	Variable v(token.id(), "i32");
	add_return(v);
}


/*************************
 * 		Keyword token    *
 *************************/
void CodeGenVisitor::visit( K_Break& token )
{

}


void CodeGenVisitor::visit( K_Continue& token )
{

}


void CodeGenVisitor::visit( Type_Int& token )
{

}


void CodeGenVisitor::visit( Type_Float& token )
{

}


void CodeGenVisitor::visit( Type_Char& token )
{

}


void CodeGenVisitor::visit( Type_String& token )
{

}


void CodeGenVisitor::visit( Type_Array& token )
{

}


void CodeGenVisitor::visit( Type_List& token )
{

}


void CodeGenVisitor::visit( Type_Bool& token )
{

}



void CodeGenVisitor::visit( Type_Function& token )
{

}


/****************************
 * 		Operator token      *
 ****************************/

void CodeGenVisitor::visit( Op_Plus& token )
{
	visit_children(token);

	// Get 2 arguments
	Value& rhs = return_stack.top();
	Value& lhs = return_stack.top();
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();
	Value result = block.create_op_plus(lhs, rhs);

	add_return(result);

	return_stack.pop();
	return_stack.pop();
}


void CodeGenVisitor::visit( Op_Minus& token )
{

}


void CodeGenVisitor::visit( Op_Mult& token )
{

}


void CodeGenVisitor::visit( Op_Div& token )
{

}


void CodeGenVisitor::visit( Op_Modulo& token )
{

}


void CodeGenVisitor::visit( Op_Exponentiation& token )
{

}


void CodeGenVisitor::visit( Op_UnaryMinus& token )
{

}


void CodeGenVisitor::visit( Op_BitwiseOr& token )
{

}


void CodeGenVisitor::visit( Op_BitwiseAnd& token )
{

}


void CodeGenVisitor::visit( Op_BitwiseXor& token )
{

}


void CodeGenVisitor::visit( Op_BitwiseNot& token )
{

}


void CodeGenVisitor::visit( Op_LogicalOr& token )
{

}


void CodeGenVisitor::visit( Op_LogicalAnd& token )
{

}


void CodeGenVisitor::visit( Op_LogicalNot& token )
{

}


void CodeGenVisitor::visit( Op_CompLessThan& token )
{

}


void CodeGenVisitor::visit( Op_CompGreaterThan& token )
{

}


void CodeGenVisitor::visit( Op_CompLessEqual& token )
{

}


void CodeGenVisitor::visit( Op_CompGreaterEqual& token )
{

}


void CodeGenVisitor::visit( Op_CompEqual& token )
{

}


void CodeGenVisitor::visit( Op_CompNotEqual& token )
{

}


void CodeGenVisitor::visit( Op_LeftShift& token )
{

}


void CodeGenVisitor::visit( Op_RightShift& token )
{

}


void CodeGenVisitor::visit( Op_StringConcat& token )
{

}


void CodeGenVisitor::visit( Op_PrefixIncrement& token )
{

}


void CodeGenVisitor::visit( Op_PrefixDecrement& token )
{

}


void CodeGenVisitor::visit( Op_PostfixIncrement& token )
{

}


void CodeGenVisitor::visit( Op_PostfixDecrement& token )
{

}


void CodeGenVisitor::visit( Op_Assignment& token )
{

}


void CodeGenVisitor::visit( Op_AssignPlus& token )
{

}


void CodeGenVisitor::visit( Op_AssignMinus& token )
{

}


void CodeGenVisitor::visit( Op_AssignMult& token )
{

}


void CodeGenVisitor::visit( Op_AssignDiv& token )
{

}


void CodeGenVisitor::visit( Op_AssignExpo& token )
{

}


void CodeGenVisitor::visit( Op_AssignMod& token )
{

}


void CodeGenVisitor::visit( Op_AssignAnd& token )
{

}


void CodeGenVisitor::visit( Op_AssignOr& token )
{

}


void CodeGenVisitor::visit( Op_AssignXor& token )
{

}


void CodeGenVisitor::visit( Op_AssignConcat& token )
{

}


/**************************
 * 		Constant token    *
 **************************/

void CodeGenVisitor::visit( String& token )
{

}


void CodeGenVisitor::visit( Character& token )
{

}

void CodeGenVisitor::visit( Integer& token )
{
	ConstantInt constant_int(token.value());
	add_return(constant_int);
}

void CodeGenVisitor::visit( Float& token )
{

}

void CodeGenVisitor::visit( Bool& token )
{

}


/**************************************
 * 		Datastructure non-terminal    *
 **************************************/

void CodeGenVisitor::visit( Array& token )
{

}


void CodeGenVisitor::visit( List& token )
{

}


void CodeGenVisitor::visit( MakeSequenceList& token )
{

}


void CodeGenVisitor::visit( MakeSequenceArray& token )
{

}


/************************************
 * 		Declaration non-terminal    *
 ************************************/

void CodeGenVisitor::visit( DeclFunc& token )
{

}


void CodeGenVisitor::visit( DeclVars& token )
{
	visit_children(token);
}


void CodeGenVisitor::visit( DeclVar& token )
{
	visit_children(token);

	if(token.contains_expr())
	{
		// Expression
		Value expr = return_stack.top();
		return_stack.pop();

		// IDENTIFIER
		Value id = return_stack.top();
		return_stack.pop();

		BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();
		block.create_decl_var(id);

		
	}
	else
	{

		// Contains only an IDENTIFIER -> Receive a 'Variable'
		Value& id = return_stack.top();

		BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();
		block.create_decl_var(id);

		return_stack.pop();
		add_return(id);
	}

}


void CodeGenVisitor::visit( ParamList& token )
{

}


void CodeGenVisitor::visit( Param& token )
{

}



/***********************************
 * 		Expression non-terminal    *
 ***********************************/

void CodeGenVisitor::visit( Expression& token )
{
	visit_children(token);
}


void CodeGenVisitor::visit( ModifyingExpression& token )
{

}


void CodeGenVisitor::visit( DatastructureAccess& token )
{

}



/*************************************
 * 		FunctionCall non-terminal    *
 *************************************/

void CodeGenVisitor::visit( FuncCall& token )
{

}


void CodeGenVisitor::visit( ArgList& token )
{

}


void CodeGenVisitor::visit( Argument& token )
{

}


void CodeGenVisitor::visit( SoyFunc& token )
{

}



/********************************
 * 		Program non-terminal    *
 ********************************/

void CodeGenVisitor::visit( Program& token )
{
	visit_children(token);
}


void CodeGenVisitor::visit( Scope& token )
{
	visit_children(token);
}



/**********************************
 * 		Statement non-terminal    *
 **********************************/

void CodeGenVisitor::visit( Statement& token )
{

}


void CodeGenVisitor::visit( Return& token )
{

}


void CodeGenVisitor::visit( Menu& token )
{

}


void CodeGenVisitor::visit( MenuDef& token )
{

}

void CodeGenVisitor::visit( MenuCase& token )
{

}

void CodeGenVisitor::visit( Roll& token )
{

}


void CodeGenVisitor::visit( Foreach& token )
{

}


void CodeGenVisitor::visit( For& token )
{

}


void CodeGenVisitor::visit( ForInitializer& token )
{

}


void CodeGenVisitor::visit( ForUpdate& token )
{

}


void CodeGenVisitor::visit( Conditional& token )
{

}


void CodeGenVisitor::visit( Elseif& token )
{

}


/************************
 * 		Default case    *
 ************************/
void CodeGenVisitor::visit( ASTNode& token )
{
	visit_children(token);
	cout << "Unknown node" << endl;
}


void CodeGenVisitor::visit_children( ASTNode& token )
{
	for(auto child : token.get_children())
		child->accept(*this);
}


void CodeGenVisitor::print(ostream& out)
{
	builder.dump(out);
}


void CodeGenVisitor::add_return(Value& value)
{
	return_stack.push(value);
}

Value CodeGenVisitor::pop_return()
{
	Value val = return_stack.top();
	return_stack.pop();

	return val;
}

bool CodeGenVisitor::is_stack_empty() const
{
	return get_stack_size() <= 0;
}

int CodeGenVisitor::get_stack_size() const
{
	return return_stack.size();
}
