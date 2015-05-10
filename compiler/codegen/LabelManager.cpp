#include <sstream>

#include "LabelManager.hpp"

using namespace std;
using namespace codegen;

LabelManager::LabelManager () { }

string LabelManager::insert_label(string var)
{
    if(!exists(var))
        labels[var] = 0;
    else
        ++labels[var];

    return get_last_occurence(var);
}


int LabelManager::get_last_occurence_number(string var)
{
    return labels[var];
}

string LabelManager::get_last_occurence(string var)
{
    stringstream ss;

    if(!exists(var))
        labels[var] = 0;

    int value = labels[var];

    if(value == 0)
        return var;

    ss << var << "." << to_string(value);

    return ss.str();
}

void LabelManager::decrease_occurence(std::string var)
{
    if(!exists(var))
        labels[var] = 0;
    else
        --(labels[var]);
}


bool LabelManager::exists(string var)
{
    return labels.find(var) != labels.end();
}
