#ifndef FUNCTION_HPP_DEFINED
#define FUNCTION_HPP_DEFINED

#include <string>

#include "Value.hpp"

namespace codegen
{
    class Function : public Value
    {
    public:
        // Return type, name, arguments
        Function(std::shared_ptr<typegen::Type>, std::string&, std::vector<std::shared_ptr<Value>>);

        // //Function(std::shared_ptr<typegen::Type>, std::string&, std::vector<std::string>&);
        // Function(std::shared_ptr<typegen::Type>, std::string&, std::vector<Value&>&);
        //
        // std::string str_value();

        std::string get_name() const;
        std::string str_name() const;
        //
        std::shared_ptr<typegen::Type> get_type_nth_argument(int n);
        std::string str_type_nth_argument(int n);
        //
        std::string get_name_nth_argument(int n);
        std::string str_name_nth_argument(int n);
        //
        std::shared_ptr<typegen::Type> get_return_type();
        std::string str_return_type();
        //
        std::string get_signature();

        std::string get_function_call();
        int nb_args() const;

    protected:
        std::string name;
        std::vector<std::shared_ptr<Value>> args;
    };
}

#endif
