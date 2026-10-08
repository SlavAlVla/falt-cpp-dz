#include "help_func.hpp"

int count(const vector<char> &digits, char d)
{
    int k{};

    for (size_t i = 0; i < digits.size(); ++i)
        if (digits[i] == d)
            ++k;

    return k;
}

vector<char> get_input()
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