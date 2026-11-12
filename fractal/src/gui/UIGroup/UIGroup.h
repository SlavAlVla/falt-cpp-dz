#pragma once
#include "UIButton/UIButton.h"
#include "UIGroupManager/UIGroupManager.h"
#include <FL/Fl_Group.H>

class UIGroup : public Fl_Group {
  protected:
    UIGroupManager* manager_;

  public:
    UIGroup (int w, int h, UIGroupManager* m, int x = 0, int y = 0)
        : Fl_Group{x, y, w, h} {
        manager_ = m;
    };

    virtual ~UIGroup () = default;
};

class MenuGroup : public UIGroup {
  private:
    SwitchGroupButton* to_fractal_btn;

  public:
    MenuGroup (int w, int h, UIGroupManager* m, int x = 0, int y = 0);
};

class FractalGroup : public UIGroup {
  private:
    SwitchGroupButton* to_menu_btn;

  public:
    FractalGroup (int w, int h, UIGroupManager* m, int x = 0, int y = 0);
};