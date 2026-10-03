#include "mode.hpp"
#include "constants.hpp"

char get_mode()
{
    vector<char> input;
    char c;
    while (std::cin.get(c) && c != '\n')
    {
        input.push_back(c);
    }

    if (input.size() != 1)
    {
        cout << "input size is not correct\n"
             << endl;
        return '\0';
    }
    char &mode = input[0];
    if (std::find(
            constants::MODES.begin(),
            constants::MODES.end(),
            mode) == constants::MODES.end())
    {
        cout << "invalid input value\n"
             << endl;
        return '\0';
    }
    return mode;
}

bool validate_mode(const int &mode)
{
    if (mode != constants::EXIT_MODE &&
        mode != constants::SINGLE_MODE &&
        mode != constants::COMPUTER_MODE)
    {
        cout << "invalid input\n"
             << endl;
        return false;
    }
    return true;
}