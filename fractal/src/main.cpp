#include "gui/MainWindow/MainWindow.h"
#include <FL/Fl.H>

int main (int argc, char* argv[]) {
    Fl_Window* win = new MainWindow{};
    win->show();

    return Fl::run();
}