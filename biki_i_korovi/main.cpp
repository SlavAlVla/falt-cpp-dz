// A little guessing game called
//    (for some obscure reason) <<Bulls and Cows>>.

#include <std_lib_facilities.h>

namespace constants
{
    constexpr size_t NUM_SIZE = 4;
    constexpr char EXIT_MODE = '0';
    constexpr char SINGLE_MODE = '1';
    constexpr char COMPUTER_MODE = '2';
    const vector<char> MODES = {EXIT_MODE, SINGLE_MODE, COMPUTER_MODE};
}

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

int count(const vector<char> &digits, char d)
{
    int k{};

    for (size_t i = 0; i < digits.size(); ++i)
        if (digits[i] == d)
            ++k;

    return k;
}

bool validate_number(const vector<char> &number)
{
    if (number.size() != constants::NUM_SIZE)
    {
        std::cout << "number size is not correct" << endl;
        return false;
    }
    for (size_t i = 0; i < number.size(); ++i)
    {
        if (number[i] < '0' || '9' < number[i])
        {
            std::cout << "the number contains not a digit" << endl;
            return false;
        }

        if (count(number, number[i]) != 1)
        {
            std::cout << "digits of the number are not unique" << endl;
            return false;
        }
    }
    return true;
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

vector<char> user_guess()
{
    vector<char> number;
    char c;

    std::cout << "guess the number: ";
    while (std::cin.get(c) && c != '\n')
    {
        number.push_back(c);
    }

    if (!std::cin)
        error("invalid input");

    if (!validate_number(number))
    {
        return vector<char>();
    }

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

            vector<char> uguess = user_guess();
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

int main()
try
{
    std::cout << "<<Bulls and Cows>>\n"
              << "Computer sets a number of 4 unique digits.\n"
              << "Try to guess it.\n"
              << "<Bull> means right digit in the right position.\n"
              << "<Cow> means right digit in the wrong position.\n"
              << "\n";

    char mode = '0';
    while (true)
    {
        std::cout << "Choose game mode:\n"
                  << constants::EXIT_MODE << ": quit the game\n"
                  << constants::SINGLE_MODE << ": single game\n"
                  << constants::COMPUTER_MODE << ": game with computer\n"
                  << "> ";
        mode = get_mode();
        if (mode == '\0')
        {
            continue;
        }
        std::cout << '\n';

        if (mode == constants::EXIT_MODE)
        {
            break;
        }
        game(mode);
    }
}
catch (exception &e)
{
    cerr << e.what() << endl;
    return 1;
}
catch (...)
{
    cerr << "Oops, something went wrong..." << endl;
    return 2;
}
