#ifndef VARIABLE_HPP_DEFINED
#define VARIABLE_HPP_DEFINED

#include "Value.hpp"

namespace codegen
{
    class Variable : public Value
    {
    public:
        Variable(std::string _name = "", std::string _type = "");

        std::string str_value();

        std::string get_name();
        void set_name(std::string);

    private:
        std::string name;
    };
}

#endif
