#ifndef ERROR_ITEM_HPP_DEFINED
#define ERROR_ITEM_HPP_DEFINED

#include <string>
#include <iostream>

namespace errors
{
	class ErrorItem
	{
	protected:
		ErrorItem(const std::string _error_type, const std::string& _context, int _line, int _col, const std::string& _file, const std::string& _additional_desc) : error_type(_error_type), context(_context), line(_line), col(_col), file(_file), additional_desc(_additional_desc) { }

		static std::string error_flag;

		const std::string error_type;

		std::string context; // contains the line which has an error.
		int col, line; // location of the error.
		std::string file; // file name.
		std::string additional_desc;

	public:
		/**
		 * Print the error.
		 */
		virtual void print(bool) const = 0;

		/**
		 * Print a scheme pointing visually to the error.
		 * Example : 
		 * maki ;a = 33
		 * _____^______
		 */
		void print_location_error() const;
	};

}



#endif // ERROR_ITEM_HPP_DEFINED
