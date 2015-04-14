#ifndef LEXICAL_ERROR_HPP_DEFINED
#define LEXICAL_ERROR_HPP_DEFINED

#include "ErrorItem.hpp"

namespace errors
{
	class LexicalError : public ErrorItem
	{
	public:
		LexicalError(const std::string& _context, int _line, int _col, const std::string& _file, const std::string& _additional_desc);
		
		virtual void print(bool) const;
	};
}

#endif // LEXICAL_ERROR_HPP_DEFINED
