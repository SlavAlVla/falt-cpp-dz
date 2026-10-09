#include "game_mode.hpp"
#include "../constants/constants.hpp"
#include "../support_func/input.hpp"

char get_game_mode()
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