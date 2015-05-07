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
        // FunctionBlock(VariableManager& vm);
        // VariableManager, name, function type
        FunctionBlock(VariableManager& vm, std::string, std::shared_ptr<typegen::Function>);
        FunctionBlock(VariableManager& vm, std::string, std::shared_ptr<typegen::Function>, const std::vector<std::string>&);

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
        void set_return(std::string);

        BasicBlock& get_block(int n);
        BasicBlock& get_last_block();

        std::string get_signature() const;

    private:
        std::shared_ptr<typegen::Function> function_type; // type object representing the function
        std::string name; // function name
        std::vector<std::string> parameters_name; // paramaters name
        std::string return_value; // value that is returned by the function block
        std::vector<BasicBlock> blocks;
        VariableManager& var_manager;


        void generate_argument_type_conv();
    };
}

#endif
