#ifndef NT_CONSTANT_HPP_DEFINED
#define NT_CONSTANT_HPP_DEFINED

#include "NonTerminal.hpp"

namespace ast
{

	/*******************************
	 * Intermediate Constant class *
	 *******************************/
	class Constant : public NonTerminal
	{
	public:
		// Constructors
		// constant of child (ast::Integer, ast::Float, ...)
		Constant(ASTNode*);
		// constant, first line, last line, first col, last col
		Constant(ASTNode*, int,int,int,int);
		// constant, node location object
		Constant(ASTNode*, const NodeLocation&);

		// get child
		ASTNode& get_constant();

		virtual void accept(ASTVisitor&);
	};
}

#endif
