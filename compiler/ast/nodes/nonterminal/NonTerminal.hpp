#ifndef NONTERMINAL_HPP_DEFINED
#define NONTERMINAL_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals
{

	/********************************
	 * Non-terminal node base class *
	 ********************************/
	class NonTerminal : public ast::nodes::ASTNode
	{
	public: 
		// constructors
		// string arg is the token node name 
		NonTerminal(const std::string&);
		// additionnal arguments are for location (see ast node constructors for ordering)
		NonTerminal(const std::string&,int,int,int,int);
		NonTerminal(const std::string&,const ast::nodes::NodeLocation&);	
	};

	/*********************************************
	 * Intermediate non-terminal node base class *
	 *********************************************/
	class NT_Program : public NonTerminal
	{
	public:
		// Constructors
		NT_Program(const std::string&);
		NT_Program(const std::string&,int,int,int,int);
		NT_Program(const std::string&,const ast::nodes::NodeLocation&);
	};

	class NT_Declaration : public NonTerminal
	{
	public:
		// Constructors
		NT_Declaration(const std::string&);
		NT_Declaration(const std::string&,int,int,int,int);
		NT_Declaration(const std::string&,const ast::nodes::NodeLocation&);
	};
	
	class NT_FunctionCall : public NonTerminal
	{
	public:
		// Constructors
		NT_FunctionCall(const std::string&);
		NT_FunctionCall(const std::string&,int,int,int,int);
		NT_FunctionCall(const std::string&,const ast::nodes::NodeLocation&);
	};

	class NT_Expression : public NonTerminal
	{
	public:
		// Constructors
		NT_Expression(const std::string&);
		NT_Expression(const std::string&,int,int,int,int);
		NT_Expression(const std::string&,const ast::nodes::NodeLocation&);
	};

	class NT_Constant : public NonTerminal
	{
	public:
		// Constructors
		NT_Constant(const std::string&);
		NT_Constant(const std::string&,int,int,int,int);
		NT_Constant(const std::string&,const ast::nodes::NodeLocation&);
	};

	class NT_Datastructure : public NonTerminal
	{
	public:
		// Constructors
		NT_Datastructure(const std::string&);
		NT_Datastructure(const std::string&,int,int,int,int);
		NT_Datastructure(const std::string&,const ast::nodes::NodeLocation&);
	};

	class NT_Statement : public NonTerminal
	{
	public:
		// Constructors
		NT_Statement(const std::string&);
		NT_Statement(const std::string&,int,int,int,int);
		NT_Statement(const std::string&,const ast::nodes::NodeLocation&);
	};

}

#endif
