#include "SymbolInfo.hpp"

#include "../util.hpp" // random_string

using namespace symb;
using namespace std;

FunctionInfo::FunctionInfo(const std::string& name, const std::vector<VariableInfo>& params, const ast::NodeLocation loc)
  :	name_(name), params_(params), anonymous_(false), used(false), location(loc)
{

}

FunctionInfo::FunctionInfo(const std::string& name, const std::vector<VariableInfo>& params)
  :	name_(name), params_(params), anonymous_(false), used(false)
{

}


/* 
 * A random alphanumeric string of length 20 has the following probability to collide with another: 1.4196007170310687e-36
 */
FunctionInfo::FunctionInfo(const std::vector<VariableInfo>& params, const ast::NodeLocation loc)
  : name_(util::random_string(20)), params_(params),  anonymous_(true), used(false), location(loc)
{

}

FunctionInfo::FunctionInfo(const std::vector<VariableInfo>& params)
  : name_(util::random_string(20)), params_(params),  anonymous_(true), used(false)
{

}

VariableInfo::VariableInfo(const std::string& name)
  : name_(name)
{

}


VariableInfo::VariableInfo(const std::string& name, const ast::NodeLocation loc)
  : name_(name), location(loc)
{

}
