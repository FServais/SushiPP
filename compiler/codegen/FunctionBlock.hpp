#ifndef FUNCTION_BLOCK_HPP_DEFINED
#define FUNCTION_BLOCK_HPP_DEFINED

#include <iostream>
#include <vector>
#include <string>

#include "BasicBlock.hpp"
#include "VariableManager.hpp"

namespace codegen
{
    class FunctionBlock
    {
    public:
        FunctionBlock(VariableManager& vm);
        // VariableManager, name, return_type
        FunctionBlock(VariableManager& vm, std::string, std::string);

        /**
         * Print the LLVM code in the output stream.
         */
        void dump(std::ostream&) const;

        void add_block(BasicBlock&);

        std::string get_name() const;
        std::string str_arguments() const;

        BasicBlock& get_block(int n);
        BasicBlock& get_last_block();

    private:

        std::string name;
        std::string return_type;
        // <type, name>
        std::vector<std::pair<std::string, std::string>> arguments;
        std::vector<BasicBlock> blocks;

        VariableManager& var_manager;

    };
}

#endif
