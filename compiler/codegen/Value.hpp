#ifndef VALUE_HPP_DEFINED
#define VALUE_HPP_DEFINED

#include <string>

#include "../inference/TypeGen.hpp"

namespace codegen
{
    class Value
    {
    public:
        Value(std::shared_ptr<typegen::Type> _type);

        bool is_variable();
        bool is_constant();
        bool is_function();

        void set_is_variable();
        void set_is_constant();
        void set_is_function();

        // std::string -> to change
        std::shared_ptr<typegen::Type> get_type();
        std::string str_type();

        virtual std::string str_value();

    protected:
        // Type
        bool variable, constant, function;
        std::shared_ptr<typegen::Type> type;

        void set_type(std::shared_ptr<typegen::Type> _type);

    };
}

#endif
