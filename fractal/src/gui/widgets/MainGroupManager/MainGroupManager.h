#pragma once

#include "../../UI/UIGroupManager/UIGroupManager.h"

class Fl_Window;

class MainGroupManager : public UIGroupManager {
public:
    explicit MainGroupManager(Fl_Window& window);
};
