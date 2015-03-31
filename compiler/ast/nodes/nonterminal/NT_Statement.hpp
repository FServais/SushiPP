#ifndef NT_STATEMENT_HPP_DEFINED
#define NT_STATEMENT_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals::nt_statement
{
	/*********************************************
	 * Intermediate NT_Statement node base class *
	 *********************************************/
	class NT_Statement : public NonTerminal
	{
	public:
		// Constructors
		NT_Statement();
		NT_Statement(int,int,int,int);
		NT_Statement(const ast::nodes::NodeLocation&);
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
		Statement(const ast::nodes::NodeLocation&);
	};

	class Return : public NT_Statement
	{
	public:
		// Constructors
		Return();
		Return(int,int,int,int);
		Return(const ast::nodes::NodeLocation&);
	};

	class Menu : public NT_Statement
	{
	public:
		// Constructors
		Menu();
		Menu(int,int,int,int);
		Menu(const ast::nodes::NodeLocation&);
	};

	class MenuDef : public NT_Statement
	{
	public:
		// Constructors
		MenuDef();
		MenuDef(int,int,int,int);
		MenuDef(const ast::nodes::NodeLocation&);
	};

	class Loop : public NT_Statement
	{
	public:
		// Constructors
		Loop();
		Loop(int,int,int,int);
		Loop(const ast::nodes::NodeLocation&);
	};

	class Roll : public NT_Statement
	{
	public:
		// Constructors
		Roll();
		Roll(int,int,int,int);
		Roll(const ast::nodes::NodeLocation&);
	};

	class Foreach : public NT_Statement
	{
	public:
		// Constructors
		Foreach();
		Foreach(int,int,int,int);
		Foreach(const ast::nodes::NodeLocation&);
	};

	class For : public NT_Statement
	{
	public:
		// Constructors
		For();
		For(int,int,int,int);
		For(const ast::nodes::NodeLocation&);
	};

	class ForInitializer : public NT_Statement
	{
	public:
		// Constructors
		ForInitializer();
		ForInitializer(int,int,int,int);
		ForInitializer(const ast::nodes::NodeLocation&);
	};

	class ForUpdate : public NT_Statement
	{
	public:
		// Constructors
		ForUpdate();
		ForUpdate(int,int,int,int);
		ForUpdate(const ast::nodes::NodeLocation&);
	};

	class Conditional : public NT_Statement
	{
	public:
		// Constructors
		Conditional();
		Conditional(int,int,int,int);
		Conditional(const ast::nodes::NodeLocation&);
	};

	class Elseif : public NT_Statement
	{
	public:
		// Constructors
		Elseif();
		Elseif(int,int,int,int);
		Elseif(const ast::nodes::NodeLocation&);
	};
}

#endif
