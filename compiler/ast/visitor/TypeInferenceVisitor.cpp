#include "TypeInferenceVisitor.hpp"

#include "../../inference/Types.hpp"

#include <algorithm>
#include <stdexcept>

using namespace std;
using namespace visitor;
using namespace inference;
using namespace symb;

#include <iostream>

TypeInferenceVisitor::TypeInferenceVisitor(SymbolTable<FunctionInfo>& function_table_, 
										   SymbolTable<VariableInfo>& variable_table_) 
  : current_scope(0), function_table(function_table_), variable_table(variable_table_)
{

}

void TypeInferenceVisitor::visit( ast::ASTNode& node )
{
	cout << "ASTNode" << endl << type_table << endl << endl;
	// hopefully, never called because of virtual 
	for(auto child : node.get_children())
	{
		params.call();
		child->accept(*this);
	}

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Identifier& id )
{
	cout << "Identifier  (" << id.id() << ")" << endl << type_table << endl << endl;
	string alpha = params.get_param(1);

	// unify alpha with the type of the identifier
	size_t identifier_scope; 

	if(variable_table.symbol_exists(id.id()))
		identifier_scope = variable_table.get_symbol_scope_id(id.id());
	else if(function_table.symbol_exists(id.id()))
		identifier_scope = function_table.get_symbol_scope_id(id.id());
	else
		throw std::logic_error("The symbol is still undefined after scope checking");

	string id_type_name = type_table.unique_id_name(identifier_scope, id.id());
	
	cout << alpha << " - > " << id_type_name << endl;
	
	type_table.unify(alpha, id_type_name);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::K_Continue& cont )
{
	// bypassed by the decl func node
	throw std::logic_error("This node should be bypassed");
}

void TypeInferenceVisitor::visit( ast::K_Break& brk )
{
	// bypassed by the decl func node
	throw std::logic_error("This node should be bypassed");
}

void TypeInferenceVisitor::visit( ast::Type_Int& type )
{
	// bypassed by the decl func node
	throw std::logic_error("This node should be bypassed");
}

void TypeInferenceVisitor::visit( ast::Type_Float& type )
{
	// bypassed by the decl func node
	throw std::logic_error("This node should be bypassed");
}

void TypeInferenceVisitor::visit( ast::Type_Char& type )
{
	// bypassed by the decl func node
	throw std::logic_error("This node should be bypassed");
}

void TypeInferenceVisitor::visit( ast::Type_String& type )
{
	// bypassed by the decl func node
	throw std::logic_error("This node should be bypassed");
}

void TypeInferenceVisitor::visit( ast::Type_Array& type )
{
	// bypassed by the decl func node
	throw std::logic_error("This node should be bypassed");
}

void TypeInferenceVisitor::visit( ast::Type_List& type )
{
	// bypassed by the decl func node
	throw std::logic_error("This node should be bypassed");
}

void TypeInferenceVisitor::visit( ast::Type_Bool& type )
{
	// bypassed by the decl func node
	throw std::logic_error("This node should be bypassed");
}

void TypeInferenceVisitor::visit( ast::Type_Function& type )
{
	// bypassed by the decl func node
	throw std::logic_error("This node should be bypassed");
}
 
void TypeInferenceVisitor::visit( ast::Op_Plus& op )
{
	cout << "Op_Plus" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator
	// operands can only be integers or float
	type_table.update_hints(alpha, TypesHint(INT | FLOAT));

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
	cout << "Op_Minus" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator
	// operands can only be integers or float
	type_table.update_hints(alpha, TypesHint(INT | FLOAT));

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
	cout << "Op_Mult" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator
	// operands can only be integers or float
	type_table.update_hints(alpha, TypesHint(INT | FLOAT));

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
	cout << "Op_Div" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator
	// operands can only be integers or float
	type_table.update_hints(alpha, TypesHint(INT | FLOAT));

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
	cout << "Op_Modulo" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

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
	cout << "Op_Exponentiation" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator
	
	// base can only be an integer or a float
	type_table.update_hints(alpha, TypesHint(INT | FLOAT));

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
	cout << "Op_UnaryMinus" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// base can only be an integer or a float
	type_table.update_hints(alpha, TypesHint(INT | FLOAT));

	params.add_param(alpha); // alpha is transmitted to the expression
	params.call();
	op.get_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_BitwiseOr& op )
{
	cout << "Op_BitwiseOr" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

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
	cout << "Op_BitwiseAnd" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

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
	cout << "Op_BitwiseXor" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

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
	cout << "Op_BitwiseNot" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// bitwise operators applies on int and return int
	type_table.unify_int(alpha);

	params.add_param(alpha);
	params.call();
	op.get_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_LogicalOr& op )
{
	cout << "Op_LogicalOr" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

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
	cout << "Op_LogicalAnd" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

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
	cout << "Op_LogicalNot" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// boolean operator expect boolean operands and return a boolean
	type_table.unify_bool(alpha);

	params.add_param(alpha);
	params.call();
	op.get_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_CompLessThan& op )
{
	cout << "Op_CompLessThan" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// comparison operators return a boolean 
	type_table.unify_bool(alpha);

	// operands can have a different types (but must be both either float or int)
	string beta = type_table.new_variable(TypesHint(FLOAT | INT));

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
	cout << "Op_CompGreaterThan" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// comparison operators return a boolean 
	type_table.unify_bool(alpha);

	// operands can have a different types (but must be both either float or int)
	string beta = type_table.new_variable(TypesHint(FLOAT | INT));

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
	cout << "Op_CompLessEqual" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// comparison operators return a boolean 
	type_table.unify_bool(alpha);

	// operands can have a different types (but must be both either float or int)
	string beta = type_table.new_variable(TypesHint(FLOAT | INT));

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
	cout << "Op_CompGreaterEqual" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// comparison operators return a boolean 
	type_table.unify_bool(alpha);

	// operands can have a different types (but must be both either float or int)
	string beta = type_table.new_variable(TypesHint(FLOAT | INT));

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
	cout << "Op_CompEqual" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// comparison operators return a boolean 
	type_table.unify_bool(alpha);

	// operands can have a different types (but must be both either float, bool or int)
	string beta = type_table.new_variable(TypesHint(INT | FLOAT | BOOL));

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
	cout << "Op_CompNotEqual" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// comparison operators return a boolean 
	type_table.unify_bool(alpha);

	// operands can have a different types (but must be both either float, bool or int)
	string beta = type_table.new_variable(TypesHint(INT | FLOAT | BOOL));

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
	cout << "Op_LeftShift" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

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
	cout << "Op_RightShift" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

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
	cout << "Op_StringConcat" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

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
	cout << "Op_PrefixIncrement" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator
	// operand can only be an integer or a float
	type_table.update_hints(alpha, TypesHint(INT | FLOAT));

	params.add_param(alpha); // alpha is transmitted to the expression
	params.call();
	op.get_operand().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_PrefixDecrement& op )
{
	cout << "Op_PrefixDecrement" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator
	// operand can only be an integer or a float
	type_table.update_hints(alpha, TypesHint(INT | FLOAT));

	params.add_param(alpha); // alpha is transmitted to the expression
	params.call();
	op.get_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_PostfixIncrement& op )
{
	cout << "Op_PostfixIncrement" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator
	// operand can only be an integer or a float
	type_table.update_hints(alpha, TypesHint(INT | FLOAT));

	params.add_param(alpha); // alpha is transmitted to the expression
	params.call();
	op.get_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_PostfixDecrement& op )
{
	cout << "Op_PostfixDecrement" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator
	// operand can only be an integer or a float
	type_table.update_hints(alpha, TypesHint(INT | FLOAT));

	params.add_param(alpha); // alpha is transmitted to the expression
	params.call();
	op.get_operand().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Op_Assignment& op )
{
	cout << "Op_Assignment" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator 

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
	cout << "Op_AssignPlus" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// operands must be either Float or Int
	type_table.update_hints(alpha, TypesHint(FLOAT | INT));

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
	cout << "Op_AssignMinus" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// operands must be either Float or Int
	type_table.update_hints(alpha, TypesHint(FLOAT | INT));

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
	cout << "Op_AssignMult" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// operands must be either Float or Int
	type_table.update_hints(alpha, TypesHint(FLOAT | INT));

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
	cout << "Op_AssignDiv" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator 

	// operands must be either Float or Int
	type_table.update_hints(alpha, TypesHint(FLOAT | INT));

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
	cout << "Op_AssignExpo" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

	// left operand can be either an float or an int
	type_table.update_hints(alpha, TypesHint(FLOAT | INT));

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
	cout << "Op_AssignMod" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator 

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
	cout << "Op_AssignAnd" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator 

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
	cout << "Op_AssignOr" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator 

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
	cout << "Op_AssignXor" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator 

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
	cout << "Op_AssignConcat" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // type returned by the operator

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
	cout << "String" << endl << type_table << endl << endl;
	string alpha = params.get_param(1);

	// string constant -> alpha is a string
	type_table.unify_string(alpha);
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Character& cste )
{
	cout << "Character" << endl << type_table << endl << endl;
	string alpha = params.get_param(1);

	// char constant -> alpha is a char
	type_table.unify_char(alpha);
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Integer& cste )
{
	cout << "Integer" << endl << type_table << endl << endl;
	string alpha = params.get_param(1);

	// int constant -> alpha is a int
	type_table.unify_int(alpha);
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Float& cste )
{
	cout << "Float" << endl << type_table << endl << endl;
	string alpha = params.get_param(1);

	// float constant -> alpha is a float
	type_table.unify_float(alpha);
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Bool& cste )
{
	cout << "Bool" << endl << type_table << endl << endl;
	string alpha = params.get_param(1);

	// bool constant -> alpha is a bool
	type_table.unify_bool(alpha);
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Array& array )
{
	cout << "Array" << endl << type_table << endl << endl;
	string alpha = params.get_param(1);

	// array constant : alpha is an array of type beta
	pair<string, string> array_type_vars = type_table.new_array();
	string beta = array_type_vars.second;

	// alpha is of type array(beta)
	type_table.unify(alpha, array_type_vars.first);

	// each element of the array must have the type beta
	params.add_param(beta);
	params.call();
	array.get_items().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::List& list )
{
	cout << "List" << endl << type_table << endl << endl;
	string alpha = params.get_param(1);

	// list constant : alpha is an list of type beta
	pair<string, string> list_type_vars = type_table.new_list();
	string beta = list_type_vars.second;

	// alpha is of type list(beta)
	type_table.unify(alpha, list_type_vars.first);

	// each element of the list must have the type beta
	params.add_param(beta);
	params.call();
	list.get_items().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::MakeSequenceList& seq_list )
{
	cout << "MakeSequenceList" << endl << type_table << endl << endl;
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
	cout << "MakeSequenceArray" << endl << type_table << endl << endl;
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
	cout << "DeclFunc" << endl << type_table << endl << endl;

	// update the symbol table with function data
	pair<string, string> func_type_names;
	if(declfunc.contains_params())
		func_type_names = add_function_declaration_rule(declfunc.get_param_list(),
														declfunc.get_id().id(),
														declfunc.get_scope().get_scope_id());
	else 
		func_type_names = add_function_declaration_rule(declfunc.get_id().id(),
														declfunc.get_scope().get_scope_id());


	// propagate return value to scope
	params.add_param(func_type_names.second);
	params.call();
	declfunc.get_scope().accept(*this);
	
	params.ret();
}

void TypeInferenceVisitor::visit( ast::DeclVars& declvars )
{
	cout << "DeclVars" << endl << type_table << endl << endl;
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
	cout << "DeclVar" << endl << type_table << endl << endl;	
	// no argument expected 
	// create a new type variable
	string varname = type_table.new_variable(type_table.unique_id_name(current_scope, declaration.get_identifier().id()));
	
	if(declaration.contains_expr())
	{
		params.add_param(varname); // the expression has the same type of the identifier
		params.call();
		declaration.get_expression().accept(*this);		
	}

	params.ret();
}

void TypeInferenceVisitor::visit( ast::ParamList& param_list )
{
	// bypassed by DelcFunc and SoyExpression 
	throw std::logic_error("This node should be bypassed"); 
}

void TypeInferenceVisitor::visit( ast::Param& param )
{
	// bypassed by DelcFunc and SoyExpression 
	throw std::logic_error("This node should be bypassed"); 
}

void TypeInferenceVisitor::visit( ast::Expression& expression )
{
	cout << "Expression" << endl << type_table << endl << endl;
	/**
	 * can either take one or zero parameter. If the number of 
	 * parameters is 0, then a new type variable is created for the 
	 * subexpression. Otherwise the one given as parameter is taken
	 */ 
	string alpha = (params.nb_params() == 0) ? type_table.new_variable() : params.get_param(1);

	params.add_param(alpha);
	params.call();
	expression.get_child().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::ExpressionList& expr_list )
{
	string alpha = params.get_param(1); // type of the elements of the list

	for(size_t i = 0; i < expr_list.nb_expressions(); ++i)
	{
		params.add_param(alpha);
		params.call();
		expr_list.get_nth_expression(i).accept(*this);
	}

	params.ret();
}

void TypeInferenceVisitor::visit( ast::ModifyingExpression& expression )
{
	cout << "ModifyingExpression" << endl << type_table << endl << endl;
	/**
	 * can either take one or zero parameter. If the number of 
	 * parameters is 0, then a new type variable is created for the 
	 * subexpression. Otherwise the one given as parameter is taken
	 */ 
	string alpha = (params.nb_params() == 0) ? type_table.new_variable() : params.get_param(1);

	params.add_param(alpha);
	params.call();
	expression.get_child().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::DatastructureAccess& ds_access )
{
	cout << "DatastructureAccess" << endl << type_table << endl << endl;
	// only array can be access with [ ]
	string alpha = params.get_param(1); // type of the array

	pair<string,string> array_type = type_table.new_array();

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
	cout << "FuncCall" << endl << type_table << endl << endl;
	string gamma = params.get_param(1); // type that should be returned by the function

	// add function matching the structure of the call
	size_t number_args = 0;

	if(func_call.contains_arglist())
		number_args = func_call.get_arg_list().nb_args();

	// build the vector of parameter names
	vector<string> type_param_name;
	generate_n(back_inserter(type_param_name), 
			   number_args, 
			   [this](){ return type_table.unique_varname(); });

	// create the function type
	pair<string,string> func_type = type_table.new_function(type_param_name);

	// gamma should be the same type as the one returned by the function
	type_table.unify(gamma, func_type.second);

	// the function id or soy should have the same structure as the one defined here
	params.add_param(func_type.first);
	params.call();
	func_call.get_function().accept(*this);

	// each argument should have the correct type
	for(size_t i = 0; i < number_args; ++i)
	{
		params.add_param(type_param_name[i]);
		params.call();
		func_call.get_arg_list().get_arg(i).accept(*this);
	}

	params.ret();
}

void TypeInferenceVisitor::visit( ast::ArgList& arg_list )
{
	// bypassed by FuncCall
	throw std::logic_error("This node should be bypassed"); 
}

void TypeInferenceVisitor::visit( ast::Argument& arg )
{
	cout << "Argument" << endl << type_table << endl << endl;
	string alpha = params.get_param(1);

	params.add_param(alpha);
	params.call();
	arg.get_child().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::SoyFunc& soy )
{
	cout << "SoyFunc" << endl << type_table << endl << endl;
	string delta = params.get_param(1); // function type

	// update the symbol table with soy function data
	pair<string, string> func_type_names = add_function_declaration_rule(soy.get_params(),
																		 soy.get_name(),
																		 soy.get_scope().get_scope_id());

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
	cout << "Program" << endl << type_table << endl << endl;
	string alpha("");

	params.add_param(alpha); // empty string means that nothing is expected as return type
	params.call();
	program.get_scope().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Scope& scope )
{
	cout << "Scope" << endl << type_table << endl << endl;
	string alpha = params.get_param(1), 
			beta; // type to pass to the children nodes

	size_t prev_scope = current_scope;
	current_scope = scope.get_scope_id();
	cout << "Move to scope " << current_scope << endl;
	// move to the new scope in the symbol tables
	variable_table.move_to_scope(current_scope);
	function_table.move_to_scope(current_scope);

	if(alpha.empty()) // empty string means that nothing is expected as return type
	{
		// the scope is not expected to return something 
		beta = type_table.new_variable(TypesHint(VOID));
		type_table.unify_void(beta);
	}
	else beta = alpha; 

	// pass beta recursively
	for(auto child : scope.get_children())
	{
		if(propagate_type_from_scope(*child))
			params.add_param(beta);
		params.call();
		child->accept(*this);
	}

	// go back to the previous scope
	variable_table.move_to_scope(prev_scope);
	function_table.move_to_scope(prev_scope);
	current_scope = prev_scope;

	cout << "Go back to " << current_scope << endl;

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Statement& statement )
{
	cout << "Statement" << endl << type_table << endl << endl;
	statement.get_statement().accept(*this); // forward the type to the actual statement
}

void TypeInferenceVisitor::visit( ast::Return& nori )
{
	cout << "Return" << endl << type_table << endl << endl;
	string alpha = params.get_param(1);

	if(nori.empty_nori())
		type_table.unify_void(alpha);
	else
	{
		params.add_param(alpha);
		params.call();
		nori.get_returned_expression().accept(*this);
	}

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Menu& menu )
{
	cout << "Menu" << endl << type_table << endl << endl;
	string alpha = params.get_param(1), // type that should be returned by the element of the body
			beta = type_table.new_variable(TypesHint(CHAR | INT)); // type of the menu expression

	params.add_param(beta);
	params.call();
	menu.get_expression().accept(*this);
	
	params.add_param(alpha); 
	params.add_param(beta);
	params.call();
	menu.get_body().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::MenuBody& body )
{
	cout << "MenuBody" << endl << type_table << endl << endl;
	string alpha = params.get_param(1), // case body return type
			beta = params.get_param(2); // matcher type

	for(size_t i = 0; i < body.nb_cases(); i++)
	{
		params.add_param(alpha);
		params.add_param(beta);
		params.call();
		body.get_nth_case(i).accept(*this);
	}

	params.add_param(alpha);
	params.call();
	body.get_default_case().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::MenuDef& menudef )
{
	cout << "MenuDef" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // the parameter that should be returned by case scope

	params.add_param(alpha);
	params.call();
	menudef.get_scope().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::MenuCase& menucase )
{
	cout << "MenuCase" << endl << type_table << endl << endl;
	string alpha = params.get_param(1), // the parameter that should be returned by case scope
			beta = params.get_param(2); // function of the case expression

	params.add_param(alpha);
	params.call();
	menucase.get_scope().accept(*this);

	params.add_param(beta);
	params.call();
	menucase.get_expression().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Roll& roll )
{
	cout << "Roll" << endl << type_table << endl << endl;
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
	cout << "Foreach" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // the parameter to pass to the roll body scope

	string iter_var_type = type_table.unique_id_name(foreach.get_scope().get_scope_id(), foreach.get_identifier().id());
	type_table.new_variable(iter_var_type); // the type of the iteration variable

	pair<string,string> list_type = type_table.new_list(); // the list expression 

	// the variable must have the same type as the array elements type
	type_table.unify(list_type.second, iter_var_type);

	// the expression must be a list
	params.add_param(list_type.first);
	params.call();
	foreach.get_expression().accept(*this);

	params.add_param(alpha);
	params.call();
	foreach.get_scope().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::For& for_loop )
{
	cout << "For" << endl << type_table << endl << endl;
	string alpha = params.get_param(1),  // the parameter to pass to the for body scope
	 		beta = type_table.new_variable(); // the type of the expression

	// the guardian must be a boolean 
	type_table.unify_bool(beta);

	params.add_param(beta);
	params.call();
	for_loop.get_expression().accept(*this);

	params.add_param(alpha);
	params.call();
	for_loop.get_scope().accept(*this);

	params.call();
	for_loop.get_initializer().accept(*this);

	params.call();
	for_loop.get_update().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::ForInitializer& initializer )
{
	cout << "ForInitializer" << endl << type_table << endl << endl;
	params.call();
	initializer.get_expression().accept(*this);
	params.ret();
}

void TypeInferenceVisitor::visit( ast::ForUpdate& update )
{
	cout << "ForUpdate" << endl << type_table << endl << endl;
	params.call();
	update.get_expression().accept(*this);
	params.ret();
}

void TypeInferenceVisitor::visit( ast::Conditional& conditional )
{
	cout << "Conditional" << endl << type_table << endl << endl;
	string alpha = params.get_param(1); // to pass to the scopes

	// transmit to if
	params.add_param(alpha);
	params.call();
	conditional.get_if().accept(*this);

	for(size_t i = 0; i < conditional.count_elseif(); ++i)
	{
		params.add_param(alpha);
		params.call();
		conditional.get_nth_elseif(i).accept(*this);
	}

	// transmit to else
	if(conditional.contains_else())
	{
		params.add_param(alpha);
		params.call();
		conditional.get_else().accept(*this);
	}

	params.ret();
}

void TypeInferenceVisitor::visit( ast::If& if_node )
{
	cout << "If" << endl << type_table << endl << endl;
	string alpha = params.get_param(1),
			beta = type_table.new_variable();

	// the expression must be a boolean 
	type_table.unify_bool(beta);

	params.add_param(beta);
	params.call();
	if_node.get_expression().accept(*this);

	params.add_param(alpha);
	params.call();
	if_node.get_scope().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Elseif& elseif )
{
	cout << "Elseif" << endl << type_table << endl << endl;
	string alpha = params.get_param(1),
			beta = type_table.new_variable();

	// the expression must be a boolean 
	type_table.unify_bool(beta);

	params.add_param(beta);
	params.call();
	elseif.get_expression().accept(*this);

	params.add_param(alpha);
	params.call();
	elseif.get_scope().accept(*this);

	params.ret();
}

void TypeInferenceVisitor::visit( ast::Else& else_node )
{
	cout << "Else" << endl << type_table << endl << endl;
	string alpha = params.get_param(1);

	params.add_param(alpha);
	params.call();
	else_node.get_scope().accept(*this);

	params.ret();
}

pair<string, string> TypeInferenceVisitor::add_function_declaration_rule(const ast::ParamList& param_list, 
																		 const string& func_name, 
																		 size_t scope_id)
{
	vector<string> param_names, // param names without scope ids
				   param_type_names; // params names with scope ids

	param_list.get_parameters_name(param_names);
	
	// get name with scope ids
	auto mk_unique_id_name = [this, scope_id](const std::string& name)
							 { return type_table.unique_id_name(scope_id, name); };

	transform(param_names.begin(), param_names.end(), back_inserter(param_type_names), mk_unique_id_name);

	// unify possible hints with param type variables
	vector<ShallowType> param_type_hints;
	param_list.get_parameters_type(param_type_hints);

	// create function
	string func_type_name = type_table.unique_id_name(current_scope, func_name);
	return type_table.new_function(param_type_names, func_type_name, param_type_hints);
}

pair<string, string> TypeInferenceVisitor::add_function_declaration_rule(const string& func_name, 
																		 size_t scope_id)
{
	vector<string> param_type_names; // params names with scope ids

	// create function
	string func_type_name = type_table.unique_id_name(current_scope, func_name);
	return type_table.new_function(param_type_names, func_type_name);
}

bool TypeInferenceVisitor::propagate_type_from_scope(ast::ASTNode& node)
{
	ast::Statement* statement = dynamic_cast<ast::Statement*>(&node);
	return statement;
}