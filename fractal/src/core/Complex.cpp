#include "Complex.h"

Complex::Complex () : real_{}, imag_{} {}

Complex::Complex (double real, double imag) : real_{real}, imag_{imag} {}

const double Complex::re () const { return real_; }

const double Complex::im () const { return imag_; }

Complex Complex::operator+ (const Complex& c) const {
    return Complex{re() + c.re(), im() + c.im()};
}

Complex Complex::operator* (const Complex& c) const {
    return Complex{re() * c.re() - im() * c.im(),
                   re() * c.im() + im() * c.re()};
}

double Complex::norm (const Complex& c) {
    return c.re() * c.re() + c.im() + c.im();
}