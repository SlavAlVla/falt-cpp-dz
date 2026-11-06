cmake_minimum_required(VERSION 3.20)

set(TARGET "bool_calculator")

cmake_path(SET LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../lib")

set(HEADERS
    src/Calculator/Calculator.h
    src/constants/constants.h
    src/Statement/Statement.h
    src/Token/Token.h
    src/Variable/Variable.h
)

set(SOURCES
    src/main.cpp
    src/Calculator/Calculator.cpp
    src/Statement/Statement.cpp
    src/Token/Token.cpp
    src/Variable/Variable.cpp
)

project(${TARGET} CXX)

add_executable(${TARGET} ${HEADERS} ${SOURCES})

target_include_directories(${TARGET} PRIVATE ${LIB_DIR})
target_include_directories(${TARGET} PRIVATE src)

install(TARGETS ${TARGET})
