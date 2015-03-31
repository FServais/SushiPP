#ifndef NT_STATEMENT_HPP_DEFINED
#define NT_STATEMENT_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals::nt_statement
{

	/***********************************
	 * Statement rules node base class *
	 ***********************************/
	class Statement : public NT_Statement
	{
	public:
		// Constructors
		Statement(const std::string&);
		Statement(const std::string&,int,int,int,int);
		Statement(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Return : public NT_Statement
	{
	public:
		// Constructors
		Return(const std::string&);
		Return(const std::string&,int,int,int,int);
		Return(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Menu : public NT_Statement
	{
	public:
		// Constructors
		Menu(const std::string&);
		Menu(const std::string&,int,int,int,int);
		Menu(const std::string&,const ast::nodes::NodeLocation&);
	};

	class MenuDef : public NT_Statement
	{
	public:
		// Constructors
		MenuDef(const std::string&);
		MenuDef(const std::string&,int,int,int,int);
		MenuDef(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Loop : public NT_Statement
	{
	public:
		// Constructors
		Loop(const std::string&);
		Loop(const std::string&,int,int,int,int);
		Loop(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Roll : public NT_Statement
	{
	public:
		// Constructors
		Roll(const std::string&);
		Roll(const std::string&,int,int,int,int);
		Roll(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Foreach : public NT_Statement
	{
	public:
		// Constructors
		Foreach(const std::string&);
		Foreach(const std::string&,int,int,int,int);
		Foreach(const std::string&,const ast::nodes::NodeLocation&);
	};

	class For : public NT_Statement
	{
	public:
		// Constructors
		For(const std::string&);
		For(const std::string&,int,int,int,int);
		For(const std::string&,const ast::nodes::NodeLocation&);
	};

	class ForInitializer : public NT_Statement
	{
	public:
		// Constructors
		ForInitializer(const std::string&);
		ForInitializer(const std::string&,int,int,int,int);
		ForInitializer(const std::string&,const ast::nodes::NodeLocation&);
	};

	class ForUpdate : public NT_Statement
	{
	public:
		// Constructors
		ForUpdate(const std::string&);
		ForUpdate(const std::string&,int,int,int,int);
		ForUpdate(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Conditional : public NT_Statement
	{
	public:
		// Constructors
		Conditional(const std::string&);
		Conditional(const std::string&,int,int,int,int);
		Conditional(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Elseif : public NT_Statement
	{
	public:
		// Constructors
		Elseif(const std::string&);
		Elseif(const std::string&,int,int,int,int);
		Elseif(const std::string&,const ast::nodes::NodeLocation&);
	};
}

#endif
