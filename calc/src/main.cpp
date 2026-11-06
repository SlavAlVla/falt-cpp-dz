#include "Calculator/Calculator.h"

int main() try {
    Calculator calculator{};
    calculator.calculate();
} catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    return 1;
} catch (...) {
    cerr << "Oops, unknown exception" << endl;
    return 2;
}