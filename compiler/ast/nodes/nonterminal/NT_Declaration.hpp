#ifndef NT_DECLARATION_HPP_DEFINED
#define NT_DECLARATION_HPP_DEFINED

#include "NonTerminal.hpp"

namespace ast
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
		NT_Declaration(const std::string&,const NodeLocation&);
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
		Declaration(const NodeLocation&);
	};

	class DeclFunc : public NT_Declaration
	{
	public:
		// Constructors
		DeclFunc();
		DeclFunc(int,int,int,int);
		DeclFunc(const NodeLocation&);
	};

	class DeclVars : public NT_Declaration
	{
	public:
		// Constructors
		DeclVars();
		DeclVars(int,int,int,int);
		DeclVars(const NodeLocation&);
	};

	class DeclVar : public NT_Declaration
	{
	public:
		// Constructors
		DeclVar();
		DeclVar(int,int,int,int);
		DeclVar(const NodeLocation&);
	};

	class ParamList : public NT_Declaration
	{
	public:
		// Constructors
		ParamList();
		ParamList(int,int,int,int);
		ParamList(const NodeLocation&);
	};

	class Param : public NT_Declaration
	{
	public:
		// Constructors
		Param();
		Param(int,int,int,int);
		Param(const NodeLocation&);
	};
}

#endif
