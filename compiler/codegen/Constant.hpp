#include "Value.hpp"

namespace codegen
{
    class Constant : public Value
    {
    public:
        Constant(const std::string& _type) : Value(_type) { }

        virtual std::string str_value() { return ""; }
    };
}
