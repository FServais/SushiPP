#ifndef UTIL_HPP_DEFINED
#define UTIL_HPP_DEFINED 

#include <string>

namespace util
{
	/**
	 * @brief Generate a random alphanumeric string of the given length 
	 * @param size_t The string length
	 * Source : http://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
	 */
	std::string random_string(size_t length);
}

#endif // UTIL_HPP_DEFINED