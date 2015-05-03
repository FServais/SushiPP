#include <sstream>

#include "Variable.hpp"

using namespace codegen;
using namespace std;


Variable::Variable(string _name, string _type) : Value(_type), name(_name)
{
    set_is_variable();
}


// From Value
string Variable::str_value()
{
    stringstream ss;
    ss << "%" << name;
    return ss.str();
}


// Name

string Variable::get_name()
{
    return name;
}

void Variable::set_name(string _name)
{
    name = _name;
}
