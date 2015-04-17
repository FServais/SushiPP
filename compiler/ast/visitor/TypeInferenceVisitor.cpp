#include "TypeInferenceVisitor.hpp"

#include "../../../Exceptions.hpp"

// static member of TypeInferenceVisitor
size_t TypeInferenceVisitor::type_variable_cnt = 1;

TypeInferenceVisitor::TypeInferenceVisitor()
{

}

void TypeInferenceVisitor::visit( ast::ASTNode& )
{

}

void TypeInferenceVisitor::visit( ast::Identifier& )
{

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

void TypeInferenceVisitor::visit( ast::Op_Plus& )
{
	check_params(1);
	LinkNode& passed_link = get_param();

	// pass the parameter to expression 2
	add_param(passed_link);
	
}

void TypeInferenceVisitor::visit( ast::Op_Minus& )
{
	check_params(1);
	LinkNode& passed_link = get_param();

	// pass the parameter to expression 2
	add_param(passed_link);
	
}

void TypeInferenceVisitor::visit( ast::Op_Mult& )
{
	check_params(1);
	LinkNode& passed_link = get_param();

	// pass the parameter to expression 2
	add_param(passed_link);
	
}

void TypeInferenceVisitor::visit( ast::Op_Div& )
{
	check_params(1);
	LinkNode& passed_link = get_param();

	// pass the parameter to expression 2
	add_param(passed_link);
	
}

void TypeInferenceVisitor::visit( ast::Op_Modulo& )
{

}

void TypeInferenceVisitor::visit( ast::Op_Exponentiation& )
{

}

void TypeInferenceVisitor::visit( ast::Op_UnaryMinus& )
{

}

void TypeInferenceVisitor::visit( ast::Op_BitwiseOr& )
{

}

void TypeInferenceVisitor::visit( ast::Op_BitwiseAnd& )
{

}

void TypeInferenceVisitor::visit( ast::Op_BitwiseXor& )
{

}

void TypeInferenceVisitor::visit( ast::Op_BitwiseNot& )
{

}

void TypeInferenceVisitor::visit( ast::Op_LogicalOr& )
{

}

void TypeInferenceVisitor::visit( ast::Op_LogicalAnd& )
{

}

void TypeInferenceVisitor::visit( ast::Op_LogicalNot& )
{

}

void TypeInferenceVisitor::visit( ast::Op_CompLessThan& )
{

}

void TypeInferenceVisitor::visit( ast::Op_CompGreaterThan& )
{

}

void TypeInferenceVisitor::visit( ast::Op_CompLessEqual& )
{

}

void TypeInferenceVisitor::visit( ast::Op_CompGreaterEqual& )
{

}

void TypeInferenceVisitor::visit( ast::Op_CompEqual& )
{

}

void TypeInferenceVisitor::visit( ast::Op_CompNotEqual& )
{

}

void TypeInferenceVisitor::visit( ast::Op_LeftShift& )
{

}

void TypeInferenceVisitor::visit( ast::Op_RightShift& )
{

}

void TypeInferenceVisitor::visit( ast::Op_StringConcat& )
{

}

void TypeInferenceVisitor::visit( ast::Op_PrefixIncrement& )
{

}

void TypeInferenceVisitor::visit( ast::Op_PrefixDecrement& )
{

}

void TypeInferenceVisitor::visit( ast::Op_PostfixIncrement& )
{

}

void TypeInferenceVisitor::visit( ast::Op_PostfixDecrement& )
{

}

void TypeInferenceVisitor::visit( ast::Op_Assignment& )
{

}

void TypeInferenceVisitor::visit( ast::Op_AssignPlus& )
{

}

void TypeInferenceVisitor::visit( ast::Op_AssignMinus& )
{

}

void TypeInferenceVisitor::visit( ast::Op_AssignMult& )
{

}

void TypeInferenceVisitor::visit( ast::Op_AssignDiv& )
{

}

void TypeInferenceVisitor::visit( ast::Op_AssignExpo& )
{

}

void TypeInferenceVisitor::visit( ast::Op_AssignMod& )
{

}

void TypeInferenceVisitor::visit( ast::Op_AssignAnd& )
{

}

void TypeInferenceVisitor::visit( ast::Op_AssignOr& )
{

}

void TypeInferenceVisitor::visit( ast::Op_AssignXor& )
{

}

void TypeInferenceVisitor::visit( ast::Op_AssignConcat& )
{

}

void TypeInferenceVisitor::visit( ast::String& )
{

}

void TypeInferenceVisitor::visit( ast::Character& )
{

}

void TypeInferenceVisitor::visit( ast::Integer& )
{

}

void TypeInferenceVisitor::visit( ast::Float& )
{

}

void TypeInferenceVisitor::visit( ast::Bool& )
{

}

void TypeInferenceVisitor::visit( ast::Array& )
{

}

void TypeInferenceVisitor::visit( ast::List& )
{

}

void TypeInferenceVisitor::visit( ast::MakeSequenceList& )
{

}

void TypeInferenceVisitor::visit( ast::MakeSequenceArray& )
{

}

void TypeInferenceVisitor::visit( ast::DeclFunc& )
{

}

void TypeInferenceVisitor::visit( ast::DeclVars& )
{

}

void TypeInferenceVisitor::visit( ast::DeclVar& )
{

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

void TypeInferenceVisitor::visit( ast::DatastructureAccess& )
{

}

void TypeInferenceVisitor::visit( ast::FuncCall& )
{

}

void TypeInferenceVisitor::visit( ast::ArgList& )
{

}

void TypeInferenceVisitor::visit( ast::Argument& )
{

}

void TypeInferenceVisitor::visit( ast::SoyFunc& )
{

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

std::string TypeInferenceVisitor::new_type_variable_name()
{
	stringstream ss;
	ss << (type_variable_cnt++) << "-typevar";
	return ss.str();
}

void TypeInferenceVisitor::check_params(size_t expected)
{
	if(expected != parameter_count)
		throw BadParameterNumberException();
}

void TypeInferenceVisitor::add_param(inference::TypeLink& link)
{
	parameters.push(link);
	parameter_count++;
}

inference::TypeLink& TypeInferenceVisitor::get_param()
{
	if(parameter_count == 0)
		throw BadParameterNumberException("no more parameters in 'get_param'");
	
	inference::TypeLink& ret = parameters.top();
	parameter_count--;
	parameter.pop();
	return ret;
}
