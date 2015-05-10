#ifndef LABEL_MANAGER_HPP_DEFINED
#define LABEL_MANAGER_HPP_DEFINED

#include <map>
#include <string>

namespace codegen
{
    class LabelManager
    {
    public:
        LabelManager();

        std::string insert_label(std::string);

        int get_last_occurence_number(std::string);
        std::string get_last_occurence(std::string);

        bool exists(std::string);

    private:
        std::map<std::string, int> labels;

    };

}

#endif
