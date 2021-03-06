#include "Exceptions.hpp"

using namespace except;
using namespace std;


RedefinedSymbolException::RedefinedSymbolException() 
	: runtime_error("The symbol already exists in this scope.")
{


}

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
