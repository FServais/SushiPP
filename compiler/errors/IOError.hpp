#ifndef IO_ERROR_HPP_DEFINED
#define IO_ERROR_HPP_DEFINED

#include "ErrorItem.hpp"

namespace errors
{
	class IOError : public ErrorItem
	{
	public:
		IOError(const std::string& _context, const std::string& _file, const std::string& _additional_desc);
		
		virtual void print(bool) const;

	private:
		void print_global() const;
	};
}

#endif // IO_ERROR_HPP_DEFINED
