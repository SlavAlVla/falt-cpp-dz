#pragma once
#include <std_lib_facilities.h>

struct Token {
    char kind;
    int value;
    std::string name;

    Token(char ch) : kind{ch}, value{false} {}

    Token(char ch, int val) : kind{ch}, value{val} {}

    Token(char ch, std::string id) : kind{ch}, name{id} {}
};

class Token_stream {
    bool full{false};
    Token buffer{'\0'};

   public:
    Token_stream() {}

    Token get();
    void putback(Token t);
    void ignore(char);
};