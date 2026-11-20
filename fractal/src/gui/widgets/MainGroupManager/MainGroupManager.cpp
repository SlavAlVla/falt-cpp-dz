#include "MainGroupManager.h"

#include "../../../config/Settings.h"
#include "../groups/groups.h"
#include <FL/Fl_Window.H>
#include <memory>

MainGroupManager::MainGroupManager (Fl_Window& window) {
    auto* menu = new MenuGroup(0, 0, settings::Window::width,
                               settings::Window::height, *this);
    auto* fractal = new FractalGroup(0, 0, settings::Window::width,
                                     settings::Window::height, *this);

    menu->hide();
    fractal->hide();

    add_group('f', fractal);
    add_group('m', menu);

    switch_group('m');
}
