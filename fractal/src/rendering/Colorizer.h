#pragma once

#include "../core/FractalResult.h"
#include <array>

class Colorizer {
public:
    std::array<unsigned char, 3> colorize(const FractalResult& result,
                                         int max_iterations) const;
};
