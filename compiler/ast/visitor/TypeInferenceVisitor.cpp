#include "TypeInferenceVisitor.hpp"

#include "../../../Exceptions.hpp"
#include "../../../Types.hpp"

using namespace std;
using namespace visitor;
using namespace inference;

void TypeInferenceVisitor::visit( ast::ASTNode& )
{

}

void TypeInferenceVisitor::visit( ast::Identifier& id )
{
	string alpha = params.get_param(1);

	// unify alpha with the type of the identifier
	type_table.unify(alpha, type_table.unique_id_name(current_scope, id.id()));

	params.ret();
}

void TypeInferenceVisitor::visit( ast::K_Continue& )
{

}

void TypeInferenceVisitor::visit( ast::K_Break& )
{

}

void TypeInferenceVisitor::visit( ast::Type_Int& )
{

}

void TypeInferenceVisitor::visit( ast::Type_Float& )
{

}

void TypeInferenceVisitor::visit( ast::Type_Char& )
{

}

void TypeInferenceVisitor::visit( ast::Type_String& )
{

}

void TypeInferenceVisitor::visit( ast::Type_Array& )
{

}

void TypeInferenceVisitor::visit( ast::Type_List& )
{

}

void TypeInferenceVisitor::visit( ast::Type_Bool& )
{

}

void TypeInferenceVisitor::visit( ast::Op_Plus& op )
{
	string alpha = params.get_param(1); 

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_Minus& op )
{
	string alpha = params.get_param(1); 

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_Mult& op )
{
	string alpha = params.get_param(1); 

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_Div& op )
{
	string alpha = params.get_param(1); 

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_Modulo& op )
{
	string alpha = params.get_param(1);

	type_table.unify_int(alpha); // module can only have integer operands

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_Exponentiation& op )
{
	string alpha = params.get_param(1);

	string beta = type_table.new_variable(); // add a type variable for the exponent
	type_table.unify_int(beta); // exponent must be an integer

	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(beta); 
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_UnaryMinus& op )
{
	string alpha = params.get_param(1);

	params.add_param(alpha); // alpha is transmitted to the expression
	params.call();
	op.get_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_BitwiseOr& op )
{
	string alpha = params.get_param(1);

	// bitwise operators applies on int and return int
	type_table.unify_int(alpha);

	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_BitwiseAnd& op )
{
	string alpha = params.get_param(1);

	// bitwise operators applies on int and return int
	type_table.unify_int(alpha);

	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_BitwiseXor& op )
{
	string alpha = params.get_param(1);

	// bitwise operators applies on int and return int
	type_table.unify_int(alpha);

	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_BitwiseNot& op )
{
	string alpha = params.get_param(1);

	// bitwise operators applies on int and return int
	type_table.unify_int(alpha);

	params.add_param(alpha);
	params.call();
	op.get_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_LogicalOr& op )
{
	string alpha = params.get_param(1);

	// boolean operator expect boolean operands and return a boolean
	type_table.unify_bool(alpha);

	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_LogicalAnd& op )
{
	string alpha = params.get_param(1);

	// boolean operator expect boolean operands and return a boolean
	type_table.unify_bool(alpha);

	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_LogicalNot& op )
{
	string alpha = params.get_param(1);

	// boolean operator expect boolean operands and return a boolean
	type_table.unify_bool(alpha);

	params.add_param(alpha);
	params.call();
	op.get_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_CompLessThan& op )
{
	string alpha = params.get_param(1);

	// comparison operators return a boolean 
	type_table.unify_bool(alpha);

	// operands can have a different types
	string beta = type_table.new_variable();

	params.add_param(beta);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(beta);
	params.call();
	op.get_right_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_CompGreaterThan& op )
{
	string alpha = params.get_param(1);

	// comparison operators return a boolean 
	type_table.unify_bool(alpha);

	// operands can have a different types
	string beta = type_table.new_variable();

	params.add_param(beta);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(beta);
	params.call();
	op.get_right_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_CompLessEqual& op )
{
	string alpha = params.get_param(1);

	// comparison operators return a boolean 
	type_table.unify_bool(alpha);

	// operands can have a different types
	string beta = type_table.new_variable();

	params.add_param(beta);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(beta);
	params.call();
	op.get_right_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_CompGreaterEqual& op )
{
	string alpha = params.get_param(1);

	// comparison operators return a boolean 
	type_table.unify_bool(alpha);

	// operands can have a different types
	string beta = type_table.new_variable();

	params.add_param(beta);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(beta);
	params.call();
	op.get_right_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_CompEqual& op )
{
	string alpha = params.get_param(1);

	// comparison operators return a boolean 
	type_table.unify_bool(alpha);

	// operands can have a different types
	string beta = type_table.new_variable();

	params.add_param(beta);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(beta);
	params.call();
	op.get_right_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_CompNotEqual& op )
{
	string alpha = params.get_param(1);

	// comparison operators return a boolean 
	type_table.unify_bool(alpha);

	// operands can have a different types
	string beta = type_table.new_variable();

	params.add_param(beta);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(beta);
	params.call();
	op.get_right_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_LeftShift& op)
{
	string alpha = params.get_param(1);

	// bitwise operators applies on int and return int
	type_table.unify_int(alpha);

	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_RightShift& op)
{
	string alpha = params.get_param(1);

	// bitwise operators applies on int and return int
	type_table.unify_int(alpha);

	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_StringConcat& op )
{
	string alpha = params.get_param(1);

	// string concatenation takes strings as operand and return string
	type_table.unify_string(alpha);

	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_PrefixIncrement& op )
{
	string alpha = params.get_param(1);

	params.add_param(alpha); // alpha is transmitted to the expression
	params.call();
	op.get_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_PrefixDecrement& op )
{
	string alpha = params.get_param(1);

	params.add_param(alpha); // alpha is transmitted to the expression
	params.call();
	op.get_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_PostfixIncrement& op )
{
	string alpha = params.get_param(1);

	params.add_param(alpha); // alpha is transmitted to the expression
	params.call();
	op.get_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_PostfixDecrement& op )
{
	string alpha = params.get_param(1);

	params.add_param(alpha); // alpha is transmitted to the expression
	params.call();
	op.get_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_Assignment& op )
{
	string alpha = params.get_param(1); 

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_AssignPlus& op )
{
	string alpha = params.get_param(1); 

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_AssignMinus& op )
{
	string alpha = params.get_param(1); 

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_AssignMult& op )
{
	string alpha = params.get_param(1); 

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_AssignDiv& op )
{
	string alpha = params.get_param(1); 

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_AssignExpo& op )
{
	string alpha = params.get_param(1); 

	// exponent must be an integer
	string beta = type_table.new_variable();
	type_table.unify_int(beta);

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(beta);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_AssignMod& op )
{
	string alpha = params.get_param(1); 

	// modulo op expects integer operands and return an integer
	type_table.unify_int(alpha);

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_AssignAnd& op )
{
	string alpha = params.get_param(1); 

	// bitwise op expects integer operands and return an integer
	type_table.unify_int(alpha);

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_AssignOr& op )
{
	string alpha = params.get_param(1); 

	// bitwise op expects integer operands and return an integer
	type_table.unify_int(alpha);

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_AssignXor& op )
{
	string alpha = params.get_param(1); 

	// bitwise op expects integer operands and return an integer
	type_table.unify_int(alpha);

	// alpha goes to both operand
	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_AssignConcat& op )
{
	string alpha = params.get_param(1);

	// string concatenation takes strings as operand and return string
	type_table.unify_string(alpha);

	params.add_param(alpha);
	params.call();
	op.get_left_operand().accept(*this);

	params.add_param(alpha);
	params.call();
	op.get_right_operand().accept(*this);
	
	params.ret();
}

/**
 * Constants
 */ 

void TypeInferenceVisitor::visit( ast::String& cste )
{
	string alpha = params.get_param(1);

	// string constant -> alpha is a string
	type_table.unify_string(alpha);
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Character& cste )
{
	string alpha = params.get_param(1);

	// char constant -> alpha is a char
	type_table.unify_char(alpha);
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Integer& cste )
{
	string alpha = params.get_param(1);

	// int constant -> alpha is a int
	type_table.unify_int(alpha);
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Float& cste )
{
	string alpha = params.get_param(1);

	// float constant -> alpha is a float
	type_table.unify_float(alpha);
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Bool& cste )
{
	string alpha = params.get_param(1);

	// bool constant -> alpha is a bool
	type_table.unify_bool(alpha);
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Array& array )
{
	string alpha = params.get_param(1);

	// array constant : alpha is an array of type beta
	pair<string, string> array_type_vars = type_table.new_array();
	string beta = array_type_vars.second;

	// alpha is of type array(beta)
	type_table.unify(alpha, array_type_vars.first);

	// each element of the array must have the type beta
	for(auto item : array.get_items())
	{
		params.add_param(beta);
		params.call();
		item.accept(*this);
	}

	params.ret();
}

void TypeInferenceVisitor::visit( ast::List& list )
{
	string alpha = params.get_param(1);

	// list constant : alpha is an list of type beta
	pair<string, string> list_type_vars = type_table.new_list();
	string beta = list_type_vars.second;

	// alpha is of type list(beta)
	type_table.unify(alpha, list_type_vars.first);

	// each element of the list must have the type beta
	for(auto& item : list.get_items())
	{
		params.add_param(beta);
		params.call();
		item.accept(*this);
	}

	params.ret();
}

void TypeInferenceVisitor::visit( ast::MakeSequenceList& seq_list )
{
	string alpha = params.get_param(1);

	// list constant : alpha is an list of type beta
	pair<string, string> list_type_vars = type_table.new_list();
	string beta = list_type_vars.second;

	// alpha is of type list(beta) and beta has type int
	type_table.unify(alpha, list_type_vars.first);
	type_table.unify_int(beta);

	// begin and end must be of type int
	params.add_param(beta);
	params.call();
	seq_list.get_begin().accept(*this);

	params.add_param(beta);
	params.call();
	seq_list.get_end().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::MakeSequenceArray& seq_array )
{
	string alpha = params.get_param(1);

	// array constant : alpha is an array of type beta
	pair<string, string> array_type_vars = type_table.new_array();
	string beta = array_type_vars.second;

	// alpha is of type array(beta) and beta has type int
	type_table.unify(alpha, array_type_vars.first);
	type_table.unify_int(beta);

	// begin and end must be of type int
	params.add_param(beta);
	params.call();
	seq_array.get_begin().accept(*this);

	params.add_param(beta);
	params.call();
	seq_array.get_end().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::DeclFunc& declfunc )
{
	ParamList& param_list = declfunc.get_param_list();

	vector<string> param_names;
	vector<ShallowType> param_types;

	param_list.get_parameters_name(param_names);
	param_list.get_parameters_type(param_types);

	
}

void TypeInferenceVisitor::visit( ast::DeclVars& declvars )
{
	// no argument expecte
	for(size_t i = 0; i < declvars.nb_variables(); ++i)
	{
		params.call();
		declvars.get_variable(i).accept(*this);
	}

	params.ret();
}

void TypeInferenceVisitor::visit( ast::DeclVar& )
{	
	// no argument expected 
	// create a new type variable
	string varname = type_table.new_variable(type_table.unique_id_name(current_scope, declaration.get_identifier().id()));
	
	params.add_param(varname); // the expression has the same type of the identifier
	params.call();
	declaration.get_expression().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::ParamList& )
{

}

void TypeInferenceVisitor::visit( ast::Param& )
{

}

void TypeInferenceVisitor::visit( ast::Expression& )
{

}

void TypeInferenceVisitor::visit( ast::ModifyingExpression& )
{

}

void TypeInferenceVisitor::visit( ast::DatastructureAccess& ds_access )
{
	// only array can be access with [ ]
	string alpha = params.get_param(1); // type of the array

	pair<string,string> array_type = new_array();

	// alpha is the type of the array
	type_table.unify(alpha, array_type.second);

	// the idenfier should 'contain' an array
	params.add_param(array_type.first);
	params.call();
	ds_access.get_id().accept(*this);

	// the index expression should be an integer
	string beta = new_variable();
	type_table.unify_int(beta);

	params.add_param(beta);
	params.call();
	ds_access.get_index().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::FuncCall& func_call )
{
	string gamma = params.get_param(1); // type that should be returned by the function

	// add function matching the structure of the call
	ArgList& arg_list = func_call.get_arg_list();

	// build the vector of parameter names
	vector<string> type_param_name;
	generate_n(back_inserter(type_param_name), 
			   arg_list.nb_args(), 
			   [type_table&](){ return type_table.unique_varname(); });

	// create the function type
	pair<string,string> func_type = type_table.new_function(type_param_name);

	// gamme should be the same type as the one returned by the function
	type_table.unify(gamme, func_type.second);

	// each argument should have the correct type
	for(size_t i = 0; i < arg_list.nb_args(); ++i)
	{
		params.add_param(type_param_name[i]);
		params.call();
		arg_list.get_arg(i).accept(*this);
	}

	// the function id or soy should have the same structure as the one defined here
	params.add_param(func_type.first);
	params.call();
	func_call.get_function().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::ArgList& )
{
	// bypassed in the FuncCall visit
}

void TypeInferenceVisitor::visit( ast::Argument& )
{

}

void TypeInferenceVisitor::visit( ast::SoyFunc& func )
{
	string delta = params.get_param(1); // function type

	
}

void TypeInferenceVisitor::visit( ast::Program& )
{

}

void TypeInferenceVisitor::visit( ast::Scope& )
{

}

void TypeInferenceVisitor::visit( ast::Statement& )
{

}

void TypeInferenceVisitor::visit( ast::Return& )
{

}

void TypeInferenceVisitor::visit( ast::Menu& )
{

}

void TypeInferenceVisitor::visit( ast::MenuDef& )
{

}

void TypeInferenceVisitor::visit( ast::Roll& )
{

}

void TypeInferenceVisitor::visit( ast::Foreach& )
{

}

void TypeInferenceVisitor::visit( ast::For& )
{

}

void TypeInferenceVisitor::visit( ast::ForInitializer& )
{

}

void TypeInferenceVisitor::visit( ast::ForUpdate& )
{

}

void TypeInferenceVisitor::visit( ast::Conditional& )
{

}

void TypeInferenceVisitor::visit( ast::Elseif& )
{

}