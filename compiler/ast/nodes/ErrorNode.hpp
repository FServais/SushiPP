#ifndef ERRORNODE_HPP_DEFINED
#define ERRORNODE_HPP_DEFINED

#include <string>
#include "ASTNode.hpp"

namespace ast
{	
	/***************************
	 * Syntax error node class *
	 ***************************/
	class ErrorNode : public ASTNode
	{
	public:
		// constructors
		ErrorNode();
	};
}

#endif
