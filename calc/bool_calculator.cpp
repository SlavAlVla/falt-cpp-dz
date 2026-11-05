
// This is example of starting code from Chapter 7.8 "Variables" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup


#include <std_lib_facilities.h>

struct Token
{
  char kind;
  int value;
  string name;

  Token(char ch) : kind{ch}, value{false} {}

  Token(char ch, int val) : kind{ch}, value{val} {}

  Token(char ch, string id) : kind{ch}, name{id} {}
};

class Token_stream
{
  bool full{false};
  Token buffer{'\0'};

public:
  Token_stream() {}

  Token get ();
  void putback (Token t);

  void ignore (char);
};

void Token_stream::putback(Token t)
{
  if (full)
    error("putback() into a full buffer");

  buffer = t;
  full = true;
}

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

Token Token_stream::get()
{
  if (full)
  {
    full = false;
    return buffer;
  }

  char ch;
  cin >> ch;

  switch (ch)
  {
  case '(':
  case ')':
  case '&':
  case '|':
  case '^':
  case '!':
  case '~':
  case print:
  case '=':
    return Token{ch};

  case '0':
  case '1':
  {
    int val = ch - '0';
    while (cin.get(ch) && (ch == '0' || ch == '1'))
      val = val * 2 + (ch - '0');
    cin.putback(ch);
    return Token{number, val};
  }

  default:
    if (isalpha(ch))
    {
      string s;
      s += ch;
      while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
        s += ch;
      cin.putback(ch);

      if (s == declkey)
        return Token{let};

      if (s == quitkey)
        return Token{quit};

      if (s == showkey)
        return Token{show};

      if (s == helpkey)
        return Token{help};

      return Token{name, s};
    }
    error("bad token");
  }
}

void Token_stream::ignore(char c)
{
  if (full && c == buffer.kind)
  {
    full = false;
    return;
  }
  full = false;

  for (char ch; cin >> ch;)
  {
    if (ch == c)
      return;
  }
}

struct Variable
{
  string name;
  int value;

  Variable(string n, int v) : name{n}, value{v} {}
};

vector<Variable> var_table;

int get_value (const string& s)
{
  for (const auto& var : var_table)
  {
    if (var.name == s)
      return var.value;
  }

  error("get: undefined name ", s);
}

void set_value (const string& s, int d)
{
  for (auto& var : var_table)
  {
    if (var.name == s)
    {
      var.value = d;
      return;
    }
  }

  error("set: undefined name ", s);
}

bool is_declared (const string& s)
{
  for (const auto& var : var_table)
  {
    if (var.name == s)
      return true;
  }

  return false;
}

int define_name (const string& var, int val = 0)
{
  if (is_declared(var))
    error(var, " declared twice");

  var_table.push_back(Variable{var, val});

  return val;
}

Token_stream ts;

int expression ();

int primary ()
{
  Token t = ts.get();
  switch (t.kind)
  {
  case '!':
    return !primary();

  case '~':
    return ~primary();

  case '(':
  {
    int d = expression();
    t = ts.get();
    if (t.kind != ')')
      error("'(' expected");
    return d;
  }

  case number:
    return t.value;

  case name:
    return get_value(t.name);

  default:
    error("primary expected");
  }
}

int term ()
{
  int left = primary();

  while (true)
  {
    Token t = ts.get();

    switch (t.kind)
    {
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

    case '^':
    {
      left = left ^ primary();
      break;
    }

    default:
      ts.putback(t);
      return left;
    }
  }
}

int expression ()
{
  int left = term();

  while (true)
  {
    Token t = ts.get();

    switch (t.kind)
    {
    case '|':
    {
      t = ts.get();
      if (t.kind == '|') {
        int factor = term();
        left = left || factor;
        break;
      }
      ts.putback(t);
      left = left | term();
      break;
    }

    default:
      ts.putback(t);
      return left;
    }
  }
}

int declaration ()
{
  Token t = ts.get();
  if (t.kind != name)
    error("name expected in declaration");

  string var = t.name;

  t = ts.get();
  if (t.kind != '=')
    return define_name(var);

  return define_name(var, expression());
}

void get_vars(vector<std::string>& statement_strings) {
  for (const auto& var : var_table) {
    stringstream ss;
    ss << var.name << " = " << var.value;
    statement_strings.push_back(ss.str());
  }
  if (statement_strings.empty()) {
    statement_strings.push_back("No variables defined.");
  }
}

void push_to_statement_strings(vector<std::string>& statement_strings, const int& val) {
  stringstream ss;
  ss << val;
  statement_strings.push_back(ss.str());
}

vector<std::string> statement ()
{
  vector<std::string> statement_strings{};
  Token t = ts.get();
  switch (t.kind)
  {
  case let:
    push_to_statement_strings(statement_strings, declaration());
    break;
  case show:
    get_vars(statement_strings);
    break;
  case help:
    statement_strings = helptext;
    break;
  default:
    ts.putback(t);
    push_to_statement_strings(statement_strings, expression());
  }
  return statement_strings;
}

void clean_up_mess () { ts.ignore(print); }

void calculate ()
{
  while (true)
    try
    {
      cout << prompt;
      Token t = ts.get();
      while (t.kind == print)
        t = ts.get();
      if (t.kind == quit)
        return;

      ts.putback(t);
      for (const auto& statement : statement()) {
        cout << statement << endl;
      }
    }
    catch (runtime_error& e)
    {
      cerr << e.what() << endl;
      clean_up_mess();
    }
}

int main ()
try
{
  calculate();
}
catch (exception& e)
{
  cerr << "exception: " << e.what() << endl;
  return 1;
}
catch (...)
{
  cerr << "Oops, unknown exception" << endl;
  return 2;
}