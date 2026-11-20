#pragma once

#include <FL/Fl_Group.H>
#include <map>

class UIGroupManager {
public:
    virtual ~UIGroupManager() = default;

    void add_group(char id, Fl_Group* group);
    void switch_group(char id);

protected:
    std::map<char, Fl_Group*> groups_;
    Fl_Group* current_group_ = nullptr;
};
