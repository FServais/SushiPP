#ifndef NT_FUNCTIONCALL_HPP_DEFINED
#define NT_FUNCTIONCALL_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals::nt_functioncall
{
	/*********************************************
	 * Intermediate NT_FunctionCall node base class *
	 *********************************************/
	class NT_FunctionCall : public NonTerminal
	{
	public:
		// Constructors
		NT_FunctionCall();
		NT_FunctionCall(int,int,int,int);
		NT_FunctionCall(const ast::nodes::NodeLocation&);
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
		FuncCall(const ast::nodes::NodeLocation&);
	};

	class ArgList : public NT_FunctionCall
	{
	public:
		// Constructors
		ArgList();
		ArgList(int,int,int,int);
		ArgList(const ast::nodes::NodeLocation&);
	};

	class Argument : public NT_FunctionCall
	{
	public:
		// Constructors
		Argument();
		Argument(int,int,int,int);
		Argument(const ast::nodes::NodeLocation&);
	};

	class BracedFuncCall : public NT_FunctionCall
	{
	public:
		// Constructors
		BracedFuncCall();
		BracedFuncCall(int,int,int,int);
		BracedFuncCall(const ast::nodes::NodeLocation&);
	};

	class FuncCallEol : public NT_FunctionCall
	{
	public:
		// Constructors
		FuncCallEol();
		FuncCallEol(int,int,int,int);
		FuncCallEol(const ast::nodes::NodeLocation&);
	};

	class ArgListEol : public NT_FunctionCall
	{
	public:
		// Constructors
		ArgListEol();
		ArgListEol(int,int,int,int);
		ArgListEol(const ast::nodes::NodeLocation&);
	};

	class SoyExpression : public NT_FunctionCall
	{
	public:
		// Constructors
		SoyExpression();
		SoyExpression(int,int,int,int);
		SoyExpression(const ast::nodes::NodeLocation&);
	};

	class SoyFunc : public NT_FunctionCall
	{
	public:
		// Constructors
		SoyFunc();
		SoyFunc(int,int,int,int);
		SoyFunc(const ast::nodes::NodeLocation&);
	};
}

#endif
