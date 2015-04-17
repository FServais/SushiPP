#ifndef MEMORY_ERROR_HPP_DEFINED
#define MEMORY_ERROR_HPP_DEFINED

#include "ErrorItem.hpp"

namespace errors
{
	class MemoryError : public ErrorItem
	{
	public:
		MemoryError(const std::string& _context, int _line, int _col, const std::string& _file, const std::string& _additional_desc);
		
		virtual void print(bool) const;
	};
}

#endif // MEMORY_ERROR_HPP_DEFINED
