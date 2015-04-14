#include "PrintASTVisitor.hpp"

using namespace std;

// Constructor
PrintASTVisitor::PrintASTVisitor() : length_line(2), out_(cout) { }
PrintASTVisitor::PrintASTVisitor(ostream& out) : length_line(2), out_(out) { }


void PrintASTVisitor::print_pair( string& p_name, string& p_value, int depth )
{
	string tab_line = string(depth * length_line, '-') + "˧";
	out_ << tab_line << " <" << p_name << " ; " << p_value << ">" << endl;
}


void PrintASTVisitor::print_single( string& name, int depth )
{
	string tab_line = string(depth * length_line, '-') + "˧";
	out_ << tab_line << " " << name << endl;
}

/*****************************
 * 		Identifier token    *
 *****************************/

void PrintASTVisitor::visit( ast::Identifier& token )
{
	print_pair(token.node_name(), token.id(), token.depth());
}


/*************************
 * 		Keyword token    *
 *************************/
void PrintASTVisitor::visit( ast::K_Maki& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_To& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_Soy& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_Nori& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_Menu& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_For& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_Roll& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_Break& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_Continue& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_Foreach& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_As& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_If& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_Elseif& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::K_Else& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Type_Int& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Type_Float& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Type_Char& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Type_String& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Type_Array& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Type_List& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Type_Tuple& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Type_Bool& token )
{
	print_single(token.node_name(), token.depth());
}


/****************************
 * 		Operator token      *
 ****************************/

void PrintASTVisitor::visit( ast::Op_Plus& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_Minus& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_Mult& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_Div& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_Modulo& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_Exponentiation& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_UnaryMinus& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_BitwiseOr& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_BitwiseAnd& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_BitwiseXor& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_BitwiseNot& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_LogicalOr& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_LogicalAnd& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_LogicalNot& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_CompLessThan& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_CompGreaterThan& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_CompLessEqual& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_CompGreaterEqual& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_CompEqual& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_CompNotEqual& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_LeftShift& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_RightShift& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_StringConcat& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_PrefixIncrement& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_PrefixDecrement& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_PostfixIncrement& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_PostfixDecrement& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_Assignment& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_AssignPlus& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_AssignMinus& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_AssignMult& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_AssignDiv& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_AssignExpo& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_AssignMod& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_AssignAnd& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_AssignOr& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_AssignXor& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Op_AssignConcat& token )
{
	print_single(token.node_name(), token.depth());
}


/**************************
 * 		Delimiter token    *
 **************************/

void PrintASTVisitor::visit( ast::DelimEol& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::DelimEos& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::TupleBeg& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::TupleEnd& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::ArrayBeg& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::ArrayEnd& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Arrow& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Virg& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::OpenPar& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::ClosingPar& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::OpenBrace& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::ClosingBrace& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::OpenAcc& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::ClosingAcc& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Underscore& token )
{
	print_single(token.node_name(), token.depth());
}


/**************************
 * 		Constant token    *
 **************************/

void PrintASTVisitor::visit( ast::String& token )
{
	print_pair(token.node_name(), token.value(), token.depth());
}

void PrintASTVisitor::visit( ast::Character& token )
{
	string value = string(1,token.value());
	print_pair(token.node_name(), value, token.depth());
}

void PrintASTVisitor::visit( ast::Integer& token )
{
	string value = to_string(token.value());
	print_pair(token.node_name(), value, token.depth());
}

void PrintASTVisitor::visit( ast::Float& token )
{
	string value = to_string(token.value());
	print_pair(token.node_name(), value, token.depth());
}

void PrintASTVisitor::visit( ast::Bool& token )
{
	string value = token.value() ? "true" : "false";
	print_pair(token.node_name(), value, token.depth());
}



/*********************************
 * 		Constant non-terminal    *
 *********************************/
void PrintASTVisitor::visit( ast::NT_Constant& token )
{
	print_single(token.node_name(), token.depth());
}


/**************************************
 * 		Datastructure non-terminal    *
 **************************************/

void PrintASTVisitor::visit( ast::Datastructure& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Array& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::List& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Tuple& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::MakeSequence& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::MakeSequenceList& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::MakeSequenceArray& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::SeqExpression& token )
{
	print_single(token.node_name(), token.depth());
}


/************************************
 * 		Declaration non-terminal    *
 ************************************/

void PrintASTVisitor::visit( ast::Declaration& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::DeclFunc& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::DeclVars& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::DeclVar& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::ParamList& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Param& token )
{
	print_single(token.node_name(), token.depth());
}


/***********************************
 * 		Expression non-terminal    *
 ***********************************/

void PrintASTVisitor::visit( ast::Expression& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::IncrExpression& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Assignment& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::ModifyingExpression& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::AssignableExpression& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::DatastructureAccess& token )
{
	print_single(token.node_name(), token.depth());
}


/*************************************
 * 		FunctionCall non-terminal    *
 *************************************/

void PrintASTVisitor::visit( ast::FuncCall& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::ArgList& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Argument& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::BracedFuncCall& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::FuncCallEol& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::ArgListEol& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::SoyExpression& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::SoyFunc& token )
{
	print_single(token.node_name(), token.depth());
}


/********************************
 * 		Program non-terminal    *
 ********************************/

void PrintASTVisitor::visit( ast::Program& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::ProgramElement& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Scope& token )
{
	print_single(token.node_name(), token.depth());
}


/**********************************
 * 		Statement non-terminal    *
 **********************************/

void PrintASTVisitor::visit( ast::Statement& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Return& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Menu& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::MenuDef& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Loop& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Roll& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Foreach& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::For& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::ForInitializer& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::ForUpdate& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Conditional& token )
{
	print_single(token.node_name(), token.depth());
}

void PrintASTVisitor::visit( ast::Elseif& token )
{
	print_single(token.node_name(), token.depth());
}

/************************
 * 		Default case    *
 ************************/
void PrintASTVisitor::visit( ast::ASTNode& token )
{
	string name = "Unknown";
	print_single(token.node_name(), token.depth());
}

