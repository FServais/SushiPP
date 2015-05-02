
#include "Builder.hpp"

using namespace codegen;
using namespace std;

Builder::Builder() : curr_pos(0)
{
    Module module(var_manager);
    modules.push_back(module);
}

void Builder::dump(ostream& out)
{
    for(auto module = modules.begin() ; module != modules.end() ; ++module ){
        module->dump(out);
        out << endl;
    }
}

Module& Builder::get_curr_module()
{
    return modules[curr_pos];
}

void Builder::add_module(Module& module)
{
    modules.push_back(module);
    ++curr_pos;
}
