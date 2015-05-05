#include <sstream>
#include <iostream>

#include "Variable.hpp"

using namespace codegen;
using namespace std;
using namespace typegen;


Variable::Variable(VariableManager& _var_manager, string _name, std::shared_ptr<typegen::Type> _type, bool _pointer) : Value(_type), var_manager(_var_manager), pointer(_pointer)
{
    set_is_variable();
    set_name(_name);
}


// From Value
string Variable::str_value()
{
    stringstream ss;
    ss << "%" << ((is_pointer()) ? orig_name : name);
    return ss.str();
}


// Name

string Variable::get_name()
{
    return orig_name;
}

void Variable::set_name(string _name)
{
    orig_name = _name;
    name = var_manager.insert_variable(orig_name);
}

bool Variable::is_pointer() const
{
    return pointer;
}
