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
		NT_FunctionCall(const std::string&);
		NT_FunctionCall(const std::string&,int,int,int,int);
		NT_FunctionCall(const std::string&,const ast::nodes::NodeLocation&);
	};

	/***************************************
	 * Function call rules node base class *
	 ***************************************/
	class FuncCall : public NT_FunctionCall
	{
	public:
		// Constructors
		FuncCall(const std::string&);
		FuncCall(const std::string&,int,int,int,int);
		FuncCall(const std::string&,const ast::nodes::NodeLocation&);
	};

	class ArgList : public NT_FunctionCall
	{
	public:
		// Constructors
		ArgList(const std::string&);
		ArgList(const std::string&,int,int,int,int);
		ArgList(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Argument : public NT_FunctionCall
	{
	public:
		// Constructors
		Argument(const std::string&);
		Argument(const std::string&,int,int,int,int);
		Argument(const std::string&,const ast::nodes::NodeLocation&);
	};

	class BracedFuncCall : public NT_FunctionCall
	{
	public:
		// Constructors
		BracedFuncCall(const std::string&);
		BracedFuncCall(const std::string&,int,int,int,int);
		BracedFuncCall(const std::string&,const ast::nodes::NodeLocation&);
	};

	class FuncCallEol : public NT_FunctionCall
	{
	public:
		// Constructors
		FuncCallEol(const std::string&);
		FuncCallEol(const std::string&,int,int,int,int);
		FuncCallEol(const std::string&,const ast::nodes::NodeLocation&);
	};

	class ArgListEol : public NT_FunctionCall
	{
	public:
		// Constructors
		ArgListEol(const std::string&);
		ArgListEol(const std::string&,int,int,int,int);
		ArgListEol(const std::string&,const ast::nodes::NodeLocation&);
	};

	class SoyExpression : public NT_FunctionCall
	{
	public:
		// Constructors
		SoyExpression(const std::string&);
		SoyExpression(const std::string&,int,int,int,int);
		SoyExpression(const std::string&,const ast::nodes::NodeLocation&);
	};

	class SoyFunc : public NT_FunctionCall
	{
	public:
		// Constructors
		SoyFunc(const std::string&);
		SoyFunc(const std::string&,int,int,int,int);
		SoyFunc(const std::string&,const ast::nodes::NodeLocation&);
	};
}

#endif
