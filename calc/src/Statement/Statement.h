#pragma once
#include <std_lib_facilities.h>

#include "Variable/Variable.h"

class Statement {
    vector<string> statements{};

   public:
    Statement() {};
    const vector<string>& get_statements() const&;
    void push(const int& val);
    void push(const vector<string>& s);
    void push(const Variable_table& var_table);
    void clear();
};