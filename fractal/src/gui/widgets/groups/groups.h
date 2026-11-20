#pragma once

#include "../../../controller/FractalController.h"
#include "../../UI/UIGroupManager/UIGroupManager.h"
#include "../PixelCanvas/PixelCanvas.h"
#include <FL/Fl_Group.H>

class MenuGroup : public Fl_Group {
  public:
    MenuGroup (int x, int y, int width, int height,
               UIGroupManager& manager);
};

class FractalGroup : public Fl_Group {
  public:
    FractalGroup (int x, int y, int width, int height,
                  UIGroupManager& manager);

    void update ();
    void zoom (double zoom_scale);

  private:
    PixelCanvas* canvas_ = nullptr;
    FractalController controller_;
};
