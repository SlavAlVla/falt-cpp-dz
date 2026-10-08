cmake_minimum_required(VERSION 3.15)
project(MyProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Автоматически ищем все .cpp и .hpp файлы внутри папки source
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "source/*.cpp" "source/*.hpp")

add_executable(my_app ${SRC_FILES})

# Подключаем заголовочные файлы из родительского каталога библиотеки
target_include_directories(my_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)