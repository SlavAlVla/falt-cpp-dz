cmake_minimum_required(VERSION 3.20)

set(TARGET "fractal")
# set(HEADERS
#     src/config/constants.h
#     src/gui/widgets/MainWindow/MainWindow.h
#     src/gui/widgets/MainGroupManager/MainGroupManager.h
#     src/gui/widgets/PixelCanvas/PixelCanvas.h
#     src/gui/widgets/buttons/buttons.h
#     src/gui/widgets/groups/groups.h
#     src/maths/Colorizer/Colorizer.h
#     src/maths/Mandelbrot/Mandelbrot.h
#     src/maths/Renderer/Renderer.h
#     src/controller/FractalController.h
# )
set(SOURCES
    src/main.cpp
    src/core/Complex.cpp
    src/core/Mandelbrot.cpp
    src/rendering/Colorizer.cpp
    src/rendering/Renderer.cpp
    src/rendering/ImageBuffer.cpp
    src/rendering/Viewport.cpp
    src/controller/FractalController.cpp
    src/gui/UI/UIButton/UIButton.cpp
    src/gui/UI/UIGroupManager/UIGroupManager.cpp
    src/gui/widgets/MainWindow/MainWindow.cpp
    src/gui/widgets/MainGroupManager/MainGroupManager.cpp
    src/gui/widgets/PixelCanvas/PixelCanvas.cpp
    src/gui/widgets/buttons/buttons.cpp
    src/gui/widgets/groups/groups.cpp
)
project(${TARGET} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/gui/UI)

find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(SYSTEM ${FLTK_INCLUDE_DIR})

add_executable(${TARGET} ${HEADERS} ${SOURCES})

target_include_directories(${TARGET} PRIVATE src)
target_link_libraries(${TARGET} UI)
target_link_libraries(${TARGET} ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})

install(TARGETS ${TARGET})