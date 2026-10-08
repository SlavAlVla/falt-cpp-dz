#pragma once
#include <std_lib_facilities.h>

vector<char> generate_number();
void count_bulls_and_cows(
    int &bulls,
    int &cows,
    const vector<char> &uguess,
    const vector<char> &number);
void game(const char &mode);