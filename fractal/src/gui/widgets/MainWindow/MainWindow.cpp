#include "MainWindow.h"

#include "../../../config/Settings.h"
#include "../MainGroupManager/MainGroupManager.h"

MainWindow::MainWindow ()
    : Fl_Window{settings::Window::width, settings::Window::height,
                "Fractal"},
      manager_{std::make_unique<MainGroupManager>(*this)} {}

MainWindow::~MainWindow () = default;
