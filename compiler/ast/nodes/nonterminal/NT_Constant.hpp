#ifndef NT_CONSTANT_HPP_DEFINED
#define NT_CONSTANT_HPP_DEFINED

#include "NonTerminal.hpp"

namespace ast
{

	/*********************************************
	 * Intermediate NT_Constant node base class *
	 *********************************************/
	class NT_Constant : public NonTerminal
	{
	public:
		// Constructors
		// type of child (ast::Integer, ast::Float, ...)
		NT_Constant(ASTNode*);
		// type, first line, last line, first col, last col
		NT_Constant(ASTNode*, int,int,int,int);
		// type, node location object
		NT_Constant(ASTNode*, const NodeLocation&);

		// get child
		ASTNode& get_type();

		virtual void accept(ASTVisitor&);
	};
}

#endif
