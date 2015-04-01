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
		NT_Constant();
		NT_Constant(int,int,int,int);
		NT_Constant(const NodeLocation&);

		virtual void accept(ASTVisitor&);
	};
}

#endif
