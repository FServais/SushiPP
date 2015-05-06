#include "CodeGenVisitor.hpp"

using namespace std;
using namespace visitor;
using namespace ast;
using namespace codegen;
using namespace symb;
using namespace inference;

CodeGenVisitor::CodeGenVisitor(SymbolTable<VariableInfo>& _variable_table, SymbolTable<FunctionInfo>& _function_table, TypeSymbolTable& _type_table) : curr_module(builder.get_curr_module()), curr_func_name("main"), variable_table(_variable_table), function_table(_function_table), type_table(_type_table)
{

}


/*****************************
 * 		Identifier token    *
 *****************************/

void CodeGenVisitor::visit( Identifier& token )
{
	string name = type_table.unique_id_name(function_table.get_curr_scope_id(), token.id());
	shared_ptr<typegen::Type> type = type_table.get_type(name);

	Variable* v = new Variable(builder.get_variable_manager(), token.id(), type, true);
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


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));

	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_Minus& token )
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
		result = dynamic_cast<Variable*>(block.create_op_minus(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_minus(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_minus(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_minus(lhs, rhs));


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));

	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_Mult& token )
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
		result = dynamic_cast<Variable*>(block.create_op_mult(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_mult(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_mult(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_mult(lhs, rhs));


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_Div& token )
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
		result = dynamic_cast<Variable*>(block.create_op_div(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_div(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_div(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_div(lhs, rhs));


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_Modulo& token )
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
		result = dynamic_cast<Variable*>(block.create_op_mod(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_mod(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_mod(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_mod(lhs, rhs));


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_Exponentiation& token )
{

}


void CodeGenVisitor::visit( Op_UnaryMinus& token )
{
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	Variable* result;

    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_unminus( *(load_rhs)));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_unminus(rhs));


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_BitwiseOr& token )
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
		result = dynamic_cast<Variable*>(block.create_op_bit_or(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_bit_or(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_bit_or(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_bit_or(lhs, rhs));


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_BitwiseAnd& token )
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
		result = dynamic_cast<Variable*>(block.create_op_bit_and(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_bit_and(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_bit_and(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_bit_and(lhs, rhs));


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_BitwiseXor& token )
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
		result = dynamic_cast<Variable*>(block.create_op_bit_xor(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_bit_xor(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_bit_xor(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_bit_xor(lhs, rhs));


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_BitwiseNot& token )
{
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	Variable* result;

    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_bit_not( *(load_rhs)));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_bit_not(rhs));


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_LogicalOr& token )
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
		result = dynamic_cast<Variable*>(block.create_op_log_or(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_log_or(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_log_or(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_log_or(lhs, rhs));


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_LogicalAnd& token )
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
		result = dynamic_cast<Variable*>(block.create_op_log_and(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_log_and(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_log_and(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_log_and(lhs, rhs));


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_LogicalNot& token )
{
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	Variable* result;

    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_log_not( *(load_rhs)));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_log_not(rhs));


	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_CompLessThan& token )
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
		result = dynamic_cast<Variable*>(block.create_op_cmp_lt(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_cmp_lt(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_cmp_lt(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_cmp_lt(lhs, rhs));

	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_CompGreaterThan& token )
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
		result = dynamic_cast<Variable*>(block.create_op_cmp_gt(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_cmp_gt(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_cmp_gt(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_cmp_gt(lhs, rhs));

	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_CompLessEqual& token )
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
		result = dynamic_cast<Variable*>(block.create_op_cmp_le(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_cmp_le(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_cmp_le(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_cmp_le(lhs, rhs));

	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_CompGreaterEqual& token )
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
		result = dynamic_cast<Variable*>(block.create_op_cmp_ge(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_cmp_ge(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_cmp_ge(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_cmp_ge(lhs, rhs));

	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_CompEqual& token )
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
		result = dynamic_cast<Variable*>(block.create_op_cmp_eq(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_cmp_eq(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_cmp_eq(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_cmp_eq(lhs, rhs));

	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_CompNotEqual& token )
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
		result = dynamic_cast<Variable*>(block.create_op_cmp_neq(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_cmp_neq(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_cmp_neq(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_cmp_neq(lhs, rhs));

	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_LeftShift& token )
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
		result = dynamic_cast<Variable*>(block.create_op_left_shift(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_left_shift(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_left_shift(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_left_shift(lhs, rhs));

	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_RightShift& token )
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
		result = dynamic_cast<Variable*>(block.create_op_right_shift(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant()){
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_right_shift(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_right_shift(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_right_shift(lhs, rhs));

	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));



	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
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
	visit_children(token);


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

void CodeGenVisitor::visit( ast::String& token )
{
	ConstantString* constant_string = new ConstantString(token.value());
	add_return(constant_string);
}


void CodeGenVisitor::visit( Character& token )
{
	ConstantChar* constant_char = new ConstantChar(token.value());
	add_return(constant_char);
}

void CodeGenVisitor::visit( Integer& token )
{
	ConstantInt* constant_int = new ConstantInt(token.value());
	add_return(constant_int);
}

void CodeGenVisitor::visit( ast::Float& token )
{
	ConstantFloat* constant_float = new ConstantFloat(token.value());
	add_return(constant_float);
}

void CodeGenVisitor::visit( ast::Bool& token )
{
	ConstantBool* constant_bool = new ConstantBool(token.value());
	add_return(constant_bool);
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
	int index = 0;

	// Visit 1st child : Identifier
	token.get_children().at(index)->accept(*this);

	Value& id = get_return_value(0);
	Variable& id_var = dynamic_cast<Variable&>(id);

	// Create new FunctionBlock
	string func_name_table = type_table.unique_id_name(function_table.get_curr_scope_id(), id_var.get_name());

	//typegen::Function* function_type = ;

	FunctionBlock function(builder.get_variable_manager(), id_var.get_name(), shared_ptr<typegen::Type>(dynamic_cast<typegen::Function*>(type_table.get_type(func_name_table).get())->get_ret_type()) );
	pop();

	// Visit 2nd child (ParameterList: visit all children and add argument for each)
	if(token.contains_params())
	{
		++index;
		function_table.move_to_scope(token.get_scope().get_scope_id());
		token.get_children().at(index)->accept(*this);
		function_table.move_to_parent_scope();
		ParamList* paramlist = dynamic_cast<ParamList*>(token.get_children().at(index));

		vector<Value*> params = get_n_return_values(paramlist->nb_params());
		for(auto param = params.rbegin() ; param != params.rend() ; ++param)
		{
			Variable* param_var = dynamic_cast<Variable*>(*param);
			function.add_argument(shared_ptr<typegen::Type>(dynamic_cast<typegen::Function*>(type_table.get_type(func_name_table).get())->get_arg(distance(params.rbegin(), param))), param_var->get_name());
		}

		pop_n_return_values(paramlist->nb_params());

	}

	// Change "cursor" of the visitor to the new function
	string current_function = curr_func_name;
	curr_func_name = function.get_name();
	curr_module.add_function(function);

	// Fullfill it through the visit of the children
	++index;
	token.get_children().at(index)->accept(*this);

	// Get back to previous block
	curr_func_name = current_function;
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
		//Variable* lhs_ptr = dynamic_cast<Variable*>(lhs.get());

		if(expr.is_variable())
		{
			// Get the value
			Variable& expr_cast = dynamic_cast<Variable&>(expr);
			unique_ptr<Value> expr_value = unique_ptr<Value>(block.create_load(expr_cast));

			// Store temp variable in location of the pointer
			unique_ptr<Value> store = unique_ptr<Value>(block.create_store(*expr_value, *lhs));
		}
		else
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
		//Variable* id_ptr = new Variable(var);

		pop();

		//add_return(id_ptr);
	}

}


void CodeGenVisitor::visit( ParamList& token )
{
	visit_children(token);
}


void CodeGenVisitor::visit( Param& token )
{
	// Only visit the first child
	token.get_children().at(0)->accept(*this);
}



/***********************************
 * 		Expression non-terminal    *
 ***********************************/

void CodeGenVisitor::visit( Expression& token )
{
	visit_children(token);
}


void CodeGenVisitor::visit( ast::ExpressionList& )
{

}


void CodeGenVisitor::visit( ModifyingExpression& token )
{
	visit_children(token);
}


void CodeGenVisitor::visit( DatastructureAccess& token )
{

}



/*************************************
 * 		FunctionCall non-terminal    *
 *************************************/

void CodeGenVisitor::visit( FuncCall& token )
{
	// Visit children :
	// - 1st child : IDENTIFIER
	// - 2nd child : Argument list -> get ID's
	visit_children(token);

	int nb_args = 0;
	if(token.contains_arglist())
		nb_args = token.get_arg_list().nb_args();

	vector<Value*> args = get_n_return_values(nb_args);

	// Function name
	Value& id = get_return_value(args.size());
	Variable& id_var = dynamic_cast<Variable&>(id);
	string func_name = id_var.get_name();

	// Return type
	string func_name_table = type_table.unique_id_name(function_table.get_curr_scope_id(), func_name);

	shared_ptr<typegen::Type> ret_type = shared_ptr<typegen::Type>(dynamic_cast<typegen::Function*>(type_table.get_type(func_name_table).get())->get_ret_type());

	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// Get values from arguments
	vector<shared_ptr<Value>> args_value;
	for(auto arg = args.rbegin() ; arg != args.rend() ; ++arg)
	{
		Value* arg_ptr = *arg;
		if(arg_ptr->is_constant())
			args_value.push_back(shared_ptr<Value>(arg_ptr));
		else if(arg_ptr->is_variable())
		{
			Variable* var = dynamic_cast<Variable*>(arg_ptr);
			args_value.push_back(shared_ptr<Value>(block.create_load(*var)));
		}
	}

	codegen::Function function(ret_type, func_name, args_value);
	Variable* add = dynamic_cast<Variable*>(block.create_func_call(function));


	pop_n_return_values(nb_args+1);


	// Create the pointer that will contain the result
	if(add == nullptr)
		return;

	unique_ptr<Variable> container = unique_ptr<Variable>(new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(add->get_name()), add->get_type(), true));

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));

	Variable* after_store_var = dynamic_cast<Variable*>(block.create_store(*add, *ptr));

	add_return(after_store_var);

}


void CodeGenVisitor::visit( ArgList& token )
{
	visit_children(token);
}


void CodeGenVisitor::visit( Argument& token )
{
	visit_children(token);
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
	size_t id_scope = token.get_scope_id();

	function_table.move_to_scope(id_scope);
	variable_table.move_to_scope(id_scope);

	visit_children(token);

	if(!function_table.is_root())
		function_table.move_to_parent_scope();

	if(!variable_table.is_root())
		variable_table.move_to_parent_scope();


}



/**********************************
 * 		Statement non-terminal    *
 **********************************/

void CodeGenVisitor::visit( Statement& token )
{
	visit_children(token);
}


void CodeGenVisitor::visit( Return& token )
{
	FunctionBlock& function = curr_module.get_function(curr_func_name);

	if(token.has_child())
	{
		// Child is Expression
		visit_children(token);

		Value& exp = get_return_value(0);
		if(exp.is_variable())
		{
			Variable& exp_var = dynamic_cast<Variable&>(exp);
			if(exp_var.is_pointer())
			{
				unique_ptr<Value> return_value = unique_ptr<Value>(function.get_last_block().create_load(exp_var));
				function.set_return(return_value->str_value());
			}
			else
				function.set_return(exp.str_value());
		}
		else
			function.set_return(exp.str_value());

		pop();
	}
	else
		function.set_return("");
}


void CodeGenVisitor::visit( Menu& token )
{

}

void CodeGenVisitor::visit( ast::MenuBody& )
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
	token.get_if().accept(*this);


	for(int i = 0 ; i < token.count_elseif() ; ++i)
		token.get_nth_elseif(i).accept(*this);

	if(token.contains_else())
		token.get_else().accept(*this);

	FunctionBlock& curr_function = curr_module.get_function(curr_func_name);
	curr_function.add_block(label_manager.get_last_occurence("end_if"));
}

void CodeGenVisitor::visit( Elseif& token )
{
	// In current block, add operations to compute the condition and the branch
	token.get_expression().accept(*this);
	Value& result_comp = top(); // Return the variable where the result is stored

	FunctionBlock& curr_function = curr_module.get_function(curr_func_name);
	BasicBlock& block = curr_function.get_last_block();

	string label_true = label_manager.insert_label("elseif_true");
	string label_false = label_manager.insert_label("elseif_false");
	block.create_cond_branch(result_comp, label_true, label_false);

	pop();

	// Create block "true"
	curr_function.add_block(label_true);

	// Add body of the block "true"
	token.get_scope().accept(*this);

	// Go to end_if
	curr_function.get_last_block().create_branch(label_manager.get_last_occurence("end_if"));

	// Create elseif_false
	curr_function.add_block(label_false);
}

void CodeGenVisitor::visit( ast::If& token )
{
	// In current block, add operations to compute the condition and the branch
	token.get_expression().accept(*this);
	Value& result_comp = top(); // Return the variable where the result is stored
	Variable& cast_result = dynamic_cast<Variable&>(result_comp);


	FunctionBlock& curr_function = curr_module.get_function(curr_func_name);
	BasicBlock& block = curr_function.get_last_block();


	string label_true = label_manager.insert_label("if_true");
	string label_false = label_manager.insert_label("if_false");
	block.create_cond_branch(result_comp, label_true, label_false);

	pop();

	// Create block "true"
	curr_function.add_block(label_true);

	// Add body of the block "true"
	token.get_scope().accept(*this);

	// Go to end_if
	curr_function.get_last_block().create_branch(label_manager.get_last_occurence("end_if"));

	// Create if_false
	curr_function.add_block(label_false);
}

void CodeGenVisitor::visit( ast::Else& token )
{
	token.get_scope().accept(*this);

	curr_module.get_function(curr_func_name).get_last_block().create_branch(label_manager.get_last_occurence("end_if"));
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

vector<Value*> CodeGenVisitor::get_n_return_values(int n)
{
	vector<Value*> values;
	for(int i = 0 ; i < n ; ++i)
		values.push_back(return_vector.at(return_vector.size()-1-i).get());

	return values;
}


void CodeGenVisitor::pop_n_return_values(int n)
{
	for(int i = 0 ; i < n ; ++i)
		pop();
}


bool CodeGenVisitor::is_vector_empty() const
{
	return get_vector_size() <= 0;
}

int CodeGenVisitor::get_vector_size() const
{
	return return_vector.size();
}
