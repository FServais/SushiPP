#ifndef UTIL_HPP_DEFINED
#define UTIL_HPP_DEFINED 

#include <string>
#include <sstream>

namespace util
{
	/**
	 * @brief Generate a random alphanumeric string of the given length 
	 * @param size_t The string length
	 * Source : http://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
	 */
	std::string random_string(size_t length);

	/**
	 * @brief Implode a range into a string. The element must be convertible to a string (with the std::to_string function)
	 * @param IIter first Iterator to the first element of the range
	 * @param IIter last Iterator to the element after the last element of the range
	 * @param std::string glue The glue string 
	 */
	template <typename IIter>
	std::string implode(IIter first, IIter last, std::string glue = std::string())
	{
		std::stringstream ss;

		while(first != last)
		{
			ss << (*first);
			first = std::next(first);
			if(first != last)
				ss << glue;
		}

		return ss.str();
	}

	/**
	 * @brief Remove the extension of a file (everything from the last dot)
	 * @param const string& file A filename
	 * @retval string The file name without extension
	 */
	std::string remove_extension(const std::string&);
}

#endif // UTIL_HPP_DEFINED