#ifndef MODULE_HPP_DEFINED
#define MODULE_HPP_DEFINED

#include <iostream>
#include <vector>

#include "FunctionBlock.hpp"
#include "VariableManager.hpp"

namespace codegen
{
    class Module
    {
    public:
        Module(VariableManager&);

        /**
         * Print the LLVM code in the output stream.
         */
        void dump(std::ostream&) const;

        void add_function(FunctionBlock&);

        FunctionBlock& get_function(std::string function_name);


    private:
        VariableManager& var_manager;

        std::vector<FunctionBlock> functions;

        // Out of the functions (global variables,...)


    };
}

#endif
