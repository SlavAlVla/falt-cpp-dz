add_library(UI STATIC
    UIGroupManager/UIGroupManager.h
    UIButton/UIButton.h
    UIGroupManager/UIGroupManager.cpp
    UIButton/UIButton.cpp
)

find_package(FLTK REQUIRED)

include_directories(SYSTEM ${FLTK_INCLUDE_DIR})

target_include_directories(UI PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)