#include "Value.hpp"

using namespace codegen;
using namespace std;

Value::Value(const string& _type) : type(_type) { }

std::string Value::get_type()
{
    return type;
}

std::string Value::str_type()
{
    return type;
}

void Value::set_type(std::string _type)
{
    type = _type;
}

string Value::str_value()
{
    return "wut";
}

bool Value::is_variable()
{
    return variable;
}

bool Value::is_constant()
{
    return constant;
}

void Value::set_is_variable()
{
    variable = true;
    constant = false;
}

void Value::set_is_constant()
{
    variable = false;
    constant = true;
}
