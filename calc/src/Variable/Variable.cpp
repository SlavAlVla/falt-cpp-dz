#include "Variable.h"

#include <std_lib_facilities.h>

const vector<Variable>& Variable_table::get_table () const& {
    return var_table;
}

int Variable_table::get_value (const string& s) const& {
    for (const auto& var : var_table) {
        if (var.name == s)
            return var.value;
    }

    error("get: undefined name ", s);
}

void Variable_table::set_value (const string& s, int d) {
    for (auto& var : var_table) {
        if (var.name == s) {
            var.value = d;
            return;
        }
    }

    error("set: undefined name ", s);
}

bool Variable_table::is_declared (const string& s) const& {
    for (const auto& var : var_table) {
        if (var.name == s)
            return true;
    }

    return false;
}

int Variable_table::define_name (const string& s, int val) {
    if (is_declared(s)) {
        set_value(s, val);
        return val;
    }

    var_table.push_back(Variable{s, val});

    return val;
}