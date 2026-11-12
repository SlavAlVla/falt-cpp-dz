#include "UIButton.h"

void UIButton::fltk_callback (Fl_Widget* wid, void* data) {
    UIButton* btn = reinterpret_cast<UIButton*>(data);
    if (btn)
        btn->on_click();
}

void SwitchGroupButton::on_click () { manager_->switch_group(gr_); }