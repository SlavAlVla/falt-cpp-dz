#pragma once

struct WinSettings {
    static constexpr unsigned WIN_W = 800;
    static constexpr unsigned WIN_H = 600;
};

enum class GroupType { MENU, FRACTAL, DEFAULT = MENU };

struct BtnSettings {
    static constexpr unsigned BTN_W = 100;
    static constexpr unsigned BTN_H = 20;
    static constexpr const char* TO_MENU_NAME = "To menu";
    static constexpr const char* TO_FRACTAL_NAME = "To fractal";
};