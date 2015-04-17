#ifndef SEMANTIC_ERROR_HPP_DEFINED
#define SEMANTIC_ERROR_HPP_DEFINED

#include "ErrorItem.hpp"

namespace errors
{
	class SemanticError : public ErrorItem
	{
	public:
		SemanticError(const std::string& _context, int _line, int _col, const std::string& _file, const std::string& _additional_desc);
		
		virtual void print(bool) const;
	};
}

#endif // SEMANTIC_ERROR_HPP_DEFINED
