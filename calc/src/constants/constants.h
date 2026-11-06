#pragma once
#include <std_lib_facilities.h>

constexpr char quit = 'q';
constexpr char print = ';';
constexpr char number = '1';
constexpr char name = 'a';
constexpr char let = 'L';
constexpr char show = 's';
constexpr char help = 'h';

const string prompt = ">> ";
const string declkey = "let";
const string quitkey = "quit";
const string showkey = "show";
const string helpkey = "help";
const vector<std::string> helptext{
    "помощь:                  help",
    "выйти:                   quit",
    "задать переменную:       let <имя> = <значение>",
    "показать переменные:     show",
    "поддерживаемые операции: & && | || ^ ! ~",
};