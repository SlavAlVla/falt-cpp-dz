#pragma once

#include "../config/Settings.h"
#include "../core/Complex.h"

class Viewport {
  public:
    Viewport (double center_x = settings::View::center_x,
              double center_y = settings::View::center_y,
              double scale = settings::View::scale);

    Complex screen_to_complex (int x, int y, double half_width,
                               double half_height) const;
    void center_at (double px, double py, int width, int height);
    void zoom_at (double px, double py, double scale_factor, int width,
                  int height);

    const double scale () const noexcept;

  private:
    double center_x_;
    double center_y_;
    double scale_;
};
