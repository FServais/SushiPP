#include "Exceptions.hpp"

using namespace except;
using namespace std;

UndefinedSymbolException::UndefinedSymbolException() 
	: runtime_error("The symbol doesn't exist in the table.")
{


}

UndefinedSymbolException::UndefinedSymbolException(const string& symb_name) 
	: runtime_error("The symbol '" + symb_name + "' does not exist in the table.")
{


}

UndefinedScopeException::UndefinedScopeException() 
	: runtime_error("The scope id does not identify any existing scope in the table.")
{


}

UndefinedScopeException::UndefinedScopeException(unsigned long id) 
	: runtime_error("The scope id '" + to_string(id) + "' does not identify any existing scope in the table")
{


}

BadSettingException::BadSettingException() 
	: runtime_error("The settings configuration are such that these data are not available.")
{


}

BadSettingException::BadSettingException(const string& details) 
	: runtime_error("The settings configuration are such that these data are not available : " + details)
{


}

BadInputParameterException::BadInputParameterException()
	: runtime_error("The program input parameters are not formatted correctly.")
{

}

BadInputParameterException::BadInputParameterException(char c)
	: runtime_error("The program detected an invalid parameter '" + string(c, 1) + "'")
{

}

BadInputParameterException::BadInputParameterException(const string& details)
	: runtime_error("The program input parameters are not formatted correctly : " + details)
{

}

ParsingException::ParsingException()
	: runtime_error("The parser has encountered an error while parsing the code.")
{

}

ParsingException::ParsingException(const string& details)
	: runtime_error("The parser has encountered an error while parsing the code : " + details)
{

}

TypeSymbolResolutionException::TypeSymbolResolutionException()
	: runtime_error("Cannot resolve a symbol type to a complete type.")
{

}

TypeSymbolResolutionException::TypeSymbolResolutionException(const string& details)
	: runtime_error("Cannot resolve a symbol type to a complete type : " + details)
{

}

BadParameterNumberException::BadParameterNumberException()
	: logic_error("The number of expected number of parameters does not match the number of given parameters.")
{

}

BadParameterNumberException::BadParameterNumberException(const string& details)
	: logic_error("The number of expected number of parameters does not match the number of given parameters : " + details)
{

}

NoSuchChildException::NoSuchChildException()
	: logic_error("The node has no such child.")
{

}

NoSuchChildException::NoSuchChildException(const string& details)
	: logic_error("The node has no such child : " + details)
{

}

NoSuchParameterException::NoSuchParameterException(size_t param)
  : logic_error("There is no parameter number " + to_string(param) + " in the VisitorParameters object")
{

}

NoSuchParameterException::NoSuchParameterException(size_t param, const string& details)
  : logic_error("There is no parameter number " + to_string(param) + " in the VisitorParameters object : " + details)
{

}

UnificationException::UnificationException(const string& details)
  : runtime_error(details)
{

}

ExistingTypeSymbolException::ExistingTypeSymbolException(const string& symbol)
  : logic_error("Attempting to add the existing symbol '" + symbol + "' in the type symbol table")
{

}

UnresolvableTypeException::UnresolvableTypeException(const string& symbol)
  : runtime_error("The type of the type symbol '" + symbol + "' cannot be resolved")
{

}

NoSuchTypeSymbolException::NoSuchTypeSymbolException(const string& symbol)
  : runtime_error("Unable to find the type symbol '" + symbol + "'")
{

}