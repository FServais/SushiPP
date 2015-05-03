#include "CodeGenVisitor.hpp"

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
	Variable* v = new Variable(token.id(), "i32");

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
	Value& rhs = get_return_value(0);
	Value& lhs = get_return_value(1);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	Variable* result;

    if(lhs.is_variable() && rhs.is_variable())
    {
        unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_plus(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_plus(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_plus(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_plus(lhs, rhs));

	pop();
	pop();

	add_return(result);
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
	ConstantInt* constant_int = new ConstantInt(token.value());
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
	auto child = token.get_children().begin();
	// Visit 1st child : Identifier
	
	// Create new FunctionBlock

	// Visit 2nd child (ParameterList: visit all children and add argument for each)

	// Change "cursor" of the visitor to the new function

	// Fullfill it through the visit of the children

	// Get back to previous block
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
		Value& expr = get_return_value(0);

		// IDENTIFIER
		Value& id = get_return_value(1);

		BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

		// Allocate in memory
		unique_ptr<Value> lhs = unique_ptr<Value>(block.create_decl_var(id));

		// Store temp variable in location of the pointer
		unique_ptr<Value> store = unique_ptr<Value>(block.create_store(expr, *lhs));

		pop();
		pop();

		//add_return(store);
	}
	else
	{
		// Contains only an IDENTIFIER -> Receive a 'Variable'
		Value& id = top();

		BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();
		block.create_decl_var(id);

		Variable& var = dynamic_cast<Variable&>(id);
		Variable* id_ptr = new Variable(var);

		pop();

		//add_return(id_ptr);
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



/************************
 * 		   Vector       *
 ************************/

void CodeGenVisitor::add_return(Value* value)
{
	return_vector.push_back(unique_ptr<Value>(value));
}


Value& CodeGenVisitor::top()
{
	return *(return_vector[return_vector.size()-1]);
}

void CodeGenVisitor::pop()
{
	return_vector.erase(return_vector.begin()+return_vector.size()-1);
}


Value& CodeGenVisitor::get_return_value(int n)
{
	return *(return_vector.at(return_vector.size()-1-n));
}

void CodeGenVisitor::remove_return_value(int n)
{
	return_vector.erase(return_vector.begin()+return_vector.size()-1-n);
}




bool CodeGenVisitor::is_vector_empty() const
{
	return get_vector_size() <= 0;
}

int CodeGenVisitor::get_vector_size() const
{
	return return_vector.size();
}
