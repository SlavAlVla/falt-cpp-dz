#pragma once
#include "constants/constants.h"
#include <map>

class UIGroup;

class UIGroupManager {
  protected:
    std::map<GroupType, UIGroup*> groups;
    UIGroup* curr_group = nullptr;

  public:
    virtual void switch_group (const GroupType& gr);

    virtual ~UIGroupManager () = default;
};

class MainGroupManager : public UIGroupManager {
  public:
    MainGroupManager ();
};