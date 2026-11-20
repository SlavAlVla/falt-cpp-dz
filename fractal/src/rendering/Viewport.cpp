#include "Viewport.h"

#include <stdexcept>

Viewport::Viewport (double center_x, double center_y, double scale)
    : center_x_(center_x), center_y_(center_y), scale_(scale) {
    if (scale_ <= 0.0) {
        throw std::invalid_argument("Viewport scale must be positive");
    }
}

Complex Viewport::screen_to_complex (int x, int y, double half_width,
                                     double half_height) const {
    return {center_x_ + (x - half_width) * scale_,
            center_y_ + (half_height - y) * scale_};
}

void Viewport::center_at (double px, double py, int width, int height) {
    center_x_ += (px - width / 2.0) * scale_;
    center_y_ += (height / 2.0 - py) * scale_;
}

void Viewport::zoom_at (double px, double py, double scale_factor,
                        int width, int height) {

    double mouse_x = center_x_ + (px - width / 2.0) * scale_;

    double mouse_y = center_y_ + (height / 2.0 - py) * scale_;

    scale_ /= scale_factor;

    center_x_ = mouse_x - (px - width / 2.0) * scale_;

    center_y_ = mouse_y - (height / 2.0 - py) * scale_;
}

const double Viewport::scale () const noexcept { return scale_; }