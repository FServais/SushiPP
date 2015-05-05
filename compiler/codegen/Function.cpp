#include <sstream>

#include "Function.hpp"

using namespace codegen;
using namespace std;

Function::Function(shared_ptr<typegen::Type> _type, string _name) : Value(_type), name(_name)
{
    set_is_function();

}


string Function::str_value()
{
    return "wut";
}


string Function::get_name() const
{
    return name;
}

string Function::str_name() const
{
    stringstream ss;
    ss << "@" << name;
    return ss.str();
}


string Function::get_type_nth_argument(int n) const
{
    typegen::Function& func_type = dynamic_cast<typegen::Function&>(*type);
    shared_ptr<typegen::Type> arg_type = func_type.get_arg(n);

    return arg_type->to_str();
}


string Function::get_return_type() const
{
    typegen::Function& func_type = dynamic_cast<typegen::Function&>(*type);
    shared_ptr<typegen::Type> ret_type = func_type.get_ret_type();

    return ret_type->to_str();
}


string Function::get_signature() const
{

}
