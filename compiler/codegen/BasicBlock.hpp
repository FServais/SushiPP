#ifndef BASIC_BLOCK_HPP_DEFINED
#define BASIC_BLOCK_HPP_DEFINED

#include <string>
#include <vector>

#include "Value.hpp"
#include "VariableManager.hpp"

namespace codegen
{
    class BasicBlock
    {
    public:
        // VaraiableManager, ErrorHandler, label
        BasicBlock(VariableManager&, std::string);

        /**
         * Print the LLVM code in the output stream.
         */
        void dump(std::ostream&) const;

        /********************
         * 		Operator
         ********************/

        Value* create_op_plus(Value&, Value&);
        Value* create_op_minus(Value&, Value&);
        Value* create_op_mult(Value&, Value&);
        Value* create_op_div(Value&, Value&);
        Value* create_op_mod(Value&, Value&);
        Value* create_op_expon(Value&, Value&);
        Value* create_op_unminus(Value&);
        Value* create_op_bit_or(Value&, Value&);
        Value* create_op_bit_and(Value&, Value&);
        Value* create_op_bit_xor(Value&, Value&);
        Value* create_op_bit_not(Value&);
        Value* create_op_log_or(Value&, Value&);
        Value* create_op_log_and(Value&, Value&);
        Value* create_op_log_not(Value&);
        Value* create_op_cmp_lt(Value&, Value&);
        Value* create_op_cmp_gt(Value&, Value&);
        Value* create_op_cmp_le(Value&, Value&);
        Value* create_op_cmp_ge(Value&, Value&);
        Value* create_op_cmp_eq(Value&, Value&);
        Value* create_op_cmp_neq(Value&, Value&);
        Value* create_op_left_shift(Value&, Value&);
        Value* create_op_right_shift(Value&, Value&);
        Value* create_op_str_conc(Value&, Value&);
        Value* create_op_pref_incr(Value&);
        Value* create_op_pref_decr(Value&);
        Value* create_op_post_incr(Value&);
        Value* create_op_post_decr(Value&);
        Value* create_op_assign(Value&, Value&);


        /************************************
		 * 		Declaration non-terminal    *
		 ************************************/
        // Value* : Variable
        Value* create_decl_var(Value&);


        // lhs and rhs : create an assignment : 'lhs = rhs'
        Value* create_assign_value(Value&, Value&);

        // store Value* in variable
        Value* create_store(Value&, Value&);

        Value* create_load(Value&);

        // getelementptr (Variable)
        Value* create_get_pointer(Value&);

        //Value* create_get_pointer_array(Value&, Value&);

        void create_branch(std::string);

        // Variable containing the result of the condition, label if true, label if false
        void create_cond_branch(Value&, std::string, std::string);

        Value* create_func_call(Value&);

    private:
        std::string label;
        std::vector<std::string> lines;

        VariableManager& var_manager;

        void add_line(std::string);


        /**
         * @brief Builds a binary operator
         * @param const std::string& func The LLVM operator as a string
         * @param const std::string& op1  The first operand
         * @param const std::string& op2  The second operand
         * @param const std::string& ret  The variable in which must be returnd the result (optionnal, default: not taken into account)
         * @retval std:string The binary operation : 
         *   1) op op1, op2
         *   2) ret = op op1, op2
         */
        std::string make_binop(const std::string&, const std::string&, const std::string&);
        std::string make_binop(const std::string&, const std::string&, const std::string&, const std::string&);
    };
}

#endif
