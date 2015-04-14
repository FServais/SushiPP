#include "SymbolInfo.hpp"

#include "../util.hpp" // random_string

using namespace symb;
using namespace std;

FunctionInfo::FunctionInfo(const std::string& name, std::vector<Parameter>& params, Type return_type)
  :	name_(name), params_(params), return_type_(return_type), anonymous_(false)
{

}

/* 
 * A random alphanumeric string of length 20 has the following probability to collide with another: 1.4196007170310687e-36
 */
FunctionInfo::FunctionInfo(std::vector<Parameter>& params, Type return_type)
  : name_(util::random_string(20)), params_(params), return_type_(return_type), anonymous_(true)
{

}
	
Parameter::Parameter(const std::string& name) 
  : name_(name), type_(UNDEFINED)
{

}

Parameter::Parameter(const std::string& name, Type type)
  : name_(name), type_(type)
{

}

VariableInfo::VariableInfo(const std::string& name)
  : name_(name), type_(UNDEFINED)
{

}

VariableInfo::VariableInfo(const std::string& name, Type type)
  : name_(name), type_(type)
{

}
