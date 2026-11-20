#pragma once

namespace settings {

struct Window {
    static constexpr int width = 800;
    static constexpr int height = 800;
};

struct Fractal {
    static constexpr int max_iterations = 100;
    static constexpr double escape_radius = 2.0;
    static constexpr double max_iter_koeff1 = 100.0;
    static constexpr double max_iter_koeff2 = 40.0;
    static constexpr double max_iter_koeff3 = 0.005;
};

struct View {
    static constexpr double mouse_sensitivity = 3;

    static constexpr double center_x = 0.0;
    static constexpr double center_y = 0.0;
    static constexpr double scale = 0.005;

    // static constexpr double center_x = -0.7436432;
    // static constexpr double center_y = 0.1318262;
    // static constexpr double scale = 0.00000002;

    // static constexpr double center_x = 0.0016437219711531;
    // static constexpr double center_y = 0.822467633298876;
    // static constexpr double scale = 0.00000000000003;
};

struct Button {
    static constexpr int width = 100;
    static constexpr int height = 24;
    static constexpr int padding = 10;
    static constexpr int margin = 20;
};

}  // namespace settings
