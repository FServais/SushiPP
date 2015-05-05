#ifndef VARIABLE_HPP_DEFINED
#define VARIABLE_HPP_DEFINED

#include "Value.hpp"
#include "VariableManager.hpp"

namespace codegen
{
    class Variable : public Value
    {
    public:
        Variable(VariableManager& _var_manager, std::string _name = "", std::string _type = "", bool _pointer = false);

        std::string str_value();

        std::string get_name();
        void set_name(std::string);

        bool is_pointer() const;

    private:
        VariableManager& var_manager;

        std::string name;
        std::string orig_name;
        bool pointer;
    };
}

#endif
