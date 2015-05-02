
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

namespace visitor
{
	class CodeGenVisitor : public ASTVisitor
	{
	public:
		CodeGenVisitor(std::ostream& out = std::cout); // arg: the stream in which to output the tree

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
		virtual void visit( ast::MenuDef& );
		virtual void visit( ast::MenuCase& );
		virtual void visit( ast::Roll& );
		virtual void visit( ast::Foreach& );
		virtual void visit( ast::For& );
		virtual void visit( ast::ForInitializer& );
		virtual void visit( ast::ForUpdate& );
		virtual void visit( ast::Conditional& );
		virtual void visit( ast::Elseif& );

		void visit_children( ast::ASTNode& );

		void print(std::ostream&);

	private:
		std::ostream& out_; // stream in which to write

		codegen::Builder builder;
		codegen::Module& curr_module;
		std::string curr_func_name;

		/* Stack */
		std::stack<codegen::Value> return_stack;

		void add_return(codegen::Value&);
		codegen::Value pop_return();
		bool is_stack_empty() const;
		int get_stack_size() const;


		/*
		llvm::Module *the_module;
		llvm::IRBuilder<> builder;
		std::map<std::string, llvm::Value*> NamedValues;
		*/

		//errors::ErrorHandler& error_handler;
	};
}

#endif
