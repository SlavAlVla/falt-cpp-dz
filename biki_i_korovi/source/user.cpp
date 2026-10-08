#include "user.hpp"
#include "constants.hpp"
#include "help_func.hpp"

vector<char> user_number()
{
    vector<char> number = get_input();

    if (number.size() == 1 && number[0] == 'q')
    {
        return number;
    }

    if (!validate_number(number))
    {
        return vector<char>();
    }

    return number;
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