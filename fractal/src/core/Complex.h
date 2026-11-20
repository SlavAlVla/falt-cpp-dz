#pragma once

class Complex {
  public:
    Complex ();
    Complex (double real, double imag);
    const double re () const;
    const double im () const;
    Complex operator+ (const Complex& c) const;
    Complex operator* (const Complex& c) const;
    static double norm (const Complex& c);

  private:
    double real_;
    double imag_;
};