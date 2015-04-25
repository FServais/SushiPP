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

	class TypeSymbolResolutionException : public std::runtime_error
	{
	public:
		TypeSymbolResolutionException();
		// param : some more details about the error
		explicit TypeSymbolResolutionException(const std::string&);
	};

	class BadParameterNumberException : public std::logic_error
	{
	public:
		BadParameterNumberException();
		// param : some more details about the error
		explicit BadParameterNumberException(const std::string&);
	};

	class NoSuchChildException : public std::logic_error
	{
	public:
		NoSuchChildException();
		// param : some more details about the error
		explicit NoSuchChildException(const std::string&);
	};

	class NoSuchParameterException : public std::logic_error
	{
	public:
		// param : the number of the parameter
		explicit NoSuchParameterException(size_t);
		// param : the number of the parameter and some more details about the error
		NoSuchParameterException(size_t, const std::string&);
	};

	class UnificationException : public std::runtime_error
	{
	public:
		// param : some more details about the error
		explicit UnificationException(const std::string&);
	};

	class ExistingTypeSymbolException : public std::logic_error
	{
	public:
		// param : the name of the type symbol 
		explicit ExistingTypeSymbolException(const std::string&);
	};

	class NoSuchTypeSymbolException : public std::runtime_error
	{
	public:
		// param : the name of the type symbol 
		explicit NoSuchTypeSymbolException(const std::string&);
	};

	class UnresolvableTypeException : public std::runtime_error
	{
	public:
		// param : the name of the type symbol 
		explicit UnresolvableTypeException(const std::string&);
	};
}

#endif // EXCEPTIONS_HPP_DEFINED