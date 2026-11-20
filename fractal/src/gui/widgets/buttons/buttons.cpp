#include "buttons.h"
#include "../groups/groups.h"

SwitchGroupButton::SwitchGroupButton (int x, int y, int width, int height,
                                      const char* label,
                                      UIGroupManager& manager,
                                      char group_id)
    : UIButton(x, y, width, height, label), manager_(manager),
      group_id_(group_id) {}

void SwitchGroupButton::on_click () { manager_.switch_group(group_id_); }

UpdateGroupButton::UpdateGroupButton (int x, int y, int width, int height,
                                      const char* label,
                                      FractalGroup& group)
    : UIButton(x, y, width, height, label), group_(group) {}

void UpdateGroupButton::on_click () { group_.update(); }

ZoomButton::ZoomButton (int x, int y, int width, int height,
                        const char* label, FractalGroup& group,
                        double zoom_scale)
    : UpdateGroupButton{x, y, width, height, label, group} {
    zoom_scale_ = zoom_scale;
}

void ZoomButton::on_click () { group_.zoom(zoom_scale_); }