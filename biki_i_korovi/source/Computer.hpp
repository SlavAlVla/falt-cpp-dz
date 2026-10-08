#pragma once
#include <std_lib_facilities.h>

class Computer
{
private:
    vector<vector<char>> guess_pool;
    vector<char> guess;
    void generate_pool(int target_length,
                       vector<char> &current,
                       vector<int> &used, // логичнее использовать vector<bool>, но возникают ошибки с ссылкой на бит
                       vector<vector<char>> &result);
    bool is_possible_guess(const int &bulls,
                           const int &cows,
                           const vector<char> &guess,
                           const vector<char> &test_guess);

public:
    Computer();
    void make_guess(const int &bulls,
                    const int &cows);
    vector<char> getGuess() const { return guess; };
};