cmake_minimum_required(VERSION 3.20)

set(TARGET "bool_calculator")

cmake_path(SET LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../lib")

set(SOURCES
    bool_calculator.cpp
)

project(${TARGET} CXX)

add_executable(${TARGET} ${SOURCES})

target_include_directories(${TARGET} PRIVATE ${LIB_DIR})

install(TARGETS ${TARGET})
