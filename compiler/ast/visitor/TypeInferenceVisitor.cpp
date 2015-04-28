#include "TypeInferenceVisitor.hpp"

#include "../../../Exceptions.hpp"
#include "../../../Types.hpp"

using namespace std;
using namespace visitor;
using namespace inference;

void TypeInferenceVisitor::visit( ast::ASTNode& node )
{
	// hopefully, never called because of virtual 
	for(auto child : node.get_children())
	{
		params.call();
		child.accept(*this);
	}

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Identifier& id )
{
	string alpha = params.get_param(1);

	// unify alpha with the type of the identifier
	type_table.unify(alpha, type_table.unique_id_name(current_scope, id.id()));

	params.ret();
}

void TypeInferenceVisitor::visit( ast::K_Continue& cont )
{
	params.ret(); // nothing to do (no type information)
}

void TypeInferenceVisitor::visit( ast::K_Break& brk )
{
	params.ret(); // nothing to do (no type information)
}

void TypeInferenceVisitor::visit( ast::Type_Int& type )
{
	params.ret(); // bypassed by the decl func node
}

void TypeInferenceVisitor::visit( ast::Type_Float& type )
{
	params.ret(); // bypassed by the decl func node
}

void TypeInferenceVisitor::visit( ast::Type_Char& type )
{
	params.ret(); // bypassed by the decl func node
}

void TypeInferenceVisitor::visit( ast::Type_String& type )
{
	params.ret(); // bypassed by the decl func node
}

void TypeInferenceVisitor::visit( ast::Type_Array& type )
{
	params.ret(); // bypassed by the decl func node
}

void TypeInferenceVisitor::visit( ast::Type_List& type )
{
	params.ret(); // bypassed by the decl func node
}

void TypeInferenceVisitor::visit( ast::Type_Bool& type )
{
	params.ret(); // bypassed by the decl func node
}

void TypeInferenceVisitor::visit( ast::Type_Function& type )
{
	params.ret(); // bypassed by the decl func node
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
	// update the symbol table with function data
	pair<string, string> func_type_names = add_function_declaration_rule(declfunc.get_param_list(),
																		 declfunc.get_scope().get_scope_id(),
																		 declfunc.get_id().id());

	// propagate return value to scope
	params.add_param(func_type_names.second);
	params.call();
	declfunc.get_scope().accept(*this);
	
	params.ret();
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

void TypeInferenceVisitor::visit( ast::DeclVar& declaration )
{	
	// no argument expected 
	// create a new type variable
	string varname = type_table.new_variable(type_table.unique_id_name(current_scope, declaration.get_identifier().id()));
	
	params.add_param(varname); // the expression has the same type of the identifier
	params.call();
	declaration.get_expression().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::ParamList& param_list )
{
	params.ret(); // bypassed by DelcFunc and SoyExpression 
}

void TypeInferenceVisitor::visit( ast::Param& param )
{
	params.ret(); // bypassed by DelcFunc and SoyExpression 
}

void TypeInferenceVisitor::visit( ast::Expression& expr )
{
	/**
	 * can either take one or zero parameter. If the number of 
	 * parameters is 0, then a new type variable is created for the 
	 * subexpression. Otherwise the one given as parameter is taken
	 */ 
	string alpha = (params.nb_params() == 0) ? new_variable() : params.get_param(1);

	params.add_param(alpha);
	params.call();
	expression.get_child().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::ModifyingExpression& expr )
{
	/**
	 * can either take one or zero parameter. If the number of 
	 * parameters is 0, then a new type variable is created for the 
	 * subexpression. Otherwise the one given as parameter is taken
	 */ 
	string alpha = (params.nb_params() == 0) ? new_variable() : params.get_param(1);

	params.add_param(alpha);
	params.call();
	expression.get_child().accept(*this);

	params.ret();
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
	string beta = type_table.new_variable();
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

void TypeInferenceVisitor::visit( ast::ArgList& arg_list )
{
	params.ret(); // bypassed in the FuncCall visit
}

void TypeInferenceVisitor::visit( ast::Argument& arg )
{
	string alpha = params.get_param(1);

	params.add_param(alpha);
	params.call();
	arg.get_child().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::SoyFunc& soy )
{
	string delta = params.get_param(1); // function type

	// update the symbol table with soy function data
	pair<string, string> func_type_names = add_function_declaration_rule(soy.get_params(),
																		 soy.get_scope().get_scope_id(),
																		 soy.get_name());

	// unify the function type with the inherited type
	type_table.unify(delta, func_type_names.first);

	// propagate return value to scope
	params.add_param(func_type_names.second);
	params.call();
	soy.get_scope().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Program& program )
{
	params.add_param(""); // empty string means that nothing is expected as return type
	params.call();
	program.get_scope().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Scope& scope )
{
	string alpha = params.get_param(1), 
		   beta; // beta is the type to pass to the child nodes

	if(alpha.empty()) // empty string means that nothing is expected as return type
	{
		// the scope is not expected to return something 
		beta = type_table.new_variable();
		type_table.unify_void(beta);
	}
	else beta = alpha; 

	// pass beta recursively
	for(auto child : scope.children())
	{
		params.add_param(beta);
		params.call();
		child->accept(*this);
	}

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Statement& statement )
{
	statement.get_statement().accept(*this); // forward the type to the actual statement
}

void TypeInferenceVisitor::visit( ast::Return& nori )
{
	string alpha = params.get_param(1);

	if(nori.empty_nori())
		type_table.unify_void(alpha);
	else
	{
		params.add_param(alpha);
		params.call();
		nori.get_expression().accept(*this);
	}

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Menu& menu )
{
	string alpha = params.get_param(1), // type that should be returned by the element of the body
			beta = type_table.new_variable(); // type of the menu expression

	params.add_param(beta);
	params.call();
	menu.get_body().accept(*this);

	params.add_param(alpha); 
	params.add_param(beta);
	params.call();
	menu.get_expression().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::MenuDef& menudef )
{
	string alpha = params.get_param(1); // the parameter that should be returned by case scope

	params.add_param(alpha);
	params.call();
	menudef.get_scope().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::MenuCase& menucase )
{
	string alpha = params.get_param(1), // the parameter that should be returned by case scope
			beta = params.get_param(2); // function of the case expression

	params.add_param(alpha);
	params.call();
	menudef.get_scope().accept(*this);

	params.add_param(beta);
	params.call();
	menudef.get_expression().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Roll& roll )
{
	string alpha = params.get_param(1), // the parameter to pass to the roll body scope
			beta = type_table.new_variable(); // type of the roll expression

	// the expression must return stg of type bool
	type_table.unify_bool(beta);

	params.add_param(beta);
	params.call();
	roll.get_expression().accept(*this);

	params.add_param(alpha);
	params.call();
	roll.get_scope().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Foreach& foreach )
{
	
}

void TypeInferenceVisitor::visit( ast::For& for_loop )
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

pair<string, string> TypeInferenceVisitor::add_function_declaration_rule(const ast::ParamList& param_list, 
																		 const string& func_name, 
																		 size_t scope_id)
{
	vector<string> param_names, // param names without scope ids
				   param_type_names; // params names with scope ids

	param_list.get_parameters_name(param_names);
	
	// get name with scope ids
	auto mk_unique_id_name = [&type_table, body_scope_id](const std::string& name)
							 { return type_table.unique_id_name(body_scope_id, name); };

	transform(param_names.begin(), params_names.end(), back_inserter(param_type_names), mk_unique_id_name);

	// unify possible hints with param type variables
	vector<ShallowType> param_type_hints;
	param_list.get_parameters_type(param_type_hints);

	// create function
	string func_type_name = type_table.unique_id_name(current_scope, func_name);
	return func_type_names = new_function(param_type_names, func_type_name, param_type_hints);
}