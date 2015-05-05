#ifndef TYPE_INFERENCE_VISITOR_HPP_DEFINED
#define TYPE_INFERENCE_VISITOR_HPP_DEFINED

#include <iostream>
#include <string>
#include <memory>

#include "ASTVisitor.hpp"
#include "VisitorParameters.hpp"
#include "../../inference/TypeSymbolTable.hpp"
#include "../../symb/SymbolTable.hpp"
#include "../../symb/SymbolInfo.hpp"
#include "../../errors/ErrorHandler.hpp"

namespace visitor
{
	class TypeInferenceVisitor : public ASTVisitor
	{
	public:
		/**
		 * @brief Construct tthe TypeInferenceVisitor with the symbol tables
		 * @param errors::ErrorHandler& The error handler
		 * @param symb::SymbolTable<symb::FunctionInfo>& function_table The function table
		 * @param symb::SymbolTable<symb::VariableInfo>& variable_table The variable talble
		 */
		TypeInferenceVisitor(errors::ErrorHandler&, symb::SymbolTable<symb::FunctionInfo>&, symb::SymbolTable<symb::VariableInfo>&);

		/****************
		 * 		Node    *
		 ****************/
		virtual void visit( ast::ASTNode& );

		/******************************
		 * 		Identifier token    *
		 ******************************/
		 
		virtual void visit( ast::Identifier& );

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
		virtual void visit( ast::Type_Function& );

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
		virtual void visit( ast::DeclVar& );
		virtual void visit( ast::ParamList& );
		virtual void visit( ast::Param& );

		/***********************************
		 * 		Expression non-terminal    *
		 ***********************************/

		virtual void visit( ast::Expression& );
		virtual void visit( ast::ExpressionList& );
		virtual void visit( ast::ModifyingExpression& );
		virtual void visit( ast::DatastructureAccess& );

		/*************************************
		 * 		FunctionCall non-terminal    *
		 *************************************/

		virtual void visit( ast::FuncCall& );
		virtual void visit( ast::ArgList& );
		virtual void visit( ast::Argument& );
		virtual void visit( ast::SoyFunc& );

		/********************************
		 * 		Program non-terminal    *
		 ********************************/

		virtual void visit( ast::Program& );
		virtual void visit( ast::Scope& );

		/**********************************
		 * 		Statement non-terminal    *
		 **********************************/

		virtual void visit( ast::Statement& );
		virtual void visit( ast::Return& );
		virtual void visit( ast::Menu& );
		virtual void visit( ast::MenuBody& );
		virtual void visit( ast::MenuDef& );
		virtual void visit( ast::MenuCase& );
		virtual void visit( ast::Roll& );
		virtual void visit( ast::Foreach& );
		virtual void visit( ast::For& );
		virtual void visit( ast::ForInitializer& );
		virtual void visit( ast::ForUpdate& );
		virtual void visit( ast::Conditional& );
		virtual void visit( ast::Elseif& );
		virtual void visit( ast::If& );
		virtual void visit( ast::Else& );

		/**
		 * @brief Return the type table built by the visitor
		 */
		std::shared_ptr<inference::TypeSymbolTable> get_table() { return type_table; }
		const std::shared_ptr<inference::TypeSymbolTable> get_table() const { return type_table; }

	private:
		/**
		 * error_handler : the error handler
		 * type_table : maps type identifiers and their actual value 
		 * params     : an object for emulating parameters passing 
		 * current_scope : the current scope id
		 */
		errors::ErrorHandler& error_handler;
		std::shared_ptr<inference::TypeSymbolTable> type_table;
		VisitorParameters<std::string> params;
		size_t current_scope;

		/**
		 * Symbol tables
		 */
		symb::SymbolTable<symb::FunctionInfo>& function_table;
		symb::SymbolTable<symb::VariableInfo>& variable_table;

		/**
		 * @brief Update the symbol table for a function declaration (either named or anonymous)
		 * @param const ast::ParamList param_list The function parameters list (optionnal: if the function has no parameters)
		 * @param const std::string& func_name The name of the function 
		 * @param size_t scope_id The function body scope id 
		 * @param std::pair<std::string, std::string> The pair containing the type variable name of the function (first)
		 * and of the return value (second)
		 * @note The VisitorParameters object is not modified
		 */
		std::pair<std::string, std::string> add_function_declaration_rule(const ast::ParamList&, const std::string&, size_t);
		std::pair<std::string, std::string> add_function_declaration_rule(const std::string&, size_t);
		
		/**
		 * @brief Check whether, from a scope node, a type variable must be propagate
		 * @retuval bool True if the variable must be propagated, false otherwise
		 * @note A type should be propagated on statement
		 */
		bool propagate_type_from_scope(ast::ASTNode&);
	};
}

#endif // TYPE_INFERENCE_VISITOR_HPP_DEFINED