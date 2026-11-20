#include "UIGroupManager.h"

#include <stdexcept>

void UIGroupManager::add_group (char id, Fl_Group* group) {
    if (!group) {
        throw std::invalid_argument("Group cannot be null");
    }
    groups_[id] = group;
}

void UIGroupManager::switch_group (char id) {
    const auto found = groups_.find(id);
    if (found == groups_.end()) {
        return;
    }

    if (current_group_) {
        current_group_->hide();
    }

    current_group_ = found->second;
    current_group_->show();
}
