#pragma once

#include "../config/Settings.h"
#include "Complex.h"
#include "FractalResult.h"

class Mandelbrot {
  public:
    explicit Mandelbrot (
        int max_iterations = settings::Fractal::max_iterations,
        double escape_radius = settings::Fractal::escape_radius);

    void static iteration(Complex& z, const Complex& point);
    FractalResult evaluate (const Complex& point) const;
    int max_iterations () const noexcept;
    void set_max_iterations (const double scale);

  private:
    int max_iterations_;
    double escape_radius_squared_;
};
