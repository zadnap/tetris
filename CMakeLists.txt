cmake_minimum_required(VERSION 3.31.5)
project(tetris VERSION 0.1.0 LANGUAGES C CXX)

find_package(raylib CONFIG REQUIRED)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(tetris_main ${SOURCES})

target_link_libraries(tetris_main PRIVATE raylib)