#ifndef NT_PROGRAM_HPP_DEFINED
#define NT_PROGRAM_HPP_DEFINED

#include "NonTerminal.hpp"

namespace ast
{
	/*********************************************
	 * Intermediate NT_Program node base class *
	 *********************************************/
	class NT_Program : public NonTerminal
	{
	public:
		// Constructors
		NT_Program(const std::string&);
		NT_Program(const std::string&,int,int,int,int);
		NT_Program(const std::string&,const NodeLocation&);
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
		Program(const NodeLocation&);
	};

	class ScopeBody : public NT_Program
	{
	public:
		// Constructors
		ScopeBody();
		ScopeBody(int,int,int,int);
		ScopeBody(const NodeLocation&);
	};

	class ProgramElement : public NT_Program
	{
	public:
		// Constructors
		ProgramElement();
		ProgramElement(int,int,int,int);
		ProgramElement(const NodeLocation&);
	};

	class Scope : public NT_Program
	{
	public:
		// Constructors
		Scope();
		Scope(int,int,int,int);
		Scope(const NodeLocation&);
	};
}

#endif
