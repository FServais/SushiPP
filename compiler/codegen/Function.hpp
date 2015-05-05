#ifndef FUNCTION_HPP_DEFINED
#define FUNCTION_HPP_DEFINED

#include <string>

#include "Value.hpp"

namespace codegen
{
    class Function : public Value
    {
    public:
        Function(std::shared_ptr<typegen::Type>, std::string);

        std::string str_value();

        std::string get_name() const;
        std::string str_name() const;

        std::string get_type_nth_argument(int n) const;
        std::string get_name_nth_argument(int n) const;
        std::string str_name_nth_argument(int n) const;

        std::string get_return_type() const;

        std::string get_signature() const;

    protected:
        std::string name;

        std::string return_type;
        std::vector<std::string> type_arguments;

    };
}

#endif
