#include "Exceptions.hpp"

using namespace except;
using namespace std;

UndefinedSymbolException::UndefinedSymbolException() 
	: runtime_error("The symbol doesn't exist in the table.")
{


}

UndefinedSymbolException::UndefinedSymbolException(const std::string& symb_name) 
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

BadSettingException::BadSettingException(const std::string& details) 
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

BadInputParameterException::BadInputParameterException(const std::string& details)
	: runtime_error("The program input parameters are not formatted correctly : " + details)
{

}

ParsingException::ParsingException()
	: runtime_error("The parser has encountered an error while parsing the code.")
{

}

ParsingException::ParsingException(const std::string& details)
	: runtime_error("The parser has encountered an error while parsing the code : " + details)
{

}

TypeSymbolResolutionException::TypeSymbolResolutionException()
	: runtime_error("Cannot resolve a symbol type to a complete type.")
{

}

TypeSymbolResolutionException::TypeSymbolResolutionException(const std::string& details)
	: runtime_error("Cannot resolve a symbol type to a complete type : " + details)
{

}

BadParameterNumberException::BadParameterNumberException()
	: logic_error("The number of expected number of parameters does not match the number of given parameters.")
{

}

BadParameterNumberException::BadParameterNumberException(const std::string& details)
	: logic_error("The number of expected number of parameters does not match the number of given parameters : " + details)
{

}