#ifndef NT_FUNCTIONCALL_HPP_DEFINED
#define NT_FUNCTIONCALL_HPP_DEFINED

#include "NonTerminal.hpp"
#include "NT_Program.hpp"
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
		size_t nb_args() const;
	};

	class FuncCall : public NT_FunctionCall
	{
	public:
		// Constructors
		FuncCall(ASTNode*, ArgList*);
		FuncCall(ASTNode*, ArgList*, int,int,int,int);
		FuncCall(ASTNode*, ArgList*, const NodeLocation&);

		virtual void accept(ASTVisitor&);
		// either an id or a function call
		ASTNode& get_function();
		/**
		 * @throws NoSuchChildException If there is no argument list
		 */
		ArgList& get_arg_list();
		bool contains_arglist() const { return has_arglist; };
		std::string& get_function_name();

	private:
		bool has_arglist;
	};
}

#endif
