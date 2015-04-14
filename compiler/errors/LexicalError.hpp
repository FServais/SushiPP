#ifndef LEXICAL_ERROR_HPP_DEFINED
#define LEXICAL_ERROR_HPP_DEFINED

#include "ErrorItem.hpp"

namespace errors
{
	class LexicalError : public ErrorItem
	{
	public:
		LexicalError(const std::string&, int, int, const std::string&, const std::string&);
		
		virtual void print(bool) const;
	};
}

#endif // LEXICAL_ERROR_HPP_DEFINED
