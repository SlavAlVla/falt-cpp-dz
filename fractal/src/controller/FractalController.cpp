#include "FractalController.h"

FractalController::FractalController (Renderer renderer)
    : renderer_(std::move(renderer)) {}

ImageBuffer FractalController::render (int width, int height) const {
    return renderer_.render(width, height);
}

Viewport& FractalController::viewport () noexcept {
    return renderer_.viewport();
}

Mandelbrot& FractalController::fractal () noexcept {
    return renderer_.fractal();
}

void FractalController::center_at (double mouse_x, double mouse_y,
                                   int width, int height) {
    viewport().center_at(mouse_x, mouse_y, width, height);
}

void FractalController::zoom_at (double mouse_x, double mouse_y,
                                 double factor, int width, int height) {
    viewport().zoom_at(mouse_x, mouse_y, factor, width, height);
    fractal().set_max_iterations(viewport().scale());
}