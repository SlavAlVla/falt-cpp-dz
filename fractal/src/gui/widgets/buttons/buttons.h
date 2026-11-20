#pragma once

#include "../../UI/UIButton/UIButton.h"
#include "../../UI/UIGroupManager/UIGroupManager.h"

class FractalGroup;

class SwitchGroupButton : public UIButton {
  public:
    SwitchGroupButton (int x, int y, int width, int height,
                       const char* label, UIGroupManager& manager,
                       char group_id);

  protected:
    void on_click () override;

  private:
    UIGroupManager& manager_;
    char group_id_;
};

class UpdateGroupButton : public UIButton {
  public:
    UpdateGroupButton (int x, int y, int width, int height,
                       const char* label, FractalGroup& group);

  protected:
    void on_click () override;
    FractalGroup& group_;
};

class ZoomButton : public UpdateGroupButton {
  public:
    ZoomButton (int x, int y, int width, int height, const char* label,
                FractalGroup& group, double zoom_scale);

  protected:
    double zoom_scale_;
    void on_click () override;
};