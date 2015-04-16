#ifndef IO_ERROR_HPP_DEFINED
#define IO_ERROR_HPP_DEFINED

#include "ErrorItem.hpp"

namespace errors
{
	class IOError : public ErrorItem
	{
	public:
		IOError(const std::string& _context, int _line, int _col, const std::string& _file, const std::string& _additional_desc);
		
		virtual void print(bool) const;
	};
}

#endif // IO_ERROR_HPP_DEFINED
