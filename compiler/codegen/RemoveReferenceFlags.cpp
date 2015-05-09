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
    int num_to_pop = 0;

    for(int i = entries.size()-1 ; i >= 0 ; --i)
    {
        if(entries[i].second == scope_id)
        {
            list.push_back(entries[i].first);
            ++num_to_pop;
        }
        else
            break;
    }

    entries.erase(entries.begin() + entries.size() - num_to_pop, entries.end());

    return list;
}
