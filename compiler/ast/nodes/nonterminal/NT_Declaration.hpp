#ifndef NT_DECLARATION_HPP_DEFINED
#define NT_DECLARATION_HPP_DEFINED

#include <string>
#include "NonTerminal.hpp"
#include "../NodeLocation.hpp"

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

		virtual void accept(ASTVisitor&);
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

		virtual void accept(ASTVisitor&);
	};

	class DeclFunc : public NT_Declaration
	{
	public:
		// Constructors
		DeclFunc();
		DeclFunc(int,int,int,int);
		DeclFunc(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class DeclVars : public NT_Declaration
	{
	public:
		// Constructors
		DeclVars();
		DeclVars(int,int,int,int);
		DeclVars(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class DeclVar : public NT_Declaration
	{
	public:
		// Constructors
		DeclVar();
		DeclVar(int,int,int,int);
		DeclVar(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class ParamList : public NT_Declaration
	{
	public:
		// Constructors
		ParamList();
		ParamList(int,int,int,int);
		ParamList(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};

	class Param : public NT_Declaration
	{
	public:
		// Constructors
		Param();
		Param(int,int,int,int);
		Param(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};
}

#endif
