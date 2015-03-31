#ifndef NT_DECLARATION_HPP_DEFINED
#define NT_DECLARATION_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals::nt_declaration
namespace ast::nodes::nonterminals::NonTerminal
{
	/*********************************************
	 * Intermediate NT_Declaration node base class *
	 *********************************************/
	class NT_Declaration : public NonTerminal
	{
	public:
		// Constructors
		NT_Declaration();
		NT_Declaration(int,int,int,int);
		NT_Declaration(const ast::nodes::NodeLocation&);
	};

	/*************************************
	 * Declaration rules node base class *
	 *************************************/
	class Declaration : public NT_Declaration
	{
	public:
		// Constructors
		Declaration();
		Declaration(int,int,int,int);
		Declaration(const ast::nodes::NodeLocation&);
	};

	class DeclFunc : public NT_Declaration
	{
	public:
		// Constructors
		DeclFunc();
		DeclFunc(int,int,int,int);
		DeclFunc(const ast::nodes::NodeLocation&);
	};

	class DeclVars : public NT_Declaration
	{
	public:
		// Constructors
		DeclVars();
		DeclVars(int,int,int,int);
		DeclVars(const ast::nodes::NodeLocation&);
	};

	class DeclVar : public NT_Declaration
	{
	public:
		// Constructors
		DeclVar();
		DeclVar(int,int,int,int);
		DeclVar(const ast::nodes::NodeLocation&);
	};

	class ParamList : public NT_Declaration
	{
	public:
		// Constructors
		ParamList();
		ParamList(int,int,int,int);
		ParamList(const ast::nodes::NodeLocation&);
	};

	class Param : public NT_Declaration
	{
	public:
		// Constructors
		Param();
		Param(int,int,int,int);
		Param(const ast::nodes::NodeLocation&);
	};


}

#endif
