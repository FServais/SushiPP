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
        FunctionBlock(VariableManager& vm, std::string, std::shared_ptr<typegen::Type>);

        /**
         * Print the LLVM code in the output stream.
         */
        void dump(std::ostream&) const;
        void dump_declaration(std::ostream&) const;

        void add_block(BasicBlock&);
        void add_block(std::string); // With block_label

        std::string get_name() const;
        std::string str_arguments() const;
        std::string str_arguments_signature() const;

        // Type, name
        void add_argument(std::shared_ptr<typegen::Type>, std::string);
        void set_return(std::string);

        BasicBlock& get_block(int n);
        BasicBlock& get_last_block();

        std::string get_signature() const;

    private:

        std::string name;
        std::shared_ptr<typegen::Type> return_type;
        std::string return_value;

        // <type, name>
        std::vector<std::pair<std::shared_ptr<typegen::Type>, std::string>> arguments;
        std::vector<BasicBlock> blocks;

        VariableManager& var_manager;

    };
}

#endif
