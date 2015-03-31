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
}

#endif
