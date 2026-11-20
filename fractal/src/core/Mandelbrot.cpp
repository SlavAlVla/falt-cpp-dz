#include "Mandelbrot.h"
#include <cmath>
#include <stdexcept>

Mandelbrot::Mandelbrot (int max_iterations, double escape_radius)
    : max_iterations_(max_iterations),
      escape_radius_squared_(escape_radius * escape_radius) {
    if (max_iterations_ <= 0 || escape_radius <= 0.0) {
        throw std::invalid_argument("Invalid Mandelbrot parameters");
    }
}

void Mandelbrot::iteration (Complex& z, const Complex& point) {
    // z = Complex{std::abs(z.re()), std::abs(z.im())};
    z = z * z + point;
}

FractalResult Mandelbrot::evaluate (const Complex& point) const {
    Complex z{};

    for (int iteration = 0; iteration < max_iterations_; ++iteration) {
        if (Complex::norm(z) > escape_radius_squared_) {
            return {iteration, true};
        }
        Mandelbrot::iteration(z, point);
    }

    return {max_iterations_, false};
}

int Mandelbrot::max_iterations () const noexcept { return max_iterations_; }

void Mandelbrot::set_max_iterations (const double scale) {
    max_iterations_ = static_cast<int>(
        settings::Fractal::max_iter_koeff1 +
        settings::Fractal::max_iter_koeff2 *
            std::log2(settings::Fractal::max_iter_koeff3 / scale));
}