#include "UIGroup.h"
#include "constants/constants.h"

MenuGroup::MenuGroup (int w, int h, UIGroupManager* manager, int x, int y)
    : UIGroup(w, h, manager, x, y) {
    to_fractal_btn = new SwitchGroupButton{
        BtnSettings::BTN_W, BtnSettings::BTN_H,
        BtnSettings::TO_FRACTAL_NAME, manager, GroupType::FRACTAL};
    this->end();
}

FractalGroup::FractalGroup (int w, int h, UIGroupManager* manager, int x,
                            int y)
    : UIGroup(w, h, manager, x, y) {
    to_menu_btn = new SwitchGroupButton{
        BtnSettings::BTN_W, BtnSettings::BTN_H, BtnSettings::TO_MENU_NAME,
        manager, GroupType::MENU};
    this->end();
}