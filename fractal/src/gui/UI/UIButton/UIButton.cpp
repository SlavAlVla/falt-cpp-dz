#include "UIButton.h"

UIButton::UIButton(int x, int y, int width, int height, const char* label)
    : Fl_Button(x, y, width, height, label) {
    callback(callback_handler, this);
}

void UIButton::callback_handler(Fl_Widget*, void* data) {
    auto* button = static_cast<UIButton*>(data);
    if (button) {
        button->on_click();
    }
}
