#include "ImageBuffer.h"

ImageBuffer::ImageBuffer (int width, int height)
    : width_(width), height_(height) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Image dimensions must be positive");
    }

    const auto pixel_count =
        static_cast<std::size_t>(width) * static_cast<std::size_t>(height);

    pixels_.resize(pixel_count * 3);
}

int ImageBuffer::width () const noexcept { return width_; }

int ImageBuffer::height () const noexcept { return height_; }

bool ImageBuffer::empty () const noexcept { return pixels_.empty(); }

unsigned char* ImageBuffer::data () noexcept { return pixels_.data(); }

const unsigned char* ImageBuffer::data () const noexcept {
    return pixels_.data();
}

std::size_t ImageBuffer::size () const noexcept { return pixels_.size(); }

void ImageBuffer::set_pixel (int x, int y, unsigned char red,
                             unsigned char green, unsigned char blue) {
    if (x < 0 || y < 0 || x >= width_ || y >= height_) {
        return;
    }

    const auto index = (static_cast<std::size_t>(y) * width_ + x) * 3;
    pixels_[index] = red;
    pixels_[index + 1] = green;
    pixels_[index + 2] = blue;
}
