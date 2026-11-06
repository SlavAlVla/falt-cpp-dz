#include "Token.h"

#include <std_lib_facilities.h>

#include "constants/constants.h"

void Token_stream::putback(Token t) {
    if (full) error("putback() into a full buffer");

    buffer = t;
    full = true;
}

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;

    switch (ch) {
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
        case '1': {
            int val = ch - '0';
            while (cin.get(ch) && (ch == '0' || ch == '1'))
                val = val * 2 + (ch - '0');
            cin.putback(ch);
            return Token{number, val};
        }

        default:
            if (isalpha(ch)) {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
                    s += ch;
                cin.putback(ch);

                if (s == declkey) return Token{let};

                if (s == quitkey) return Token{quit};

                if (s == showkey) return Token{show};

                if (s == helpkey) return Token{help};

                return Token{name, s};
            }
            error("bad token");
    }
}

void Token_stream::ignore(char c) {
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    for (char ch; cin >> ch;) {
        if (ch == c) return;
    }
}