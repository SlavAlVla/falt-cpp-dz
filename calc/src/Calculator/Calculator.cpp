#include "Calculator/Calculator.h"

#include <std_lib_facilities.h>

#include "constants/constants.h"

int Calculator::primary () {
  Token t = ts.get();
  switch (t.kind) {
  case '!':
    return !primary();

  case '~':
    return ~primary();

  case '(': {
    int d = expression();
    t = ts.get();
    if (t.kind != ')')
      error("'(' expected");
    return d;
  }

  case number:
    return t.value;

  case name:
    return var_table.get_value(t.name);

  default:
    error("primary expected");
  }
}

int Calculator::term () {
  int left = primary();

  while (true) {
    Token t = ts.get();

    switch (t.kind) {
    case '&':
      t = ts.get();
      if (t.kind == '&') {
        int factor = primary();
        left = left && factor;
        break;
      }
      ts.putback(t);
      left = left & primary();
      break;

    case '^': {
      left = left ^ primary();
      break;
    }

    default:
      ts.putback(t);
      return left;
    }
  }
}

int Calculator::expression () {
  int left = term();

  while (true) {
    Token t = ts.get();

    switch (t.kind) {
    case '|':
      t = ts.get();
      if (t.kind == '|') {
        int factor = term();
        left = left || factor;
        break;
      }
      ts.putback(t);
      left = left | term();
      break;

    default:
      ts.putback(t);
      return left;
    }
  }
}

int Calculator::declaration () {
  Token t = ts.get();
  if (t.kind != name)
    error("name expected in declaration");

  string var = t.name;

  t = ts.get();
  if (t.kind == print)
    return var_table.define_name(var);
  if (t.kind == '=')
    return var_table.define_name(var, expression());
  error("Bad syntaxis");
}

void Calculator::make_statement () {
  Token t = ts.get();
  switch (t.kind) {
  case let:
    statement.push(declaration());
    break;
  case show:
    statement.push(var_table);
    break;
  case help:
    statement.push(helptext);
    break;
  default:
    ts.putback(t);
    statement.push(expression());
  }
}

void Calculator::clean_up_mess () { ts.ignore(print); }

void Calculator::calculate () {
  while (true)
    try {
      cout << prompt;
      Token t = ts.get();
      while (t.kind == print)
        t = ts.get();
      if (t.kind == quit)
        return;

      ts.putback(t);
      make_statement();
      for (const auto& sm : statement.get_statements()) {
        cout << sm << endl;
      }
      statement.clear();
    } catch (runtime_error& e) {
      cerr << e.what() << endl;
      clean_up_mess();
    }
}