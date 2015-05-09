#include "CodeGenVisitor.hpp"

#include <algorithm>

using namespace std;
using namespace visitor;
using namespace ast;
using namespace codegen;
using namespace symb;
using namespace inference;

CodeGenVisitor::CodeGenVisitor(SymbolTable<VariableInfo>& _variable_table,
							   SymbolTable<FunctionInfo>& _function_table,
							   TypeSymbolTable& _type_table,
							   settings::BuiltInFunctions& _built_in)
  : curr_module(builder.get_curr_module()),
  	curr_func_name("main"),
  	variable_table(_variable_table),
  	function_table(_function_table),
  	type_table(_type_table),
  	built_in(_built_in)
{
	// add the built-in functions
	for(auto& function : built_in)
	{
		string llvm_func_name = get_llvm_function_name(function.first, true),
				func_type_name = type_table.unique_id_name(0, function.first);
		shared_ptr<typegen::Function> func_type = dynamic_pointer_cast<typegen::Function>(type_table.get_type(func_type_name));
		FunctionBlock curr_func(builder.get_variable_manager(), llvm_func_name, func_type);
	    curr_module.add_declaration(function.first, curr_func);
	}
}


/*****************************
 * 		Identifier token    *
 *****************************/

void CodeGenVisitor::visit( Identifier& token )
{
	cout << "Identifier" << endl;
	string name;
	if(function_table.symbol_exists(token.id()))
		name = type_table.unique_id_name(function_table.get_symbol_scope_id(token.id()), token.id());
	else
		name = type_table.unique_id_name(variable_table.get_symbol_scope_id(token.id()), token.id());

	shared_ptr<typegen::Type> type = type_table.get_type(name);

	Variable* v = new Variable(builder.get_variable_manager(), token.id(), type, true);
	add_return(v);
}


/*************************
 * 		Keyword token    *
 *************************/
void CodeGenVisitor::visit( K_Break& token )
{
	cout << "K_Break" << endl;

}


void CodeGenVisitor::visit( K_Continue& token )
{
	cout << "K_Continue" << endl;

}


void CodeGenVisitor::visit( Type_Int& token )
{
	cout << "Type_Int" << endl;

}


void CodeGenVisitor::visit( Type_Float& token )
{
	cout << "Type_Float" << endl;

}


void CodeGenVisitor::visit( Type_Char& token )
{
	cout << "Type_Char" << endl;

}


void CodeGenVisitor::visit( Type_String& token )
{
	cout << "Type_String" << endl;

}


void CodeGenVisitor::visit( Type_Array& token )
{
	cout << "Type_Array" << endl;

}


void CodeGenVisitor::visit( Type_List& token )
{
	cout << "Type_List" << endl;

}


void CodeGenVisitor::visit( Type_Bool& token )
{
	cout << "Type_Bool" << endl;

}



void CodeGenVisitor::visit( Type_Function& token )
{
	cout << "Type_Function" << endl;

}


/****************************
 * 		Operator token      *
 ****************************/

void CodeGenVisitor::visit( Op_Plus& token )
{
	cout << "Op_Plus" << endl;
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
	cout << "Op_Minus" << endl;
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
	cout << "Op_Mult" << endl;
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
	cout << "Op_Div" << endl;
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
	cout << "Op_Modulo" << endl;
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
	cout << "Op_Exponentiation" << endl;
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
		result = dynamic_cast<Variable*>(block.create_op_expon(*(load_lhs), *(load_rhs)));
    }
	else if(lhs.is_variable() && rhs.is_constant())
	{
		unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
		result = dynamic_cast<Variable*>(block.create_op_expon(*(load_lhs), rhs));
	}
	else if(lhs.is_constant() && rhs.is_variable())
	{
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_expon(lhs, *(load_rhs)));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_expon(lhs, rhs));

	// Create the pointer that will contain the result
	Variable* container = new Variable(builder.get_variable_manager(), builder.get_variable_manager().insert_variable(result->get_name()), result->get_type(), true);

	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));

	Value* after_store = block.create_store(*result, *ptr);
	Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();
	pop();

	add_return(after_store_var);
}


void CodeGenVisitor::visit( Op_UnaryMinus& token )
{
	cout << "Op_UnaryMinus" << endl;
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
	cout << "Op_BitwiseOr" << endl;
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
	cout << "Op_BitwiseAnd" << endl;
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
	cout << "Op_BitwiseXor" << endl;
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
	cout << "Op_BitwiseNot" << endl;
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
	cout << "Op_LogicalOr" << endl;
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
	cout << "Op_LogicalAnd" << endl;
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
	cout << "Op_LogicalNot" << endl;
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
	cout << "Op_CompLessThan" << endl;
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
	cout << "Op_CompGreaterThan" << endl;
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
	cout << "Op_CompLessEqual" << endl;
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
	cout << "Op_CompGreaterEqual" << endl;
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
	cout << "Op_CompEqual" << endl;
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
	cout << "Op_CompNotEqual" << endl;
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
	cout << "Op_LeftShift" << endl;
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
	cout << "Op_RightShift" << endl;
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
	cout << "Op_StringConcat" << endl;

}


void CodeGenVisitor::visit( Op_PrefixIncrement& token )
{
	cout << "Op_PrefixIncrement" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& operand = get_return_value(0);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	Variable* result;

	if(operand.is_variable())
	{
		unique_ptr<Value> load_operand(block.create_load(operand));
		result = dynamic_cast<Variable*>(block.create_op_pref_incr(*load_operand));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_pref_incr(operand));

	Value* after_store = block.create_store(*result, operand);
	//Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();

	add_return(after_store);
}


void CodeGenVisitor::visit( Op_PrefixDecrement& token )
{
	cout << "Op_PrefixDecrement" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& operand = get_return_value(0);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	Variable* result;

	if(operand.is_variable())
	{
		unique_ptr<Value> load_operand(block.create_load(operand));
		result = dynamic_cast<Variable*>(block.create_op_pref_decr(*load_operand));
	}
	else
		result = dynamic_cast<Variable*>(block.create_op_pref_decr(operand));

	Value* after_store = block.create_store(*result, operand);
	//Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	pop();

	add_return(after_store);

}


void CodeGenVisitor::visit( Op_PostfixIncrement& token )
{
	cout << "Op_PostfixIncrement" << endl;
	// visit_children(token);

	// // Get 2 arguments
	// Value& operand = get_return_value(0);
	// BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// Variable* result;

	// if(operand.is_variable())
	// {
	// 	unique_ptr<Value> load_operand(block.create_load(operand));
	// 	result = dynamic_cast<Variable*>(block.create_op_post_incr(*load_operand));
	// }
	// else
	// 	result = dynamic_cast<Variable*>(block.create_op_post_incr(operand));

	// // increment the value stored
	// Value* after_store = block.create_store(*result, operand);

	// // return the non incremented value
	// Variable* container = new Variable(builder.get_variable_manager(), 
	// 									builder.get_variable_manager().insert_variable(operand->get_name()), 
	// 									result->get_type(), true);

	// unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));
	// Value* after_store = block.create_store(*container, *ptr);
	// Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	// pop();

	// add_return(after_store);

}


void CodeGenVisitor::visit( Op_PostfixDecrement& token )
{
	cout << "Op_PostfixDecrement" << endl;
	// visit_children(token);

	// // Get 2 arguments
	// Value& operand = get_return_value(0);
	// BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// Variable* result;

	// if(operand.is_variable())
	// {
	// 	unique_ptr<Value> load_operand(block.create_load(operand));
	// 	result = dynamic_cast<Variable*>(block.create_op_post_decr(*load_operand));
	// }
	// else
	// 	result = dynamic_cast<Variable*>(block.create_op_post_decr(operand));

	// Value* after_store = block.create_store(*result, operand);
	// //Variable* after_store_var = dynamic_cast<Variable*>(after_store);

	// pop();

	// add_return(after_store);
}


void CodeGenVisitor::visit( Op_Assignment& token )
{
	cout << "Op_Assignment" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	Value& lhs = get_return_value(1);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();
	Value* after_store = block.create_store(lhs, rhs);
	pop();
	pop();
	add_return(after_store);
}


void CodeGenVisitor::visit( Op_AssignPlus& token )
{
	cout << "Op_AssignPlus" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	Value& lhs = get_return_value(1);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// the left hand side is a variable
	unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
	
	Variable* result;
    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_plus(*load_lhs, *load_rhs));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_plus(*load_lhs, rhs));

	Value* after_store = block.create_store(*result, lhs);
	
	pop();
	pop();

	add_return(after_store);
}


void CodeGenVisitor::visit( Op_AssignMinus& token )
{
	cout << "Op_AssignMinus" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	Value& lhs = get_return_value(1);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// the left hand side is a variable
	unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
	
	Variable* result;
    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_minus(*load_lhs, *load_rhs));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_minus(*load_lhs, rhs));

	Value* after_store = block.create_store(*result, lhs);
	
	pop();
	pop();

	add_return(after_store);
}


void CodeGenVisitor::visit( Op_AssignMult& token )
{
	cout << "Op_AssignMult" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	Value& lhs = get_return_value(1);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// the left hand side is a variable
	unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
	
	Variable* result;
    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_mult(*load_lhs, *load_rhs));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_mult(*load_lhs, rhs));

	Value* after_store = block.create_store(*result, lhs);
	
	pop();
	pop();

	add_return(after_store);
}


void CodeGenVisitor::visit( Op_AssignDiv& token )
{
	cout << "Op_AssignDiv" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	Value& lhs = get_return_value(1);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// the left hand side is a variable
	unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
	
	Variable* result;
    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_div(*load_lhs, *load_rhs));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_div(*load_lhs, rhs));

	Value* after_store = block.create_store(*result, lhs);
	
	pop();
	pop();

	add_return(after_store);
}


void CodeGenVisitor::visit( Op_AssignExpo& token )
{
	cout << "Op_AssignExpo" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	Value& lhs = get_return_value(1);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// the left hand side is a variable
	unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
	
	Variable* result;
    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_expon(*load_lhs, *load_rhs));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_expon(*load_lhs, rhs));

	Value* after_store = block.create_store(*result, lhs);
	
	pop();
	pop();

	add_return(after_store);
}


void CodeGenVisitor::visit( Op_AssignMod& token )
{
	cout << "Op_AssignMod" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	Value& lhs = get_return_value(1);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// the left hand side is a variable
	unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
	
	Variable* result;
    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_mod(*load_lhs, *load_rhs));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_mod(*load_lhs, rhs));

	Value* after_store = block.create_store(*result, lhs);
	
	pop();
	pop();

	add_return(after_store);
}


void CodeGenVisitor::visit( Op_AssignAnd& token )
{
	cout << "Op_AssignAnd" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	Value& lhs = get_return_value(1);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// the left hand side is a variable
	unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
	
	Variable* result;
    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_bit_and(*load_lhs, *load_rhs));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_bit_and(*load_lhs, rhs));

	Value* after_store = block.create_store(*result, lhs);
	
	pop();
	pop();

	add_return(after_store);
}


void CodeGenVisitor::visit( Op_AssignOr& token )
{
	cout << "Op_AssignOr" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	Value& lhs = get_return_value(1);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// the left hand side is a variable
	unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
	
	Variable* result;
    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_bit_or(*load_lhs, *load_rhs));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_bit_or(*load_lhs, rhs));

	Value* after_store = block.create_store(*result, lhs);
	
	pop();
	pop();

	add_return(after_store);
}


void CodeGenVisitor::visit( Op_AssignXor& token )
{
	cout << "Op_AssignXor" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	Value& lhs = get_return_value(1);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// the left hand side is a variable
	unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
	
	Variable* result;
    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_bit_xor(*load_lhs, *load_rhs));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_bit_xor(*load_lhs, rhs));

	Value* after_store = block.create_store(*result, lhs);
	
	pop();
	pop();

	add_return(after_store);
}


void CodeGenVisitor::visit( Op_AssignConcat& token )
{
	cout << "Op_AssignConcat" << endl;
	visit_children(token);

	// Get 2 arguments
	Value& rhs = get_return_value(0);
	Value& lhs = get_return_value(1);
	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// the left hand side is a variable
	unique_ptr<Value> load_lhs = unique_ptr<Value>(block.create_load(lhs));
	
	Variable* result;
    if(rhs.is_variable())
    {
		unique_ptr<Value> load_rhs = unique_ptr<Value>(block.create_load(rhs));
		result = dynamic_cast<Variable*>(block.create_op_str_conc(*load_lhs, *load_rhs));
    }
	else
		result = dynamic_cast<Variable*>(block.create_op_str_conc(*load_lhs, rhs));

	Value* after_store = block.create_store(*result, lhs);
	
	pop();
	pop();

	add_return(after_store);
}


/**************************
 * 		Constant token    *
 **************************/

void CodeGenVisitor::visit( ast::String& token )
{
	cout << "String" << endl;
	ConstantString* constant_string = new ConstantString(token.value());
	add_return(constant_string);
}


void CodeGenVisitor::visit( Character& token )
{
	cout << "Character" << endl;
	ConstantChar* constant_char = new ConstantChar(token.value());
	add_return(constant_char);
}

void CodeGenVisitor::visit( Integer& token )
{
	cout << "Integer" << endl;
	ConstantInt* constant_int = new ConstantInt(token.value());
	add_return(constant_int);
}

void CodeGenVisitor::visit( ast::Float& token )
{
	cout << "Float" << endl;
	ConstantFloat* constant_float = new ConstantFloat(token.value());
	add_return(constant_float);
}

void CodeGenVisitor::visit( ast::Bool& token )
{
	cout << "Bool" << endl;
	ConstantBool* constant_bool = new ConstantBool(token.value());
	add_return(constant_bool);
}


/**************************************
 * 		Datastructure non-terminal    *
 **************************************/

void CodeGenVisitor::visit( ast::Array& token )
{
	cout << "Array" << endl;

}


void CodeGenVisitor::visit( ast::List& token )
{
	cout << "List" << endl;

}


void CodeGenVisitor::visit( MakeSequenceList& token )
{
	cout << "MakeSequenceList" << endl;

}


void CodeGenVisitor::visit( MakeSequenceArray& token )
{
	cout << "MakeSequenceArray" << endl;

}


/************************************
 * 		Declaration non-terminal    *
 ************************************/

void CodeGenVisitor::visit( DeclFunc& token )
{
	cout << "DeclFunc" << endl;
	int index = 0;

	// Visit 1st child : Identifier
	token.get_children().at(index)->accept(*this);

	Value& id = get_return_value(0);
	Variable& id_var = dynamic_cast<Variable&>(id);

	// Create new FunctionBlock
	string declared_function_name = id_var.get_name(),
			func_name_table = type_table.unique_id_name(function_table.get_curr_scope_id(), declared_function_name),
			llvm_func_name = get_llvm_function_name(declared_function_name, built_in.count(declared_function_name));

	//typegen::Function* function_type = ;
	vector<string> params;

	if(token.contains_params())
		token.get_param_list().get_parameters_name(params);

	FunctionBlock function(builder.get_variable_manager(),
						   llvm_func_name,
						   dynamic_pointer_cast<typegen::Function>(type_table.get_type(func_name_table)),
						   params);

	pop();

	// Change "cursor" of the visitor to the new function
	string current_function = curr_func_name;
	curr_func_name = declared_function_name;
	curr_module.add_function(declared_function_name, function);

	// Fullfill it through the visit of the children
	token.get_scope().accept(*this);

	// Get back to previous block
	curr_func_name = current_function;
}


void CodeGenVisitor::visit( DeclVars& token )
{
	cout << "DeclVars" << endl;
	visit_children(token);
}


void CodeGenVisitor::visit( DeclVar& token )
{
	cout << "DeclVar" << endl;
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
	cout << "ParamList" << endl;
	visit_children(token);
}


void CodeGenVisitor::visit( Param& token )
{
	cout << "Param" << endl;
	// Only visit the first child
	token.get_children().at(0)->accept(*this);
}



/***********************************
 * 		Expression non-terminal    *
 ***********************************/

void CodeGenVisitor::visit( Expression& token )
{
	cout << "Expression" << endl;
	visit_children(token);
}


void CodeGenVisitor::visit( ast::ExpressionList& )
{

}


void CodeGenVisitor::visit( ModifyingExpression& token )
{
	cout << "ModifyingExpression" << endl;
	visit_children(token);
}


void CodeGenVisitor::visit( DatastructureAccess& token )
{
	cout << "DatastructureAccess" << endl;

}



/*************************************
 * 		FunctionCall non-terminal    *
 *************************************/

void CodeGenVisitor::visit( FuncCall& token )
{
	cout << "FuncCall" << endl;
	// Visit children :
	// - 1st child : IDENTIFIER
	// - 2nd child : Argument list -> get ID's
	visit_children(token);

	int nb_args = 0;
	if(token.contains_arglist())
		nb_args = token.get_arg_list().nb_args();

	vector<shared_ptr<Value>> args = get_n_return_values(nb_args);

	// Function name
	Value& id = get_return_value(args.size());
	Variable& id_var = dynamic_cast<Variable&>(id);
	string func_name = id_var.get_name();

	// Return type
	string func_name_table = type_table.unique_id_name(function_table.get_symbol_scope_id(func_name), func_name);

	shared_ptr<typegen::Function> func_type = dynamic_pointer_cast<typegen::Function>(type_table.get_type(func_name_table));

	BasicBlock& block = curr_module.get_function(curr_func_name).get_last_block();

	// Get values from arguments
	vector<shared_ptr<Value>> args_value;
	for(auto arg = args.rbegin() ; arg != args.rend() ; ++arg)
	{
		shared_ptr<Value> arg_ptr = *arg;
		if(arg_ptr->is_constant())
			args_value.push_back(arg_ptr);
		else if(arg_ptr->is_variable())
		{
			shared_ptr<Variable> var = dynamic_pointer_cast<Variable>(arg_ptr);
			args_value.push_back(shared_ptr<Value>(block.create_load(*var)));
		}
	}

	string llvm_func_name = get_llvm_function_name(func_name, built_in.count(func_name));
	codegen::Function function(func_type->get_ret_type(), llvm_func_name, args_value);
	Variable* add = dynamic_cast<Variable*>(block.create_func_call(function));

	pop_n_return_values(nb_args+1);

	// Create the pointer that will contain the result
	if(add == nullptr)
		return;
	Variable* var = new Variable(builder.get_variable_manager(),
								 builder.get_variable_manager().insert_variable(add->get_name()),
								 add->get_type(), true);

	unique_ptr<Variable> container = unique_ptr<Variable>(var);
	unique_ptr<Value> ptr = unique_ptr<Value>(block.create_decl_var(*container));

	Variable* after_store_var = dynamic_cast<Variable*>(block.create_store(*add, *ptr));

	add_return(after_store_var);
}


void CodeGenVisitor::visit( ArgList& token )
{
	cout << "ArgList" << endl;
	visit_children(token);
}


void CodeGenVisitor::visit( Argument& token )
{
	cout << "Argument" << endl;
	visit_children(token);
}


void CodeGenVisitor::visit( SoyFunc& token )
{
	cout << "SoyFunc" << endl;

	// // Visit 1st child : Identifier
	// token.get_children().at(0)->accept(*this);

	// Value& id = get_return_value(0);
	// Variable& id_var = dynamic_cast<Variable&>(id);

	// // Create new FunctionBlock
	// string declared_function_name = id_var.get_name(),
	// 		func_name_table = type_table.unique_id_name(function_table.get_curr_scope_id(), declared_function_name),
	// 		llvm_func_name = get_llvm_function_name(declared_function_name, built_in.count(declared_function_name));

	// //typegen::Function* function_type = ;
	// vector<string> params;

	// if(token.contains_params())
	// 	token.get_param_list().get_parameters_name(params);

	// FunctionBlock function(builder.get_variable_manager(),
	// 					   llvm_func_name,
	// 					   dynamic_pointer_cast<typegen::Function>(type_table.get_type(func_name_table)),
	// 					   params);

	// pop();

	// // Change "cursor" of the visitor to the new function
	// string current_function = curr_func_name;
	// curr_func_name = declared_function_name;
	// curr_module.add_function(declared_function_name, function);

	// // Fullfill it through the visit of the children
	// token.get_scope().accept(*this);

	// // Get back to previous block
	// curr_func_name = current_function;
}



/********************************
 * 		Program non-terminal    *
 ********************************/

void CodeGenVisitor::visit( Program& token )
{
	cout << "Program" << endl;
	visit_children(token);
}


void CodeGenVisitor::visit( Scope& token )
{
	cout << "Scope" << endl;
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
	cout << "Statement" << endl;
	visit_children(token);
}


void CodeGenVisitor::visit( Return& token )
{
	cout << "Return" << endl;
	cout << "func : " << curr_func_name << endl;
	FunctionBlock& function = curr_module.get_function(curr_func_name);
	cerr << "ff" << endl;
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
				shared_ptr<Value> return_value(function.get_last_block().create_load(exp_var));
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
	cout << "Menu" << endl;

}

void CodeGenVisitor::visit( ast::MenuBody& )
{

}

void CodeGenVisitor::visit( MenuDef& token )
{
	cout << "MenuDef" << endl;

}

void CodeGenVisitor::visit( MenuCase& token )
{
	cout << "MenuCase" << endl;

}

void CodeGenVisitor::visit( Roll& token )
{
	cout << "Roll" << endl;

}


void CodeGenVisitor::visit( Foreach& token )
{
	cout << "Foreach" << endl;

}


void CodeGenVisitor::visit( For& token )
{
	cout << "For" << endl;

}


void CodeGenVisitor::visit( ForInitializer& token )
{
	cout << "ForInitializer" << endl;

}


void CodeGenVisitor::visit( ForUpdate& token )
{
	cout << "ForUpdate" << endl;

}


void CodeGenVisitor::visit( Conditional& token )
{
	cout << "Conditional" << endl;
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
	cout << "Elseif" << endl;
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
	cout << "If" << endl;
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
	cout << "Else" << endl;
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

vector<shared_ptr<Value>> CodeGenVisitor::get_n_return_values(int n)
{
	vector<shared_ptr<Value>> values;
	copy(next(return_vector.begin(), return_vector.size() - n), return_vector.end(), back_inserter(values));
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

string CodeGenVisitor::get_llvm_function_name(const string& spp_name, bool built_in = false)
{
	if(!built_in)
		return "." + spp_name;

	string new_name(spp_name);
	replace_if(new_name.begin(), new_name.end(), [](char c) { return c == '-'; }, '_');
	return new_name;
}
