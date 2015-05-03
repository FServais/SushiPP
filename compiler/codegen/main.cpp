#include <iostream>

#include "Builder.hpp"
#include "ConstantInt.hpp"
#include "Variable.hpp"

using namespace std;
using namespace codegen;


int main(int argc, char const *argv[]) {

    Builder builder;

    Module& module = builder.get_curr_module();

    FunctionBlock& main_function = module.get_function("main");


    BasicBlock& block = main_function.get_block(0);

    ConstantInt lhs(10);
    Variable rhs("super_var", "i32");

    Value assign = block.create_decl_var(rhs);
    Value res = block.create_op_plus(lhs, rhs);
    Value store = block.create_store(lhs, rhs);

    builder.dump(cout);

    return 0;
}
