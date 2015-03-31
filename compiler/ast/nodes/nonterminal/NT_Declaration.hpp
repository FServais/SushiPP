#ifndef NT_DECLARATION_HPP_DEFINED
#define NT_DECLARATION_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals::nt_declaration
{
	/*********************************************
	 * Intermediate NT_Declaration node base class *
	 *********************************************/
	class NT_Declaration : public NonTerminal
	{
	public:
		// Constructors
		NT_Declaration(const std::string&);
		NT_Declaration(const std::string&,int,int,int,int);
		NT_Declaration(const std::string&,const ast::nodes::NodeLocation&);
	};

	/*************************************
	 * Declaration rules node base class *
	 *************************************/
	class Declaration : public NT_Declaration
	{
	public:
		// Constructors
		Declaration(const std::string&);
		Declaration(const std::string&,int,int,int,int);
		Declaration(const std::string&,const ast::nodes::NodeLocation&);
	};

	class DeclFunc : public NT_Declaration
	{
	public:
		// Constructors
		DeclFunc(const std::string&);
		DeclFunc(const std::string&,int,int,int,int);
		DeclFunc(const std::string&,const ast::nodes::NodeLocation&);
	};

	class DeclVars : public NT_Declaration
	{
	public:
		// Constructors
		DeclVars(const std::string&);
		DeclVars(const std::string&,int,int,int,int);
		DeclVars(const std::string&,const ast::nodes::NodeLocation&);
	};

	class DeclVar : public NT_Declaration
	{
	public:
		// Constructors
		DeclVar(const std::string&);
		DeclVar(const std::string&,int,int,int,int);
		DeclVar(const std::string&,const ast::nodes::NodeLocation&);
	};

	class ParamList : public NT_Declaration
	{
	public:
		// Constructors
		ParamList(const std::string&);
		ParamList(const std::string&,int,int,int,int);
		ParamList(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Param : public NT_Declaration
	{
	public:
		// Constructors
		Param(const std::string&);
		Param(const std::string&,int,int,int,int);
		Param(const std::string&,const ast::nodes::NodeLocation&);
	};


}

#endif
