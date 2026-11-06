#pragma once
#include <std_lib_facilities.h>

struct Variable {
    string name;
    int value;

    Variable(string n, int v) : name{n}, value{v} {}
};

class Variable_table {
    vector<Variable> var_table{};

    bool is_declared(const string& s) const&;

   public:
    Variable_table() {};
    const vector<Variable>& get_table() const&;
    int get_value(const string& s) const&;
    void set_value(const string& s, int d);
    int define_name(const string& var, int val = 0);
};