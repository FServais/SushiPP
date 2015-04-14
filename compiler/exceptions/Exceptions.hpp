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
		// param : the scope id
		explicit UndefinedScopeException(unsigned long);
	};

	class BadSettingException : public std::runtime_error
	{
	public:		
		BadSettingException();
		// param : some detail about the error
		explicit BadSettingException(const std::string&);
	};

	class BadInputParameterException : public std::runtime_error
	{
	public:
		BadInputParameterException();
		// param : the invalid parameter
		BadInputParameterException(char);
		// param : some detail about the error
		explicit BadInputParameterException(const std::string&);
	};

	class ParsingException : public std::runtime_error
	{
	public:
		ParsingException();
		// param : some detail about the parsing error
		explicit ParsingException(const std::string&);
	};
}

#endif // EXCEPTIONS_HPP_DEFINED