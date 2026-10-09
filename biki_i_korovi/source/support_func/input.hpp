#pragma once
#include <std_lib_facilities.h>

inline vector<char> get_input()
{
    vector<char> input;
    char c;
    while (std::cin.get(c) && c != '\n')
    {
        input.push_back(c);
    }
    if (!std::cin)
        error("invalid input");
    return input;
}