#ifndef VALUE_HPP_DEFINED
#define VALUE_HPP_DEFINED

#include <string>

#include "../inference/Typegen.hpp"

namespace codegen
{
    class Value
    {
    public:
        Value(std::shared_ptr<typegen::Type> _type);

        bool is_variable();
        bool is_constant();

        void set_is_variable();
        void set_is_constant();

        // std::string -> to change
        typegen::Type& get_type();
        std::string str_type();

        virtual std::string str_value();

    protected:
        // Type
        bool variable, constant;
        std::shared_ptr<typegen::Type> type;

        void set_type(std::shared_ptr<typegen::Type> _type);

    };
}

#endif
