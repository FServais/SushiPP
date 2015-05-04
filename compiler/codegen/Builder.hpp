#ifndef BUILDER_HPP_DEFINED
#define BUILDER_HPP_DEFINED

#include <iostream>
#include <vector>

#include "Module.hpp"
#include "VariableManager.hpp"

namespace codegen
{
    class Builder
    {
    public:
        Builder();

        /**
         * Print the LLVM code in the output stream.
         */
        void dump(std::ostream&);

        Module& get_curr_module();

        void add_module(Module&);

        VariableManager& get_variable_manager();

    private:
        std::vector<Module> modules;
        int curr_pos;

        VariableManager var_manager;

    };

}

#endif
