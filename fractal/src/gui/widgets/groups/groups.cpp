#include "groups.h"
#include "../buttons/buttons.h"

#include "../../../config/Settings.h"

MenuGroup::MenuGroup (int x, int y, int width, int height,
                      UIGroupManager& manager)
    : Fl_Group(x, y, width, height) {
    begin();
    new SwitchGroupButton(settings::Button::padding,
                          settings::Button::padding,
                          settings::Button::width, settings::Button::height,
                          "Open fractal", manager, 'f');
    end();
}

FractalGroup::FractalGroup (int x, int y, int width, int height,
                            UIGroupManager& manager)
    : Fl_Group(x, y, width, height),
      controller_(Renderer(Mandelbrot(settings::Fractal::max_iterations,
                                      settings::Fractal::escape_radius),
                           Viewport(settings::View::center_x,
                                    settings::View::center_y,
                                    settings::View::scale))) {
    begin();

    canvas_ = new PixelCanvas(0, 0, width, height, controller_);
    new SwitchGroupButton(settings::Button::padding,
                          settings::Button::padding,
                          settings::Button::width, settings::Button::height,
                          "To menu", manager, 'm');
    new UpdateGroupButton(
        settings::Button::width + settings::Button::margin,
        settings::Button::padding, settings::Button::width,
        settings::Button::height, "Draw", *this);

    end();
}

void FractalGroup::update () {
    if (!canvas_) {
        return;
    }
    canvas_->set_image(controller_.render(canvas_->w(), canvas_->h()));
}
