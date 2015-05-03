#include "Module.hpp"

using namespace codegen;
using namespace std;

Module::Module(VariableManager& vm) : var_manager(vm)
{
    FunctionBlock function(vm, "main", "i32");
    function.add_argument("i32", "ac");
    function.add_argument("i8**", "av");
    function.set_return("0");
    add_function(function);
}

void Module::dump(ostream& out) const
{
    for(auto func = functions.begin() ; func != functions.end() ; ++func ){
        func->dump(out);
        out << endl;
    }
}

void Module::add_function(FunctionBlock& function)
{
    functions.push_back(function);
}

FunctionBlock& Module::get_function(string function_name)
{
    for(auto func = functions.begin() ; func != functions.end() ; ++func)
    {
        if(func->get_name() == function_name)
            return *func;
    }

    throw 0;
}
