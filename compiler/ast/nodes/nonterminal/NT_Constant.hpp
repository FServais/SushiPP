#ifndef NT_CONSTANT_HPP_DEFINED
#define NT_CONSTANT_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals::nt_constant
{

	/**********************************
	 * Constant rules node base class *
	 **********************************/
	class NT_Constant : public NonTerminal
	{
	public:
		// Constructors
		NT_Constant();
		NT_Constant(int,int,int,int);
		NT_Constant(const ast::nodes::NodeLocation&);
	};

}

#endif
