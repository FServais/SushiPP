#ifndef GEN_ERROR_HPP_DEFINED
#define GEN_ERROR_HPP_DEFINED

#include "ErrorItem.hpp"

namespace errors
{
	class GenError : public ErrorItem
	{
	public:
		GenError(const std::string& _context, const std::string& _file, const std::string& _additional_desc);
		
		virtual void print(bool) const;

	private:
		void print_global() const;
	};
}

#endif // GEN_ERROR_HPP_DEFINED
