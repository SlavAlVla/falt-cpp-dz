#include "mode.hpp"
#include "constants.hpp"
#include "help_func.hpp"

char get_mode()
{
    vector<char> input = get_input();
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