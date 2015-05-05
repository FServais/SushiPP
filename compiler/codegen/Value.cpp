#include "Value.hpp"

using namespace codegen;
using namespace std;
using namespace typegen;

Value::Value(shared_ptr<Type> _type) : type(_type) { }

Type& Value::get_type()
{
    return *type;
}

string Value::str_type()
{
    return type->to_str();
}

void Value::set_type(shared_ptr<Type> _type)
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
