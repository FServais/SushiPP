#ifndef NT_PROGRAM_HPP_DEFINED
#define NT_PROGRAM_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals::nt_program
{

	/********************************
	 * Program rules node base class *
	 ********************************/
	class Program : public NT_Program
	{
	public:
		// Constructors
		Program(const std::string&);
		Program(const std::string&,int,int,int,int);
		Program(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Empty : public NT_Program
	{
	public:
		// Constructors
		Empty(const std::string&);
		Empty(const std::string&,int,int,int,int);
		Empty(const std::string&,const ast::nodes::NodeLocation&);
	};

	class ScopeBody : public NT_Program
	{
	public:
		// Constructors
		ScopeBody(const std::string&);
		ScopeBody(const std::string&,int,int,int,int);
		ScopeBody(const std::string&,const ast::nodes::NodeLocation&);
	};

	class ProgramElement : public NT_Program
	{
	public:
		// Constructors
		ProgramElement(const std::string&);
		ProgramElement(const std::string&,int,int,int,int);
		ProgramElement(const std::string&,const ast::nodes::NodeLocation&);
	};

	class Scope : public NT_Program
	{
	public:
		// Constructors
		Scope(const std::string&);
		Scope(const std::string&,int,int,int,int);
		Scope(const std::string&,const ast::nodes::NodeLocation&);
	};


}

#endif