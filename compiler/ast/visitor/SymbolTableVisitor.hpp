
#ifndef SymbolTableVisitor_HPP_DEFINED
#define SymbolTableVisitor_HPP_DEFINED


#include "../../symb/SymbolTable.hpp"
#include "../../symb/SymbolInfo.hpp"
#include "../../exceptions/Exceptions.hpp"
#include "../../errors/ErrorHandler.hpp"
#include "../../util.hpp"
#include "ASTVisitor.hpp"
#include <set>

using namespace symb;

namespace visitor 
{
	class SymbolTableVisitor : public ASTVisitor
	{
	public:

		// constructor & destructor
		SymbolTableVisitor(SymbolTable<FunctionInfo>& , SymbolTable<VariableInfo>& , errors::ErrorHandler&);
		~SymbolTableVisitor(){};

		virtual void visit( ast::ASTNode& );
		virtual void visit( ast::DeclVar& );
		virtual void visit( ast::FuncCall&  );
		virtual void visit( ast::Identifier& );
		virtual void visit( ast::Scope& );

		/**
		*	@brief	checks whether the symbol is declared in the table for the  allowed scopes 
		*	@param 		std::string&			the symbol name
		*	@param 		symb::SymbolTable<S>& 	the table
		*	@ retval 	true if the symbol is declared in one of the scopes	
		*/
		template<class S>
		bool symbol_exists(std::string& , symb::SymbolTable<S>& );



		/**
		*	@brief 		Generate errors when it find variables declared but never used
		*	@param 		size_t scope 		the id of the scope that we are checking
		*
		*/
		void check_unused(size_t scope);
		/*************************
		 * 		Keyword token    *
		 *************************/
		 
		virtual void visit( ast::K_Continue& );
		virtual void visit( ast::K_Break& );
		virtual void visit( ast::Type_Int& );
		virtual void visit( ast::Type_Float& );
		virtual void visit( ast::Type_Char& );
		virtual void visit( ast::Type_String& );
		virtual void visit( ast::Type_Array& );
		virtual void visit( ast::Type_List& );
		virtual void visit( ast::Type_Bool& );
		
		/**************************
		 * 		Operator token    *
		 **************************/
		
		virtual void visit( ast::Op_Plus& );
		virtual void visit( ast::Op_Minus& );
		virtual void visit( ast::Op_Mult& );
		virtual void visit( ast::Op_Div& );
		virtual void visit( ast::Op_Modulo& );
		virtual void visit( ast::Op_Exponentiation& );
		virtual void visit( ast::Op_UnaryMinus& );
		virtual void visit( ast::Op_BitwiseOr& );
		virtual void visit( ast::Op_BitwiseAnd& );
		virtual void visit( ast::Op_BitwiseXor& );
		virtual void visit( ast::Op_BitwiseNot& );
		virtual void visit( ast::Op_LogicalOr& );
		virtual void visit( ast::Op_LogicalAnd& );
		virtual void visit( ast::Op_LogicalNot& );
		virtual void visit( ast::Op_CompLessThan& );
		virtual void visit( ast::Op_CompGreaterThan& );
		virtual void visit( ast::Op_CompLessEqual& );
		virtual void visit( ast::Op_CompGreaterEqual& );
		virtual void visit( ast::Op_CompEqual& );
		virtual void visit( ast::Op_CompNotEqual& );
		virtual void visit( ast::Op_LeftShift& );
		virtual void visit( ast::Op_RightShift& );
		virtual void visit( ast::Op_StringConcat& );
		virtual void visit( ast::Op_PrefixIncrement& );
		virtual void visit( ast::Op_PrefixDecrement& );
		virtual void visit( ast::Op_PostfixIncrement& );
		virtual void visit( ast::Op_PostfixDecrement& );
		virtual void visit( ast::Op_Assignment& );
		virtual void visit( ast::Op_AssignPlus& );
		virtual void visit( ast::Op_AssignMinus& );
		virtual void visit( ast::Op_AssignMult& );
		virtual void visit( ast::Op_AssignDiv& );
		virtual void visit( ast::Op_AssignExpo& );
		virtual void visit( ast::Op_AssignMod& );
		virtual void visit( ast::Op_AssignAnd& );
		virtual void visit( ast::Op_AssignOr& );
		virtual void visit( ast::Op_AssignXor& );
		virtual void visit( ast::Op_AssignConcat& );
		
		/**************************
		 * 		Constant token    *
		 **************************/
		
		virtual void visit( ast::String& );
		virtual void visit( ast::Character& );
		virtual void visit( ast::Integer& );
		virtual void visit( ast::Float& );
		virtual void visit( ast::Bool& );
		
		/**************************************
		 * 		Datastructure non-terminal    *
		 **************************************/
		
		virtual void visit( ast::Array& );
		virtual void visit( ast::List& );
		virtual void visit( ast::MakeSequenceList& );
		virtual void visit( ast::MakeSequenceArray& );
		
		/************************************
		 * 		Declaration non-terminal    *
		 ************************************/
		
		virtual void visit( ast::DeclFunc& );
		virtual void visit( ast::DeclVars& );
		virtual void visit( ast::ParamList& );
		virtual void visit( ast::Param& );
		
		/***********************************
		 * 		Expression non-terminal    *
		 ***********************************/
		 
		virtual void visit( ast::Expression& );
		virtual void visit( ast::ModifyingExpression& );
		virtual void visit( ast::DatastructureAccess& );
		
		/*************************************
		 * 		FunctionCall non-terminal    *
		 *************************************/
		
		virtual void visit( ast::ArgList& );
		virtual void visit( ast::Argument& );
		virtual void visit( ast::SoyFunc& );
		
		/********************************
		 * 		Program non-terminal    *
		 ********************************/
		
		virtual void visit( ast::Program& );

		/**********************************
		 * 		Statement non-terminal    *
		 **********************************/
		
		virtual void visit( ast::Statement& );
		virtual void visit( ast::Return& );
		virtual void visit( ast::Menu& );
		virtual void visit( ast::MenuDef& );
		virtual void visit( ast::MenuCase& );
		virtual void visit( ast::Roll& );
		virtual void visit( ast::Foreach& );
		virtual void visit( ast::For& );
		virtual void visit( ast::ForInitializer& );
		virtual void visit( ast::ForUpdate& );
		virtual void visit( ast::Conditional& );
		virtual void visit( ast::Elseif& );


	private:
		SymbolTable<FunctionInfo>& function_table;
		SymbolTable<VariableInfo>& variable_table;
		errors::ErrorHandler& error_handler;

		std::set<size_t> allowed_scopes;
		std::set<size_t> prev_allowed_scopes;

			
		void visit_children( ast::ASTNode& );
	};
}

#endif

