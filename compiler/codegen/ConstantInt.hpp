#include <string>

#include "Constant.hpp"


namespace codegen
{
    class ConstantInt : public Constant
    {
    public:
        ConstantInt(int _value) : Constant(nullptr), value(_value)
        {
            set_type(std::shared_ptr<typegen::Type>(new typegen::Bool()));
        }

        int get_value() { return value; }

        std::string str_value() { return std::to_string(value); }
    private:
        int value;

    };
}
