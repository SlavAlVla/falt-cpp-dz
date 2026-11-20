#pragma once

#include <FL/Fl_Button.H>

class UIButton : public Fl_Button {
public:
    UIButton(int x, int y, int width, int height, const char* label);
    ~UIButton() override = default;

protected:
    virtual void on_click() = 0;

private:
    static void callback_handler(Fl_Widget* widget, void* data);
};
