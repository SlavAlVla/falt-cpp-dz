#pragma once
#include "UIGroupManager/UIGroupManager.h"
#include "constants/constants.h"
#include <FL/Fl_Window.H>

class MainWindow : public Fl_Window {
    UIGroupManager* manager;

  public:
    MainWindow ()
        : Fl_Window{WinSettings::WIN_W, WinSettings::WIN_H, "Fractal"} {
        manager = new MainGroupManager{};
        this->end();
    }
};