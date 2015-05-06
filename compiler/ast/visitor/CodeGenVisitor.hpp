
#ifndef CodeGenVisitor_HPP_DEFINED
#define CodeGenVisitor_HPP_DEFINED

#include <iostream>
#include <string>
#include <stack>

/*
#include "llvm/IR/Verifier.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
*/

#include "ASTVisitor.hpp"
#include "../../codegen/Builder.hpp"
#include "../../codegen/Variable.hpp"
#include "../../codegen/LabelManager.hpp"
#include "../../codegen/Constant.hpp"

#include "../../symb/SymbolTable.hpp"
#include "../../symb/SymbolInfo.hpp"
#include "../../inference/TypeSymbolTable.hpp"

namespace visitor
{
	class CodeGenVisitor : public ASTVisitor
	{
	public:
		CodeGenVisitor(symb::SymbolTable<symb::VariableInfo>& variable_table, symb::SymbolTable<symb::FunctionInfo>& function_table, inference::TypeSymbolTable& type_table); // arg: the stream in which to output the tree

		virtual void visit( ast::ASTNode& );

		/******************************
		 * 		Identifier token      *
		 ******************************/
		virtual void visit( ast::Identifier& );

		/*************************
		 * 		Keyword token    *
		 *************************/

		virtual void visit( ast::K_Break& );
		virtual void visit( ast::K_Continue& );
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

		virtual void visit( ast::Op_Plus& ); // Int or float
		virtual void visit( ast::Op_Minus& ); // Int or float
		virtual void visit( ast::Op_Mult& ); // Int or float
		virtual void visit( ast::Op_Div& ); // Int or float
		virtual void visit( ast::Op_Modulo& ); // Int
		virtual void visit( ast::Op_Exponentiation& ); // Base is int of float
		virtual void visit( ast::Op_UnaryMinus& ); // Int or float
		virtual void visit( ast::Op_BitwiseOr& ); // int
		virtual void visit( ast::Op_BitwiseAnd& ); // int
		virtual void visit( ast::Op_BitwiseXor& ); // int
		virtual void visit( ast::Op_BitwiseNot& ); // int
		virtual void visit( ast::Op_LogicalOr& ); // bool
		virtual void visit( ast::Op_LogicalAnd& ); // bool
		virtual void visit( ast::Op_LogicalNot& ); // bool
		virtual void visit( ast::Op_CompLessThan& ); // Int or float for operand, returns bool
		virtual void visit( ast::Op_CompGreaterThan& ); // Int or float for operand, returns bool
		virtual void visit( ast::Op_CompLessEqual& ); // Int or float for operand, returns bool
		virtual void visit( ast::Op_CompGreaterEqual& ); // Int or float for operand, returns bool
		virtual void visit( ast::Op_CompEqual& ); // Int, float or bool, returns bool
		virtual void visit( ast::Op_CompNotEqual& ); // Int, float or bool, returns bool
		virtual void visit( ast::Op_LeftShift& ); // int
		virtual void visit( ast::Op_RightShift& ); // int
		virtual void visit( ast::Op_StringConcat& ); // string
		virtual void visit( ast::Op_PrefixIncrement& ); // Int or float
		virtual void visit( ast::Op_PrefixDecrement& ); // Int or float
		virtual void visit( ast::Op_PostfixIncrement& ); // Int or float
		virtual void visit( ast::Op_PostfixDecrement& ); // Int or float
		virtual void visit( ast::Op_Assignment& ); // Whatever
		virtual void visit( ast::Op_AssignPlus& ); // Int or float
		virtual void visit( ast::Op_AssignMinus& ); // Int or float
		virtual void visit( ast::Op_AssignMult& ); // Int or float
		virtual void visit( ast::Op_AssignDiv& );
		virtual void visit( ast::Op_AssignExpo& );
		virtual void visit( ast::Op_AssignMod& ); // int
		virtual void visit( ast::Op_AssignAnd& );
		virtual void visit( ast::Op_AssignOr& );
		virtual void visit( ast::Op_AssignXor& );
		virtual void visit( ast::Op_AssignConcat& ); // String

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


		void visit_children( ast::ASTNode& );

		void print(std::ostream&);

	private:
		codegen::Builder builder;
		codegen::Module& curr_module;
		std::string curr_func_name;

		codegen::LabelManager label_manager;

		symb::SymbolTable<symb::VariableInfo>& variable_table;
		symb::SymbolTable<symb::FunctionInfo>& function_table;
		inference::TypeSymbolTable& type_table;


		/* Vector */
		std::vector<std::unique_ptr<codegen::Value>> return_vector;

		void add_return(codegen::Value*);
		codegen::Value& top();
		void pop();

		codegen::Value& get_return_value(int n);
		void remove_return_value(int n);

		std::vector<codegen::Value*> get_n_return_values(int n);
		void pop_n_return_values(int n);

		bool is_vector_empty() const;
		int get_vector_size() const;


		/*
		llvm::Module *the_module;
		llvm::IRBuilder<> builder;
		std::map<std::string, llvm::Value*> NamedValues;
		*/

		//errors::ErrorHandler& error_handler;
	};
}

#endif
