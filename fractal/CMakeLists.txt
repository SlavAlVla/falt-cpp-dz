cmake_minimum_required(VERSION 3.20)

# cmake_path(SET LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../lib")
set(TARGET "fractal")
set(HEADERS
    src/gui/MainWindow/MainWindow.h
    src/gui/UIGroup/UIGroup.h
    src/gui/UIGroupManager/UIGroupManager.h
    src/gui/UIButton/UIButton.h
    src/gui/constants/constants.h
)
set(SOURCES
    src/main.cpp
    src/gui/UIGroup/UIGroup.cpp
    src/gui/UIGroupManager/UIGroupManager.cpp
    src/gui/UIButton/UIButton.cpp
)
project(${TARGET} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)

# include_directories(${LIB_DIR})
include_directories(SYSTEM ${FLTK_INCLUDE_DIR})

add_executable(${TARGET} ${HEADERS} ${SOURCES})

target_include_directories(${TARGET} PRIVATE src/gui)
target_link_libraries(${TARGET} ${FLTK_LIBRARIES} ${OPENGL_LIBRARIES})

install(TARGETS ${TARGET})