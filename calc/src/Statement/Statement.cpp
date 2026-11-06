#include "Statement/Statement.h"

#include "Variable/Variable.h"

const vector<string>& Statement::get_statements() const& { return statements; }

void Statement::push(const int& val) {
    stringstream ss;
    ss << val;
    statements.push_back(ss.str());
}

void Statement::push(const vector<string>& vs) {
    for (const string s : vs) statements.push_back(s);
}

void Statement::push(const Variable_table& var_table) {
    for (const auto& var : var_table.get_table()) {
        stringstream ss;
        ss << var.name << " = " << var.value;
        statements.push_back(ss.str());
    }
    if (statements.empty()) {
        statements.push_back("No variables defined.");
    }
}

void Statement::clear() { statements.clear(); }