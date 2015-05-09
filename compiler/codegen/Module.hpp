#ifndef MODULE_HPP_DEFINED
#define MODULE_HPP_DEFINED

#include <iostream>
#include <vector>
#include <tuple>

#include "FunctionBlock.hpp"
#include "VariableManager.hpp"
#include "../settings/BuiltInFunctions.hpp"

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

        /**
         * @brief Adds a function declaration based on a basic block
         * @param const std::string& name The function name
         * @param FunctionBlock& block The function block containing function informations
         * @param settings::Runtime runtime The runtime library to which it belongs (optional)
         */
        void add_declaration(const std::string&, FunctionBlock&);
        void add_declaration(const std::string&, FunctionBlock&, settings::Runtime);

        /**
         * @brief Adds a function declaration as a raw string containing the LLVM declaration
         * @param const std::string& name The function name
         * @param const std::string& decl The declration 
         * @note The name of the function must be the same as te one on the declaration
         */
        void add_declaration(const std::string&, const std::string&);

        /**
         * @brief Checks whether the function was declared
         * @param const std::string& func The function name 
         * @retval bool True if the function was declared
         */
        bool function_declared(const std::string&) const;

        /**
         * @brief Signals the module that a function was used and that it must be declared 
         * @note The function will be declared only if its declaration was added
         * @note If the declaration wasn't added, this function does nothing
         */
        void function_is_used(const std::string&);

        /**
         * @brief Add a global variable and assign it the given string
         * @param const std::string& name The variable name (prefixed with % for type and with @ for variables)
         * @param const std::string& expression The expression to be assigned to the variable
         */
        void add_global_type(const std::string&, const std::string&);
        void add_global_variable(const std::string&, const std::string&);

        void add_str_constant(std::string);

        /**
         * @brief Return the function block associated with the given function (not the declaration)
         * @param const std::string& function_name The name of the function
         */
        FunctionBlock& get_function(std::string function_name);

        /**
         * Getters and setters for the list and array table types
         */
        void set_list_table_type(const std::string& type_name) { list_table_type = type_name; }
        void set_array_table_type(const std::string& type_name) { array_table_type = type_name; }

        const std::string& get_list_table_type() const { return list_table_type; }
        const std::string& get_array_table_type() const { return array_table_type; }

        /**
         * @brief Create a declation string
         * @param const std::string& name function name
         * @param const std::string& ret_type The return type of the function
         * @param const std::vector<std::string>& param_types The parameters types
         */
        static std::string make_declare(const std::string&, const std::string&, const std::vector<std::string>&);

        /**
         * @brief Return the name of the function so that it can be used in a llvm script
         * @param const std::string& spp_name The sushi ++ name of the function
         * @param bool built_in True if the function is a built_in function, false otherwise (optional, default: false)
         * @retval std::string The name of the function to be used in the llvm code
         * @note The conversion is the following :
         *  - built-in functions : the hyphens are transformed to lowercase
         *  - spp functions : a dot is prepend to the function name
         */
        static std::string get_llvm_function_name(const std::string&, bool);

    private:
        VariableManager& var_manager;

        std::map<std::string, FunctionBlock> functions; // map function name with function block of function definition
        std::vector<std::string> global_vars;
        std::vector<std::string> str_constants;

        /**
         * maps function name and a tuple containing the LLVM declaration string and a flag indicating if the function
         * was used or not
         */
        std::map<std::string, std::tuple<std::string, bool>> declarations; 

        /**
         * Types of the list_table and array_table runtime structures
         */
        std::string list_table_type, array_table_type;
    };
}

#endif
