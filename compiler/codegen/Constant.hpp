#include "Value.hpp"
#include <string>

namespace codegen
{
    class Constant : public Value
    {
    public:
        Constant(const std::shared_ptr<typegen::Type> _type) : Value(_type) { set_is_constant(); }

        virtual std::string str_value() { return ""; }
    };

    class ConstantInt : public Constant
    {
    public:
        ConstantInt(int _value) : Constant(nullptr), value(_value)
        {
            set_type(std::shared_ptr<typegen::Type>(new typegen::Int()));
        }

        int get_value() { return value; }

        std::string str_value() { return std::to_string(value); }
    private:
        int value;

    };

    class ConstantFloat : public Constant
    {
    public:
        ConstantFloat(float _value) : Constant(nullptr), value(_value)
        {
            set_type(std::shared_ptr<typegen::Type>(new typegen::Float()));
        }

        float get_value() { return value; }

        std::string str_value() { return std::to_string(value); }
    private:
        float value;

    };

	class ConstantBool : public Constant
    {
    public:
        ConstantBool(bool _value) : Constant(nullptr), value(_value)
        {
            set_type(std::shared_ptr<typegen::Type>(new typegen::Bool()));
        }

        bool get_value() { return value; }

        std::string str_value() { return std::to_string(value); }
    private:
        bool value;

    };

    class ConstantChar : public Constant
    {
    public:
        ConstantChar(char _value) : Constant(nullptr), value(_value)
        {
            set_type(std::shared_ptr<typegen::Type>(new typegen::Char()));
        }

        char get_value() { return value; }

        std::string str_value() { return std::to_string(value); }
    private:
        char value;

    };


    class ConstantString : public Constant
    {
    public:
        ConstantString(std::string _value) : Constant(nullptr), value(_value)
        {
            set_type(std::shared_ptr<typegen::Type>(new typegen::String()));
        }

        std::string get_value() { return value; }

        std::string str_value() { return value; }
    private:
        std::string value;

    };


}
