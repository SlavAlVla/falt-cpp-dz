#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

class ImageBuffer {
  public:
    ImageBuffer () = default;
    ImageBuffer (int width, int height);

    int width () const noexcept;
    int height () const noexcept;
    bool empty () const noexcept;

    unsigned char* data () noexcept;
    const unsigned char* data () const noexcept;
    std::size_t size () const noexcept;

    void set_pixel (int x, int y, unsigned char red, unsigned char green,
                    unsigned char blue);

  private:
    int width_;
    int height_;
    std::vector<unsigned char> pixels_;
};
