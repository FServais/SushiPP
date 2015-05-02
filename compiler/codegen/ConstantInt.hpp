#include <string>

#include "Constant.hpp"


namespace codegen
{
    class ConstantInt : public Constant
    {
    public:
        ConstantInt(int _value) : Constant("i32"), value(_value) { }

        int get_value() { return value; }

        std::string str_value() { return std::to_string(value); }
        std::string str_type() { return type; }

    private:
        int value;

    };
}
