#include "Module.hpp"
#include "BasicBlock.hpp"
#include "../util.hpp"

#include <algorithm> // replace_if

using namespace codegen;
using namespace std;

Module::Module(VariableManager& vm) : var_manager(vm) { }

void Module::dump(ostream& out) const
{
    for(auto var = global_vars.begin() ; var != global_vars.end() ; ++var )
        out << *var << endl;

    for(auto cst = str_constants.begin() ; cst != str_constants.end() ; ++cst )
        out << *cst << endl;

    out << endl;

    for(auto& decl : declarations)
        if(get<1>(decl.second))
            out << get<0>(decl.second) << endl;

    out << endl;

    for(auto& func : functions)
    {
        func.second.dump(out);
        out << endl;
    }
}

void Module::add_function(const string& function_name, FunctionBlock& function)
{
    if(functions.count(function_name))
        throw logic_error("Existing function");
    functions.emplace(function_name, function);
}

void Module::add_global_type(const string& name, const string& expression)
{
    global_vars.push_back("%" + name + " = " + expression);
}

void Module::add_global_variable(const string& name, const string& expression)
{
    global_vars.push_back("@" + name + " = " + expression);
}

void Module::add_str_constant(string cst)
{
    str_constants.push_back(cst);
}

FunctionBlock& Module::get_function(string function_name)
{
    return functions.at(function_name);
}

void Module::add_declaration(const string& function_name, FunctionBlock& f_block)
{
    if(function_declared(function_name))
        throw logic_error("Existing declaration");
    string declare = make_declare(function_name, 
                                  f_block.str_return_signature(), 
                                  f_block.arguments_signature());
    declarations[function_name] = make_tuple(declare, false);
}

void Module::add_declaration(const string& function_name, FunctionBlock& f_block, settings::Runtime runtime)
{
    if(function_declared(function_name))
        throw logic_error("Existing declaration");
    vector<string> arg_sigs(f_block.arguments_signature());

    // insert the array or list table 
    switch(runtime)
    {
    case settings::LIST_RUNTIME:
        arg_sigs.insert(arg_sigs.begin(), "%" + list_table_type + "*"); break;
    case settings::ARRAY_RUNTIME:
        arg_sigs.insert(arg_sigs.begin(), "%" + array_table_type + "*"); break;
    default: break;
    }

    string declare = make_declare(function_name, 
                                  f_block.str_return_signature(),
                                  arg_sigs);
    declarations[function_name] = make_tuple(declare, false);
}

void Module::add_declaration(const string& function_name, const string& raw_declaration)
{
    if(function_declared(function_name))
        throw logic_error("Existing declaration");
    declarations[function_name] = make_tuple(raw_declaration, false);
}

bool Module::function_declared(const string& name) const
{
    return declarations.count(name);
}

void Module::function_is_used(const string& name)
{
    if(function_declared(name))
        get<1>(declarations[name]) = true;
}

string Module::make_declare(const string& name, const string& return_type, const vector<string>& param_types)
{
    string params(param_types.size() == 0 ? "..." : util::implode(param_types.begin(), param_types.end(), ", "));
    return "declare " + return_type + " @" + get_llvm_function_name(name, true) + "(" + params + ")"; // declared is always a built in function
}

string Module::get_llvm_function_name(const string& spp_name, bool built_in = false)
{
    if(!built_in)
        return "." + spp_name;

    string new_name(spp_name);
    replace_if(new_name.begin(), new_name.end(), [](char c) { return c == '-'; }, '_');
    return new_name;
}
