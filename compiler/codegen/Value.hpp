#ifndef VALUE_HPP_DEFINED
#define VALUE_HPP_DEFINED

#include <string>

namespace codegen
{
    class Value
    {
    public:
        Value(const std::string& _type);

        // Type
        bool is_variable() { return variable; }
        bool is_constant() { return constant; }

        // std::string -> to change
        std::string get_type();
        std::string str_type();

        virtual std::string str_value();

    protected:
        // Type
        bool variable, constant;
        std::string type;

        void set_type(std::string _type);

    };
}

#endif