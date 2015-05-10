#ifndef BASIC_BLOCK_HPP_DEFINED
#define BASIC_BLOCK_HPP_DEFINED

#include <string>
#include <vector>

#include "Value.hpp"
#include "VariableManager.hpp"
#include "Variable.hpp"
#include "../settings/BuiltInFunctions.hpp"


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


        // Value* : Variable
        Value* create_decl_var(Value&);


        // lhs and rhs : create an assignment : 'lhs = rhs'
        Value* create_assign_value(Value&, Value&);

        // lhs and rhs : create an assignment : 'lhs = rhs'
        Value* create_assign(Value&, Value&);

        // store Value* in variable
        Value* create_store(Value&, Value&);
        Value* create_func_store(Value&, Value&);
        // load the value
        Value* create_load(Value&);
        /**
         * @param var : type and variable name
         * @retval ret
         * ret = load var
         */
        std::string create_load_raw(const std::string&);

        // getelementptr (Variable)
        Value* create_get_pointer(Value&);

        //Value* create_get_pointer_array(Value&, Value&);

        void create_branch(std::string);

        // Variable containing the result of the condition, label if true, label if false
        void create_cond_branch(Value&, std::string, std::string);

        /**
         * @brief Create a function call
         * @param Value& function The function object
         * @param settings::Runtime runtime Indicate the runtime lib. in which the function is (optionnal, default: considered as a user function)
         * @retval Value* The variable containing the result of the function call, nullptr if the return type is void
         */
        Value* create_func_call(Value&, settings::Runtime);
        Value* create_func_call(Value&);

        /**
         * @brief Create a return line
         * @param Value& value The value to return
         */
        void create_return(Value&);

        /**
         * @Brief Add a new line at the end of the block
         * @param const std::string& expr The LLVM expression
         * @param const std::string& ret The name of the variable in which the result of the expression must be stored (optionnal)
         * @param const std::shared_ptr<typegen::Type>& type The type of the return variable (optionnal)
         * @retval Variable* When the ret argument is omitted, a nullptr is returned, otherwise the Value object containing the
         * variable generated by the variable manager
         * @note The function generates two kind of LLMV code line
         *   1) ret = expr (when ret is provided)
         *   2) expr (when ret is omitted)
         */
        Variable* add_expression(const std::string&, const std::string&, std::shared_ptr<typegen::Type>);
        Variable* add_expression(const std::string&);
        /**
         * @brief Assign a llvm expression
         * @param const std::string& expr The LLVM expression
         * @param const std::string& glob_var The global variable name
         */
        void add_assign_global(const std::string& , const std::string&);

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
        static std::string make_binop(const std::string&, const std::string&, const std::string&);
        static std::string make_binop(const std::string&, const std::string&, const std::string&, const std::string&);

        /**
         * @brief Create a llvm function call
         * @param const std::string& sig The signature of the function
         * @param const std::string& name The name of the function
         * @param const std::vector<std::string>& vec The arguments' signatures
         * @param const std::string& ret The variable in which must be returnd the result (optionnal, default: not taken into account)
         * ret = call sig @name(arg_sig)
         */
        static std::string make_call(const std::string&, const std::string&, const std::vector<std::string>&);
        static std::string make_call(const std::string&, const std::string&, const std::vector<std::string>&, const std::string&);

        static std::string make_signature(const std::string&, const std::vector<std::string>&);

    private:
        std::string label;
        std::vector<std::string> lines;

        VariableManager& var_manager;

        void add_line(std::string);


    };
}

#endif
