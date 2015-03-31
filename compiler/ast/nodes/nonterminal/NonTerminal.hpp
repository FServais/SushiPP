#ifndef NONTERMINAL_HPP_DEFINED
#define NONTERMINAL_HPP_DEFINED

#include <string>
#include "../NodeLocation.hpp"
#include "../ASTNode.hpp"

namespace ast
{
	/********************************
	 * Non-terminal node base class *
	 ********************************/
	class NonTerminal : public ASTNode
	{
	public:
		// constructors
		// string arg is the token node name
		NonTerminal(const std::string&);
		// additionnal arguments are for location (see ast node constructors for ordering)
		NonTerminal(const std::string&,int,int,int,int);
		NonTerminal(const std::string&,const NodeLocation&);
	};
}

#endif
