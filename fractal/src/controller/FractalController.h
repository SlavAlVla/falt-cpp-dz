#pragma once

#include "../rendering/Renderer.h"

class FractalController {
  public:
    explicit FractalController (Renderer renderer = Renderer{});

    ImageBuffer render (int width, int height) const;
    void set_fractal_max_iterations ();
    Viewport& viewport () noexcept;
    Mandelbrot& fractal () noexcept;
    void set_max_iterations ();
    void center_at (double mouse_x, double mouse_y, int width, int height);
    void zoom_at (double mouse_x, double mouse_y, double factor, int width,
                  int height);

  private:
    Renderer renderer_;
};
