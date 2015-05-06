#include "Module.hpp"

using namespace codegen;
using namespace std;

Module::Module(VariableManager& vm) : var_manager(vm)
{
    shared_ptr<typegen::Function> main_func(new typegen::Function(shared_ptr<typegen::Type>(new typegen::Int)));
    FunctionBlock function(vm, "main", main_func);
    function.set_return("0");
    add_function(function);


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

    for(auto decl = declarations.begin() ; decl != declarations.end() ; ++decl ){
        decl->dump_declaration(out);
        out << endl;
    }

    for(auto func = functions.begin() ; func != functions.end() ; ++func ){
        func->dump(out);
        out << endl;
    }
}

void Module::add_function(FunctionBlock& function)
{
    functions.push_back(function);
}


void Module::add_declaration(FunctionBlock& decl)
{
    declarations.push_back(decl);
}

void Module::add_str_constant(std::string cst)
{
    str_constants.push_back(cst);
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
