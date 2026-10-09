#pragma once
#include <std_lib_facilities.h>

inline int count(const vector<char> &digits, char d)
{
    int k{};

    for (size_t i = 0; i < digits.size(); ++i)
        if (digits[i] == d)
            ++k;

    return k;
}