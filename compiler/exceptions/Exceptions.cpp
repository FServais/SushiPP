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