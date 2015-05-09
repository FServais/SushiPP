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

        void add_function(const std::string&, FunctionBlock&);
        void add_declaration(const std::string&, FunctionBlock&);

        void add_str_constant(std::string);

        FunctionBlock& get_function(std::string function_name);


    private:
        VariableManager& var_manager;

        std::map<std::string, FunctionBlock> functions; // map function name with function block of function definition
        std::map<std::string, FunctionBlock> declarations; // map function name with function block of function declaration
        std::vector<std::string> global_vars;
        std::vector<std::string> str_constants;
    };
}

#endif
