#include "game.hpp"
#include "constants.hpp"
#include "help_func.hpp"
#include "user.hpp"

vector<char> generate_number()
{
    vector<char> number(10);
    char c = '0';
    for (char &n : number)
    {
        n = c++;
    }

    std::mt19937 gen(time(nullptr));
    std::shuffle(number.begin(), number.end(), gen);

    number.resize(constants::NUM_SIZE);
    return number;
}

void count_bulls_and_cows(
    int &bulls,
    int &cows,
    const vector<char> &uguess,
    const vector<char> &number)
{
    for (size_t i = 0; i < uguess.size(); ++i)
    {
        if (uguess[i] == number[i])
            ++bulls;
        else if (count(number, uguess[i]) == 1)
            ++cows;
    }
}

void game(const char &mode)
{
    std::cout << "game is on" << endl;

    switch (mode)
    {
    case constants::SINGLE_MODE:
        vector<char> number = generate_number();

        int bulls{}, cows{};

        do
        {
            bulls = 0, cows = 0;

            vector<char> uguess = user_number();
            if (uguess.empty())
            {
                continue;
            }

            count_bulls_and_cows(bulls, cows, uguess, number);

            std::cout << bulls << " bull(s) and " << cows << " cow(s)" << endl;
        } while (bulls != 4);
    }

    std::cout << "game is over\n"
              << endl;
}