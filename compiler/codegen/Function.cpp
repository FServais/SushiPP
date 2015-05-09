#include <sstream>
#include <iostream>
#include <algorithm>

#include "Function.hpp"
#include "Constant.hpp"
#include "Variable.hpp"

using namespace codegen;
using namespace std;


Function::Function(shared_ptr<typegen::Type> return_type, string& _name, vector<shared_ptr<Value>> arguments) : Value(return_type), name(_name), args(arguments)
{

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

shared_ptr<typegen::Type> Function::get_type_nth_argument(int n)
{
    return args[n]->get_type();
}

string Function::str_type_nth_argument(int n)
{
    return args[n]->get_type()->to_str();
}

string Function::get_name_nth_argument(int n)
{
    /*
    if(args[n]->is_variable())
    {
        Variable& arg = dynamic_cast<Variable&>(*(args[n]));
        return arg.str_value();
    }
    else if(args[n]->is_constant())
    {
        Constant& arg = dynamic_cast<Constant&>(*(args[n]));
        return arg.str_value();
    }
    */
    return args[n]->str_value();
}

string Function::str_name_nth_argument(int n)
{
    /*
    if(args[n]->is_variable())
    {
        stringstream ss;
        ss << "%" << get_name_nth_argument(n);
        return ss.str();
    }
    */
    return get_name_nth_argument(n);
}

shared_ptr<typegen::Type> Function::get_return_type()
{
     return get_type();
}

string Function::str_return_type()
{
     return get_type()->to_str();
}

string Function::get_signature()
{
    stringstream ss;
    ss << str_return_type() << " " << "(";

    for(int i = 0 ; i < nb_args() ; ++i)
    {
        if(i == nb_args()-1)
            ss << str_type_nth_argument(i) << ")*";
        else
            ss << str_type_nth_argument(i) << ", ";
    }

    return ss.str();
}

vector<string> Function::str_arguments() const
{
    vector<string> str_args;
    transform(args.begin(), args.end(), back_inserter(str_args),
              [](shared_ptr<Value> arg)
              {
                return arg->str_type() + " " + arg->str_value();
              });
    return str_args;
}

string Function::get_function_call()
{
    stringstream ss;

    ss << get_signature() << " " << str_name() << " (";
    for(auto arg = args.begin() ; arg != args.end() ; ++arg)
    {
        if(arg == args.end() - 1)
            ss << str_type_nth_argument(arg - args.begin()) << " " << str_name_nth_argument(arg - args.begin()) << ")";
        else
            ss << str_type_nth_argument(arg - args.begin()) << " " << str_name_nth_argument(arg - args.begin()) << ", ";
    }

    return ss.str();
}

int Function::nb_args() const
{
    return args.size();
}

