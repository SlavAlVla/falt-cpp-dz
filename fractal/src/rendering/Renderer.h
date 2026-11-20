#pragma once

#include "../core/Mandelbrot.h"
#include "Colorizer.h"
#include "ImageBuffer.h"
#include "Viewport.h"

class Renderer {
  public:
    Renderer (Mandelbrot fractal = Mandelbrot{},
              Viewport viewport = Viewport{},
              Colorizer colorizer = Colorizer{});

    ImageBuffer render (int width, int height) const;

    Viewport& viewport () noexcept;
    const Viewport& viewport () const noexcept;
    Mandelbrot& fractal () noexcept;
    const Mandelbrot& fractal () const noexcept;

  private:
    Mandelbrot fractal_;
    Viewport viewport_;
    Colorizer colorizer_;
};
