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
    return "";
}
