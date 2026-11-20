#include "Renderer.h"

#include <stdexcept>

Renderer::Renderer (Mandelbrot fractal, Viewport viewport,
                    Colorizer colorizer)
    : fractal_(std::move(fractal)), viewport_(std::move(viewport)),
      colorizer_(std::move(colorizer)) {}

ImageBuffer Renderer::render (int width, int height) const {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Render dimensions must be positive");
    }

    ImageBuffer image(width, height);

    int half_width = width / 2.0;
    int half_height = height / 2.0;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const auto point =
                viewport_.screen_to_complex(x, y, half_width, half_height);
            const auto result = fractal_.evaluate(point);
            const auto rgb =
                colorizer_.colorize(result, fractal_.max_iterations());

            image.set_pixel(x, y, rgb[0], rgb[1], rgb[2]);
        }
    }

    return image;
}

Viewport& Renderer::viewport () noexcept { return viewport_; }

const Viewport& Renderer::viewport () const noexcept { return viewport_; }

Mandelbrot& Renderer::fractal () noexcept { return fractal_; }

const Mandelbrot& Renderer::fractal () const noexcept { return fractal_; }
