#ifndef NT_FUNCTIONCALL_HPP_DEFINED
#define NT_FUNCTIONCALL_HPP_DEFINED

#include "NonTerminal.hpp"

namespace ast
{
	/*********************************************
	 * Intermediate NT_FunctionCall node base class *
	 *********************************************/
	class NT_FunctionCall : public NonTerminal
	{
	public:
		// Constructors
		NT_FunctionCall(const std::string&);
		NT_FunctionCall(const std::string&,int,int,int,int);
		NT_FunctionCall(const std::string&,const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	/***************************************
	 * Function call rules node base class *
	 ***************************************/
	class FuncCall : public NT_FunctionCall
	{
	public:
		// Constructors
		FuncCall();
		FuncCall(int,int,int,int);
		FuncCall(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class ArgList : public NT_FunctionCall
	{
	public:
		// Constructors
		ArgList();
		ArgList(int,int,int,int);
		ArgList(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Argument : public NT_FunctionCall
	{
	public:
		// Constructors
		Argument();
		Argument(int,int,int,int);
		Argument(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class BracedFuncCall : public NT_FunctionCall
	{
	public:
		// Constructors
		BracedFuncCall();
		BracedFuncCall(int,int,int,int);
		BracedFuncCall(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class FuncCallEol : public NT_FunctionCall
	{
	public:
		// Constructors
		FuncCallEol();
		FuncCallEol(int,int,int,int);
		FuncCallEol(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class ArgListEol : public NT_FunctionCall
	{
	public:
		// Constructors
		ArgListEol();
		ArgListEol(int,int,int,int);
		ArgListEol(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class SoyExpression : public NT_FunctionCall
	{
	public:
		// Constructors
		SoyExpression();
		SoyExpression(int,int,int,int);
		SoyExpression(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class SoyFunc : public NT_FunctionCall
	{
	public:
		// Constructors
		SoyFunc();
		SoyFunc(int,int,int,int);
		SoyFunc(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};
}

#endif
