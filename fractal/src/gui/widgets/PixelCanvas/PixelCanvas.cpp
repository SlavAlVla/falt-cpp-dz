#include "PixelCanvas.h"

#include <FL/Fl_Group.H>
#include <FL/fl_draw.H>

PixelCanvas::PixelCanvas (int x, int y, int width, int height,
                          FractalController& controller, const char* label)
    : Fl_Widget(x, y, width, height, label), image_(width, height),
      controller_{controller} {}

void PixelCanvas::set_image (ImageBuffer image) {
    image_ = std::move(image);

    if (parent()) {
        parent()->redraw();
    } else {
        redraw();
    }
}

void PixelCanvas::draw () {
    if (image_.empty()) {
        return;
    }

    fl_draw_image(image_.data(), x(), y(), image_.width(), image_.height(),
                  3);
}

int PixelCanvas::handle (int event) {
    switch (event) {
    case FL_RELEASE: {
        controller_.center_at(Fl::event_x() - x(), Fl::event_y() - y(), w(),
                              h());
        set_image(controller_.render(w(), h()));
        return 1;
    }
    case FL_MOUSEWHEEL: {
        double factor = Fl::event_dy() < 0
                            ? settings::View::mouse_sensitivity
                            : 1.0 / settings::View::mouse_sensitivity;
        controller_.zoom_at(Fl::event_x() - x(), Fl::event_y() - y(),
                            factor, w(), h());
        set_image(controller_.render(w(), h()));

        return 1;
    }
    }

    return Fl_Widget::handle(event);
}