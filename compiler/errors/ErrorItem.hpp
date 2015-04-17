#ifndef ERROR_ITEM_HPP_DEFINED
#define ERROR_ITEM_HPP_DEFINED

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

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
