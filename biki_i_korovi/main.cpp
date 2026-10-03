// A little guessing game called
//    (for some obscure reason) <<Bulls and Cows>>.

#include <std_lib_facilities.h>

namespace constants
{
    constexpr size_t NUM_SIZE = 4;
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

bool validate(const vector<char> &number)
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

    if (!validate(number))
    {
        return vector<char>();
    }

    return number;
}

void count_bulls_and_cows(
    int& bulls,
    int& cows,
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

void game() {
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

    std::cout << "game is over" << endl;
}

int main()
try
{
    std::cout << "<<Bulls and Cows>>\n"
              << "Computer sets a number of 4 unique digits.\n"
              << "Try to guess it.\n"
              << "<Bull> means right digit in the right position.\n"
              << "<Cow> means right digit in the wrong position.\n"
              << "\n"
              << "game is on" << endl;
    game();
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
