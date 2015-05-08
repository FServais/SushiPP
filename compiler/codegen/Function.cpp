#include <sstream>
#include <iostream>

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

// //Function::Function(shared_ptr<typegen::Type> _type, string& _name, vector<string>& _arg_names) : Value(_type), name(_name), arg_names(_arg_names)
// Function::Function(shared_ptr<typegen::Type> _return_type, string& _name, vector<Value&>& _args) : Value(_return_type), name(_name), args(_args)
// {
//     set_is_function();
// }
//
//
// string Function::str_value()
// {
//     stringstream ss;
//
//     ss << str_return_type() << " @"  << name << "(";
//
//     typegen::Function& func_type = dynamic_cast<typegen::Function&>(*type);
//     for(int i = 0 ; i < func_type.nb_param() ; ++i)
//     {
//         if(i == func_type.nb_param()-1)
//             ss << get_type_nth_argument(i) << ")";
//         else
//             ss << get_type_nth_argument(i) << ", ";
//     }
//
//     return ss.str();
// }
//
//
// string Function::get_name() const
// {
//     return name;
// }
//
// string Function::str_name() const
// {
//     stringstream ss;
//     ss << "@" << name;
//     return ss.str();
// }
//
//
// shared_ptr<typegen::Type> Function::get_type_nth_argument(int n) const
// {
//     /*
//     typegen::Function& func_type = dynamic_cast<typegen::Function&>(*type);
//     shared_ptr<typegen::Type> arg_type = func_type.get_arg(n);
//
//     return arg_type->to_str();
//     */
//
//     return args[n].get_type();
// }
//
// string Function::get_name_nth_argument(int n) const
// {
//     if(args[n].is_variable())
//     {
//         Variable& arg = dynamic_cast<Variable&>(args[n]);
//         return arg.get_name();
//     }
//     else if(args[n].is_constant())
//     {
//         Function& arg = dynamic_cast<Function&>(args[n]);
//         return arg.get_name();
//     }
//
//     return args[n].str_value();
// }
//
// string Function::str_name_nth_argument(int n) const
// {
//     stringstream ss;
//     ss << "%" << get_name_nth_argument(n);
//     return ss.str();
// }
//
// shared_ptr<typegen::Type> Function::get_return_type()
// {
//     //return dynamic_cast<typegen::Function&>(*type).get_ret_type();
//     return get_type();
// }
//
//
// string Function::get_signature()
// {
//     stringstream ss;
//     ss << get_return_type() << " " << "(";
//
//     typegen::Function& func_type = dynamic_cast<typegen::Function&>(*type);
//     for(int i = 0 ; i < func_type.nb_param() ; ++i)
//     {
//         if(i == func_type.nb_param()-1)
//             ss << get_type_nth_argument(i) << ")*";
//         else
//             ss << get_type_nth_argument(i) << ", ";
//     }
//
//     return ss.str();
// }
//
//
// int Function::nb_args() const
// {
//     return args.size();
// }
