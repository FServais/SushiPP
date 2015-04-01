#ifndef NT_STATEMENT_HPP_DEFINED
#define NT_STATEMENT_HPP_DEFINED

#include <string>
#include "NonTerminal.hpp"
#include "../NodeLocation.hpp"

namespace ast
{
	/*********************************************
	 * Intermediate NT_Statement node base class *
	 *********************************************/
	class NT_Statement : public NonTerminal
	{
	public:
		// Constructors
		NT_Statement(const std::string&);
		NT_Statement(const std::string&,int,int,int,int);
		NT_Statement(const std::string&,const NodeLocation&);
	};

	/***********************************
	 * Statement rules node base class *
	 ***********************************/
	class Statement : public NT_Statement
	{
	public:
		// Constructors
		Statement();
		Statement(int,int,int,int);
		Statement(const NodeLocation&);
	};

	class Return : public NT_Statement
	{
	public:
		// Constructors
		Return();
		Return(int,int,int,int);
		Return(const NodeLocation&);
	};

	class Menu : public NT_Statement
	{
	public:
		// Constructors
		Menu();
		Menu(int,int,int,int);
		Menu(const NodeLocation&);
	};

	class MenuBody : public NT_Statement
	{
	public:
		// Constructors
		MenuBody();
		MenuBody(int,int,int,int);
		MenuBody(const NodeLocation&);
	};

	class MenuCase : public NT_Statement
	{
	public:
		// Constructors
		MenuCase();
		MenuCase(int,int,int,int);
		MenuCase(const NodeLocation&);
	};

	class MenuDef : public NT_Statement
	{
	public:
		// Constructors
		MenuDef();
		MenuDef(int,int,int,int);
		MenuDef(const NodeLocation&);
	};

	class Loop : public NT_Statement
	{
	public:
		// Constructors
		Loop();
		Loop(int,int,int,int);
		Loop(const NodeLocation&);
	};

	class Roll : public NT_Statement
	{
	public:
		// Constructors
		Roll();
		Roll(int,int,int,int);
		Roll(const NodeLocation&);
	};

	class Foreach : public NT_Statement
	{
	public:
		// Constructors
		Foreach();
		Foreach(int,int,int,int);
		Foreach(const NodeLocation&);
	};

	class For : public NT_Statement
	{
	public:
		// Constructors
		For();
		For(int,int,int,int);
		For(const NodeLocation&);
	};

	class ForInitializer : public NT_Statement
	{
	public:
		// Constructors
		ForInitializer();
		ForInitializer(int,int,int,int);
		ForInitializer(const NodeLocation&);
	};

	class ForUpdate : public NT_Statement
	{
	public:
		// Constructors
		ForUpdate();
		ForUpdate(int,int,int,int);
		ForUpdate(const NodeLocation&);
	};

	class Conditional : public NT_Statement
	{
	public:
		// Constructors
		Conditional();
		Conditional(int,int,int,int);
		Conditional(const NodeLocation&);
	};

	class Elseif : public NT_Statement
	{
	public:
		// Constructors
		Elseif();
		Elseif(int,int,int,int);
		Elseif(const NodeLocation&);
	};
}

#endif
