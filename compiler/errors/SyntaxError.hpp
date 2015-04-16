#ifndef SYNTAX_ERROR_HPP_DEFINED
#define SYNTAX_ERROR_HPP_DEFINED

#include "ErrorItem.hpp"

namespace errors
{
	class SyntaxError : public ErrorItem
	{
	public:
		SyntaxError(const std::string&, int, int, const std::string&, const std::string&);
		
		virtual void print(bool) const;
	};
}

#endif // SYNTAX_ERROR_HPP_DEFINED
