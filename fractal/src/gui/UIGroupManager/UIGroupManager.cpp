#include "UIGroupManager.h"
#include "UIGroup/UIGroup.h"
#include "constants/constants.h"
#include <iostream>

void UIGroupManager::switch_group (const GroupType& gr) {
    if (curr_group)
        curr_group->hide();

    if (groups.count(gr)) {
        curr_group = groups[gr];
        curr_group->show();
    }
}

MainGroupManager::MainGroupManager () {
    groups[GroupType::MENU] =
        new MenuGroup(WinSettings::WIN_W, WinSettings::WIN_H, this);
    groups[GroupType::FRACTAL] =
        new FractalGroup(WinSettings::WIN_W, WinSettings::WIN_H, this);
    for (auto& [name, gr] : groups) {
        gr->hide();
    }
    curr_group = groups[GroupType::DEFAULT];
    curr_group->show();
}