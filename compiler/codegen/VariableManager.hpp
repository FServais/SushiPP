#ifndef VARIABLE_MANAGER_HPP_DEFINED
#define VARIABLE_MANAGER_HPP_DEFINED

#include <map>
#include <string>

namespace codegen
{
    class VariableManager
    {
    public:
        VariableManager ();

        std::string insert_variable(std::string);

        int get_last_occurence_number(std::string);
        std::string get_last_occurence(std::string);

        bool exists(std::string);

    private:
        std::map<std::string, int> variables;

    };

}

#endif
