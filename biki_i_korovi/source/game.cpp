#include "game.hpp"
#include "constants.hpp"
#include "help_func.hpp"
#include "user.hpp"
#include "Computer.hpp"

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
    bulls = 0, cows = 0;
    for (size_t i = 0; i < uguess.size(); ++i)
    {
        if (uguess[i] == number[i])
            ++bulls;
        else if (count(number, uguess[i]) == 1)
            ++cows;
    }
    std::cout << bulls << " bull(s) and " << cows << " cow(s)" << endl;
}

void game(const char &mode)
{
    std::cout << "game is on. Type 'q' to leave the game" << endl;

    vector<char> number, uguess;
    int bulls{}, cows{}, attempts{};
    switch (mode)
    {
    case constants::SINGLE_MODE:
        number = generate_number();
        attempts = 0;
        do
        {
            attempts++;
            std::cout << "attempt " << attempts << endl;
            bulls = 0, cows = 0;

            std::cout << "guess the number: ";
            uguess = user_number();
            if (uguess.empty())
            {
                attempts--;
                continue;
            }
            if (uguess[0] == 'q')
            {
                break;
            }
            count_bulls_and_cows(bulls, cows, uguess, number);
        } while (bulls != 4);

        std::cout << "game is over with " << attempts << " attempts" << endl
                  << endl;
        break;

    case constants::COMPUTER_MODE:
        Computer computer{};
        int cbulls, ccows;
        vector<char> unumber;

        do
        {
            std::cout << "guess your number: ";
            unumber = user_number();
        } while (unumber.empty());
        if (unumber[0] == 'q')
        {
            std::cout << endl;
            break;
        }
        std::cout << "your number is "
                  << std::string_view(unumber.data(), unumber.size()) << ". ";
        number = generate_number();
        attempts = 0;
        std::cout << "Now guess computer's number"
                  << endl;
        do
        {
            attempts++;
            std::cout << "attempt " << attempts << endl;

            std::cout << "guess the number: ";
            uguess = user_number();
            if (uguess.empty())
            {
                attempts--;
                continue;
            }
            if (uguess[0] == 'q')
            {
                break;
            }
            count_bulls_and_cows(bulls, cows, uguess, number);
            if (bulls == 4)
                break;

            std::cout << "computer's guess: "
                      << std::string_view(computer.getGuess().data(), computer.getGuess().size())
                      << " (you guessed "
                      << std::string_view(unumber.data(), unumber.size()) << ")"
                      << endl;
            count_bulls_and_cows(cbulls, ccows, computer.getGuess(), unumber);
            computer.make_guess(cbulls, ccows);
        } while (bulls != 4 && cbulls != 4);

        std::cout << "game is over with " << attempts << " attempts" << endl;
        if (bulls == 4)
            std::cout << "user wins!\n"
                      << endl;
        if (cbulls == 4)
            std::cout << "computer wins!\n"
                      << endl;
        break;
    }
}