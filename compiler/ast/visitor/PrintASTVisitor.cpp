#include "PrintASTVisitor.hpp"

using namespace std;

// Constructor
PrintASTVisitor::PrintASTVisitor() : length_line(5) { }


void PrintASTVisitor::print_pair( string p_name&, string p_value&, int depth )
{
	string tab_line = string(depth * length_line, "-") + "˧";
	cout << tab_line << " <" << token.node_name() << " ; " << token.id() << ">" << endl;
}


void PrintASTVisitor::print_single( string name&, int depth )
{
	string tab_line = string(depth * length_line, "-") + "˧";
	cout << tab_line << " (" << nonterminal.node_name() << ")" << endl;
}


/*****************************
 * 		Identifier token    *
 *****************************/

void visit( ast::Identifier& token )
{
	print_pair(token.node_name(), token.id(), token.depth());
}


/*************************
 * 		Keyword token    *
 *************************/
void visit( ast::Maki& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::To& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Soy& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Nori& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::K_Menu& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::K_For& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::K_Roll& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Break& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Continue& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::K_Foreach& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::As& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::If& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::K_Elseif& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Else& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Type_Int& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Type_Float& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Type_Char& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Type_String& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Type_Array& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Type_List& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Type_Tuple& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Type_Bool& token )
{
	print_single(token.node_name(), token.depth());
}


/****************************
 * 		Operator token      *
 ****************************/

void visit( ast::Op_Plus& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_Minus& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_Mult& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_Div& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_Modulo& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_Exponentiation& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_UnaryMinus& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_BitwiseOr& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_BitwiseAnd& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_BitwiseXor& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_BitwiseNot& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_LogicalOr& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_LogicalAnd& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_LogicalNot& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_CompLessThan& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_CompGreaterThan& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_CompLessEqual& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_CompGreaterEqual& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_CompEqual& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_CompNotEqual& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_LeftShift& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_RightShift& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_StringConcat& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_PrefixIncrement& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_PrefixDecrement& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_PostfixIncrement& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_PostfixDecrement& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_Assignment& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_AssignPlus& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_AssignLess& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_AssignMult& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_AssignDiv& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_AssignExpo& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_AssignMod& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_AssignAnd& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_AssignOr& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_AssignXor& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Op_AssignConcat& token )
{
	print_single(token.node_name(), token.depth());
}


/**************************
 * 		Delimiter token    *
 **************************/

void visit( ast::DelimEol& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::DelimEos& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::TupleBeg& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::TupleEnd& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ArrayBeg& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ArrayEnd& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Arrow& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Virg& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::OpenPar& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ClosingPar& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::OpenBrace& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ClosingBrace& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::OpenAcc& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ClosingAcc& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Underscore& token )
{
	print_single(token.node_name(), token.depth());
}


/**************************
 * 		Constant token    *
 **************************/

void visit( ast::String& token )
{
	print_pair(token.node_name(), token.value(), token.depth());
}

void visit( ast::Character& token )
{
	print_pair(token.node_name(), token.value(), token.depth());
}

void visit( ast::Integer& token )
{
	print_pair(token.node_name(), token.value(), token.depth());
}

void visit( ast::Float& token )
{
	print_pair(token.node_name(), token.value(), token.depth());
}

void visit( ast::Bool& token )
{
	print_pair(token.node_name(), token.value(), token.depth());
}



/*********************************
 * 		Constant non-terminal    *
 *********************************/
void visit( ast::NT_Constant& token )
{
	print_single(token.node_name(), token.depth());
}


/**************************************
 * 		Datastructure non-terminal    *
 **************************************/

void visit( ast::Datastructure& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Array& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::List& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Tuple& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::MakeSequence& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::MakeSequenceList& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::MakeSequenceArray& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::SeqExpression& token )
{
	print_single(token.node_name(), token.depth());
}


/************************************
 * 		Declaration non-terminal    *
 ************************************/

void visit( ast::Declaration& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::DeclFunc& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::DeclVars& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::DeclVar& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ParamList& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Param& token )
{
	print_single(token.node_name(), token.depth());
}


/***********************************
 * 		Expression non-terminal    *
 ***********************************/

void visit( ast::Expression& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::IncrExpression& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Assignment& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ModifyingExpression& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::AssignableExpression& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::DatastructureAccess& token )
{
	print_single(token.node_name(), token.depth());
}


/*************************************
 * 		FunctionCall non-terminal    *
 *************************************/

void visit( ast::FuncCall& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ArgList& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Argument& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::BracedFuncCall& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::FuncCallEol& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ArgListEol& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::SoyExpression& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::SoyFunc& token )
{
	print_single(token.node_name(), token.depth());
}


/********************************
 * 		Program non-terminal    *
 ********************************/

void visit( ast::Program& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ScopeBody& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ProgramElement& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Scope& token )
{
	print_single(token.node_name(), token.depth());
}


/**********************************
 * 		Statement non-terminal    *
 **********************************/

void visit( ast::Statement& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Return& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Menu& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::MenuDef& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Loop& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Roll& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Foreach& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::For& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ForInitializer& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::ForUpdate& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Conditional& token )
{
	print_single(token.node_name(), token.depth());
}

void visit( ast::Elseif& token )
{
	print_single(token.node_name(), token.depth());
}

/************************
 * 		Default case    *
 ************************/

void visit( ast::ASTNode& token )
{
	print_single("Unknown", token.detph());
}

