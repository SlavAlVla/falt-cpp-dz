#pragma once

#include <FL/Fl_Window.H>
#include <memory>

class MainGroupManager;

class MainWindow : public Fl_Window {
public:
    MainWindow();
    ~MainWindow() override;

private:
    std::unique_ptr<MainGroupManager> manager_;
};
