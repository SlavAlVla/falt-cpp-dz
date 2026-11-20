#include "groups.h"
#include "../buttons/buttons.h"
#include <iostream>

#include "../../../config/Settings.h"

using btn = settings::Button;
using frkt = settings::Fractal;
using view = settings::View;

MenuGroup::MenuGroup (int x, int y, int width, int height,
                      UIGroupManager& manager)
    : Fl_Group(x, y, width, height) {
    begin();
    new SwitchGroupButton(btn::padding, btn::padding, btn::width,
                          btn::height, "Open fractal", manager, 'f');
    end();
}

FractalGroup::FractalGroup (int x, int y, int width, int height,
                            UIGroupManager& manager)
    : Fl_Group(x, y, width, height),
      controller_(
          Renderer(Mandelbrot(frkt::max_iterations, frkt::escape_radius),
                   Viewport(view::center_x, view::center_y, view::scale))) {
    begin();

    canvas_ = new PixelCanvas(0, 0, width, height, controller_);
    new SwitchGroupButton(btn::padding, btn::padding, btn::width,
                          btn::height, "To menu", manager, 'm');

    new UpdateGroupButton(btn::padding * 2 + btn::width, btn::padding,
                          btn::width, btn::height, "Draw", *this);

    new ZoomButton(btn::padding * 3 + btn::width * 2, btn::padding,
                   btn::width, btn::height, "Zoom in", *this,
                   view::mouse_sensitivity);

    new ZoomButton(btn::padding * 4 + btn::width * 3, btn::padding,
                   btn::width, btn::height, "Zoom out", *this,
                   1. / view::mouse_sensitivity);

    end();
}

void FractalGroup::update () {
    if (!canvas_) {
        return;
    }
    controller_.set_fractal_max_iterations();
    canvas_->set_image(controller_.render(canvas_->w(), canvas_->h()));
}

void FractalGroup::zoom (double zoom_scale) {
    if (!canvas_) {
        return;
    }
    controller_.zoom_at(canvas_->w() / 2, canvas_->h() / 2, zoom_scale,
                        canvas_->w(), canvas_->h());
    controller_.set_fractal_max_iterations();
    canvas_->set_image(controller_.render(canvas_->w(), canvas_->h()));
}