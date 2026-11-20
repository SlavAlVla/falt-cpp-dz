#include "Colorizer.h"

std::array<unsigned char, 3>
Colorizer::colorize (const FractalResult& result,
                     int max_iterations) const {
    if (!result.escaped) {
        return {0, 0, 0};
    }

    const double t = std::clamp(
        static_cast<double>(result.iterations) / max_iterations, 0.0, 1.0);

    const auto channel = [] (double value) {
        return static_cast<unsigned char>(
            std::clamp(std::lround(value), 0L, 255L));
    };

    return {channel(12.0 * (1.0 - t) * t * t * t * 255.0),
            channel(14.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0),
            channel(8.5 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0)};
}
