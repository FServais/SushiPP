#ifndef NT_CONSTANT_HPP_DEFINED
#define NT_CONSTANT_HPP_DEFINED

#include <string>

namespace ast::nodes::nonterminals::nt_constant
{

	/**********************************
	 * Constant rules node base class *
	 **********************************/
	class Constant : public NT_Constant
	{
	public:
		// Constructors
		Constant(const std::string&);
		Constant(const std::string&,int,int,int,int);
		Constant(const std::string&,const ast::nodes::NodeLocation&);
	};
}

#endif
