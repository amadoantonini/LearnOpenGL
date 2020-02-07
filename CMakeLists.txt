cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)

project(learn_opengl)

configure_file("Config.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/include/Config.h")

include_directories(include)

add_subdirectory(src)
