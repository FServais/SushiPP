#include "util.hpp"

#include <algorithm> // generate_n
#include <cstdlib> // rand 

std::string util::random_string(size_t length)
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length,0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}

std::string util::remove_extension(const std::string& filename)
{
    size_t pos_of_dot = filename.find_last_of('.');
    return filename.substr(0, pos_of_dot);
}