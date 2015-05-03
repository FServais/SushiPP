#include <sstream>

#include "VariableManager.hpp"

using namespace std;
using namespace codegen;

VariableManager::VariableManager () { }

string VariableManager::insert_variable(string var)
{
    if(!exists(var))
        variables[var] = 0;
    else
        ++variables[var];

    return get_last_occurence(var);
}


int VariableManager::get_last_occurence_number(string var)
{
    return variables[var];
}

string VariableManager::get_last_occurence(string var)
{
    stringstream ss;

    if(!exists(var))
        variables[var] = 0;

    int value = variables[var];

    if(value == 0)
        return var;

    ss << var << "." << to_string(value);

    return ss.str();
}


bool VariableManager::exists(string var)
{
    return variables.find(var) != variables.end();
}
