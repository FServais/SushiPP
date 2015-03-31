#ifndef NT_PROGRAM_HPP_DEFINED
#define NT_PROGRAM_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals::nt_program
{
	/*********************************************
	 * Intermediate NT_Program node base class *
	 *********************************************/
	class NT_Program : public NonTerminal
	{
	public:
		// Constructors
		NT_Program();
		NT_Program(int,int,int,int);
		NT_Program(const ast::nodes::NodeLocation&);
	};

	/********************************
	 * Program rules node base class *
	 ********************************/
	class Program : public NT_Program
	{
	public:
		// Constructors
		Program();
		Program(int,int,int,int);
		Program(const ast::nodes::NodeLocation&);
	};

	class ScopeBody : public NT_Program
	{
	public:
		// Constructors
		ScopeBody();
		ScopeBody(int,int,int,int);
		ScopeBody(const ast::nodes::NodeLocation&);
	};

	class ProgramElement : public NT_Program
	{
	public:
		// Constructors
		ProgramElement();
		ProgramElement(int,int,int,int);
		ProgramElement(const ast::nodes::NodeLocation&);
	};

	class Scope : public NT_Program
	{
	public:
		// Constructors
		Scope();
		Scope(int,int,int,int);
		Scope(const ast::nodes::NodeLocation&);
	};


}

#endif
