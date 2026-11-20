#pragma once

#include "../../../controller/FractalController.h"
#include "../../../rendering/ImageBuffer.h"
#include <FL/Fl_Widget.H>

class PixelCanvas : public Fl_Widget {
  public:
    PixelCanvas (int x, int y, int width, int height,
                 FractalController& controller,
                 const char* label = nullptr);

    void set_image (ImageBuffer image);
    void draw () override;
    int handle (int event) override;

  private:
    ImageBuffer image_;
    FractalController& controller_;
};
