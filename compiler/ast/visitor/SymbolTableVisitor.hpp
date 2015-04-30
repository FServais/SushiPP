
#ifndef SymbolTableVisitor_HPP_DEFINED
#define SymbolTableVisitor_HPP_DEFINED



#include "../../symb/SymbolTable.hpp"
#include "../../symb/SymbolInfo.hpp"
#include "../../exceptions/Exceptions.hpp"
#include "../../util.hpp"
#include "ASTVisitor.hpp"

using namespace symb;

class SymbolTableVisitor : public visitor::ASTVisitor
{
public:

	SymbolTableVisitor(SymbolTable<FunctionInfo>& , SymbolTable<VariableInfo>& );
	~SymbolTableVisitor(){};

	virtual void visit( ast::ASTNode& );
	virtual void visit( ast::DeclVar& );
	virtual void visit( ast::FuncCall&  );
	virtual void visit( ast::Identifier& );
	virtual void visit( ast::Scope& );


		/*************************
		 * 		Keyword token    *
		 *************************/
		 
		virtual void visit( ast::K_Continue& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::K_Break& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Type_Int& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Type_Float& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Type_Char& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Type_String& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Type_Array& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Type_List& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Type_Bool& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		
		/**************************
		 * 		Operator token    *
		 **************************/
		
		virtual void visit( ast::Op_Plus& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_Minus& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_Mult& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_Div& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_Modulo& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_Exponentiation& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_UnaryMinus& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_BitwiseOr& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_BitwiseAnd& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_BitwiseXor& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_BitwiseNot& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_LogicalOr& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_LogicalAnd& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_LogicalNot& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_CompLessThan& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_CompGreaterThan& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_CompLessEqual& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_CompGreaterEqual& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_CompEqual& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_CompNotEqual& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_LeftShift& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_RightShift& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_StringConcat& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_PrefixIncrement& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_PrefixDecrement& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_PostfixIncrement& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_PostfixDecrement& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_Assignment& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_AssignPlus& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_AssignMinus& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_AssignMult& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_AssignDiv& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_AssignExpo& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_AssignMod& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_AssignAnd& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_AssignOr& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_AssignXor& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Op_AssignConcat& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		
		/**************************
		 * 		Constant token    *
		 **************************/
		
		virtual void visit( ast::String& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Character& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Integer& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Float& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Bool& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		
		/**************************************
		 * 		Datastructure non-terminal    *
		 **************************************/
		
		virtual void visit( ast::Array& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::List& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::MakeSequenceList& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::MakeSequenceArray& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		
		/************************************
		 * 		Declaration non-terminal    *
		 ************************************/
		
		virtual void visit( ast::DeclFunc& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::DeclVars& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::ParamList& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Param& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		
		/***********************************
		 * 		Expression non-terminal    *
		 ***********************************/
		 
		virtual void visit( ast::Expression& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::ModifyingExpression& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::DatastructureAccess& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		
		/*************************************
		 * 		FunctionCall non-terminal    *
		 *************************************/
		
		virtual void visit( ast::ArgList& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Argument& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::SoyFunc& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		
		/********************************
		 * 		Program non-terminal    *
		 ********************************/
		
		virtual void visit( ast::Program& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};

		/**********************************
		 * 		Statement non-terminal    *
		 **********************************/
		
		virtual void visit( ast::Statement& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Return& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Menu& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::MenuDef& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::MenuCase& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Roll& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Foreach& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::For& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::ForInitializer& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::ForUpdate& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Conditional& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};
		virtual void visit( ast::Elseif& token) {for(auto it = token.get_children().begin() ; it != token.get_children().end() ; ++it)
		(*it)->accept(*this);};


private:
	SymbolTable<FunctionInfo>& function_table;
	SymbolTable<VariableInfo>& variable_table;
	
};

#endif

