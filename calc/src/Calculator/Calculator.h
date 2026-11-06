#pragma once
#include "Statement/Statement.h"
#include "Token/Token.h"
#include "Variable/Variable.h"

class Calculator {
    Statement statement{};
    Token_stream ts{};
    Variable_table var_table{};

    int primary();
    int term();
    int expression();
    int declaration();
    void make_statement();

   public:
    Calculator() {};
    void calculate();
    void clean_up_mess();
};