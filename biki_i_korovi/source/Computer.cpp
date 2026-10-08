#include "Computer.hpp"
#include "constants.hpp"
#include "help_func.hpp"

void Computer::generate_pool(int target_length,
                             vector<char> &current,
                             vector<int> &used, // логичнее использовать vector<bool>, но возникают ошибки с ссылкой на бит
                             vector<vector<char>> &result)
{
    if (current.size() == target_length)
    {
        result.push_back(current);
        return;
    }

    for (char c = '0'; c <= '9'; ++c)
    {
        if (!used[c - '0'])
        {
            used[c - '0'] = 1;
            current.push_back(c);

            generate_pool(target_length, current, used, result);

            current.pop_back();
            used[c - '0'] = 0;
        }
    }
}

Computer::Computer()
{
    vector<int> used(10, 0);
    generate_pool(constants::NUM_SIZE, vector<char>(), used, guess_pool);

    std::mt19937 gen(time(nullptr));
    std::uniform_int_distribution<> rand_guess(0, guess_pool.size() - 1);
    guess = guess_pool[rand_guess(gen)];
}

bool Computer::is_possible_guess(const int &bulls,
                                 const int &cows,
                                 const vector<char> &guess,
                                 const vector<char> &test_guess)
{
    int test_bulls = 0, test_cows = 0;
    for (size_t i = 0; i < guess.size(); ++i)
    {
        if (guess[i] == test_guess[i])
            ++test_bulls;
        else if (count(test_guess, guess[i]) == 1)
            ++test_cows;
    }
    if (test_bulls == bulls && test_cows == cows)
        return true;
    return false;
}

void Computer::make_guess(const int &bulls,
                          const int &cows)
{
    for (size_t i = 0; i < guess_pool.size(); ++i)
    {
        if (!is_possible_guess(bulls, cows, guess, guess_pool[i]))
        {
            guess_pool.erase(guess_pool.begin() + i);
            i--;
        }
    }
    guess = guess_pool[0];
}
