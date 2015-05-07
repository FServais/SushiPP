#include "Module.hpp"

using namespace codegen;
using namespace std;

Module::Module(VariableManager& vm) : var_manager(vm)
{
    shared_ptr<typegen::Function> main_func(new typegen::Function(shared_ptr<typegen::Type>(new typegen::Int)));
    FunctionBlock function(vm, "main", main_func);
    function.set_return("0");
    add_function("main", function);


    // Add printf
    // FunctionBlock printf(vm, "printf", shared_ptr<typegen::Type>(new typegen::Int()));
    // printf.add_argument(shared_ptr<typegen::Type>(new typegen::Bool()), "");
    // printf.add_argument(shared_ptr<typegen::Type>(new typegen::Bool()), "");
    // add_declaration(printf);

    // add_str_constant("@.str = private unnamed_addr constant [3 x i8] c\"%d\\00\", align 1");

}

void Module::dump(ostream& out) const
{
    for(auto var = global_vars.begin() ; var != global_vars.end() ; ++var )
        out << *var << endl;

    for(auto cst = str_constants.begin() ; cst != str_constants.end() ; ++cst )
        out << *cst << endl;

    out << endl;

    for(auto& decl : declarations)
        decl.second.dump_declaration(out);

    for(auto& func : functions)
    {
        func.second.dump(out);
        out << endl;
    }
}

void Module::add_function(const std::string& function_name, FunctionBlock& function)
{
    if(declarations.count(function_name))
        throw std::logic_error("Existing function");
    functions.emplace(function_name, function);
}


void Module::add_declaration(const std::string& function_name, FunctionBlock& decl)
{
    if(declarations.count(function_name))
        throw std::logic_error("Existing declaration");
    declarations.emplace(function_name, decl);
}

void Module::add_str_constant(std::string cst)
{
    str_constants.push_back(cst);
}

FunctionBlock& Module::get_function(string function_name)
{
    return functions.at(function_name);
}
