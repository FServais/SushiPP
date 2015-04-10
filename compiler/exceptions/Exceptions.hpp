#ifndef EXCEPTIONS_HPP_DEFINED
#define EXCEPTIONS_HPP_DEFINED 

#include <stdexcept>
#include <string>

namespace except
{
	class UndefinedSymbolException : public std::runtime_error
	{
	public:
		UndefinedSymbolException();
		// param : the symbol name
		explicit UndefinedSymbolException(const std::string&);
	};

	class UndefinedScopeException : public std::runtime_error
	{
	public:		
		UndefinedScopeException();
		// parem : the scope id
		explicit UndefinedScopeException(unsigned long);
	};
}

#endif // EXCEPTIONS_HPP_DEFINED