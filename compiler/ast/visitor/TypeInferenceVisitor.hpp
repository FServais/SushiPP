#ifndef TYPE_INFERENCE_VISITOR_HPP_DEFINED
#define TYPE_INFERENCE_VISITOR_HPP_DEFINED

#include <iostream>
#include <string>

#include "ASTVisitor.hpp"

namespace ast 
{
	class TypeInferenceVisitor : public ASTVisitor
	{
	public:
		TypeInferenceVisitor();

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

		virtual void visit( ast::Datastructure& );
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
		virtual void visit( ast::IncrExpression& );
		virtual void visit( ast::Assignment& );
		virtual void visit( ast::ModifyingExpression& );
		virtual void visit( ast::AssignableExpression& );
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
		virtual void visit( ast::MenuDef& );
		virtual void visit( ast::Roll& );
		virtual void visit( ast::Foreach& );
		virtual void visit( ast::For& );
		virtual void visit( ast::ForInitializer& );
		virtual void visit( ast::ForUpdate& );
		virtual void visit( ast::Conditional& );
		virtual void visit( ast::Elseif& );

	private:
		/**
		 * These table maps symbols with their associated link type pointing the their type 
		 * Symbols are either symbols from the soure program or type variables
		 */
		std::unordered_map<std::string, inference::LinkType&> type_symbol_table;

		/** Common flat types objects */
		inference::Int type_int;
		inference::Bool type_bool;
		inference::String type_string;
		inference::Char type_char;
		inference::Float type_float;
		inference::Void type_void;

		/** 
		 * Stack of TypeLink reference to emulate parameter passing 
		 * The variable parameter_count counts the number of parameters that were passed
		 */
		size_t parameter_count;
		std::stack<inference::TypeLink&> parameters;

		/** Counts the number of generated type variable */
		static size_t type_variable_cnt;

		/**
		 * @brief Generate a new (unique) type variable name
		 * @retval std::string The brand new variable name
		 */
		static std::string new_type_variable_name();

		/**
		 * @brief Checks whether the number of parameters match the one expected
		 * @param size_t expected Expected number of parameters
		 * @throw BadParameterNumberException if the number of expected parameters doesn't match the number of given parameters
		 */
		void check_params(size_t);

		/**
		 * @brief Add a parameter for the next call
		 * @param inference::TypeLink link The link to pass as parameter
		 */
		void add_param(inference::TypeLink&);

		/**
		 * @brief Get a parameter from the parameter stack
		 * @param inference::TypeLink& The reference to the link node parameter
		 * @throw BadParameterNumberException If no parameters are available anymore
		 */
		inference::TypeLink& get_param();
	};
}

#endif // TYPE_INFERENCE_VISITOR_HPP_DEFINED