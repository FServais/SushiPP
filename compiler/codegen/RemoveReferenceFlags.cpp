#include "RemoveReferenceFlags.hpp"

using namespace std;
using namespace codegen;

void RemoveReferenceFlags::add_flag(const string var, const int scope_id)
{
    entries.push_back(make_pair(var, scope_id));
}

bool RemoveReferenceFlags::is_present(const string var, const int scope_id) const
{
    for(auto entry : entries)
        if(entry.first == var && entry.second == scope_id)
            return true;

    return false;
}

vector<string> RemoveReferenceFlags::pop_vars_at_scope(const int scope_id)
{
    vector<string> list;
    for(auto it = entries.rbegin() ; it != entries.rend() ; ++it)
    {
        if(it->second == scope_id)
            list.push_back(it->first);
        else
            break;
    }

    return list;
}
