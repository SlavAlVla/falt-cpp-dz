#pragma once
#include "UIGroupManager/UIGroupManager.h"
#include "constants/constants.h"
#include <FL/Fl_Button.H>

class UIButton : public Fl_Button {
    static void fltk_callback (Fl_Widget* wid, void* data);

  protected:
    virtual void on_click () = 0;

  public:
    UIButton (int w, int h, const char* n, int x = 0, int y = 0)
        : Fl_Button{x, y, w, h, n} {
        this->callback(fltk_callback, this);
    };

    virtual ~UIButton () = default;
};

class SwitchGroupButton : public UIButton {
    UIGroupManager* manager_;
    GroupType gr_;
    void on_click () override;

  public:
    SwitchGroupButton (int w, int h, const char* n, UIGroupManager* m,
                       GroupType gr, int x = 0, int y = 0)
        : UIButton{w, h, n, x, y} {
        manager_ = m;
        gr_ = gr;
    }
};