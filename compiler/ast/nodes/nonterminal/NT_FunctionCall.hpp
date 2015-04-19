#ifndef NT_FUNCTIONCALL_HPP_DEFINED
#define NT_FUNCTIONCALL_HPP_DEFINED

#include "NonTerminal.hpp"
#include "../tokens/Token.hpp"

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
		FuncCall(Identifier*, ArgList*);
		FuncCall(Identifier*, ArgList*, int,int,int,int);
		FuncCall(Identifier*, ArgList*, const NodeLocation&);

		virtual void accept(ASTVisitor&);
		Identifier& get_id();
		ArgList& get_arg_list();
	};

	class ArgList : public NT_FunctionCall
	{
	public:
		// Constructors
		ArgList(Argument*);
		ArgList(Argument*,int,int,int,int);
		ArgList(Argument*, const NodeLocation&);

		virtual void accept(ASTVisitor&);
		void add_argument(Argument*);
		Argument& get_arg(size_t);
	};

	class Argument : public NT_FunctionCall
	{
	public:
		// Constructors
		Argument(ASTNode*);
		Argument(ASTNode*, int,int,int,int);
		Argument(ASTNode*, const NodeLocation&);

		virtual void accept(ASTVisitor&);
		ASTNode& get_child();


	};
	
	class SoyFunc : public NT_FunctionCall
	{
	public:
		// Constructors
		SoyFunc(ArgList*, Scope*);
		SoyFunc(ArgList*, Scope*, int,int,int,int);
		SoyFunc(ArgList*, Scope*, const NodeLocation&);

		virtual void accept(ASTVisitor&);
		ArgList& get_arg_list();
		Scope& get_scope();
	};
}

#endif
