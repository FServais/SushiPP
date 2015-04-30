#include "SymbolInfo.hpp"

#include "../util.hpp" // random_string

using namespace symb;
using namespace std;

FunctionInfo::FunctionInfo(const std::string& name, std::vector<VariableInfo>& params)
  :	name_(name), params_(params), anonymous_(false)
{

}

/* 
 * A random alphanumeric string of length 20 has the following probability to collide with another: 1.4196007170310687e-36
 */
FunctionInfo::FunctionInfo(std::vector<VariableInfo>& params)
  : name_(util::random_string(20)), params_(params),  anonymous_(true)
{

}

VariableInfo::VariableInfo(const std::string& name)
  : name_(name)
{

}
