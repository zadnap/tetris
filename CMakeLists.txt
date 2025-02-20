cmake_minimum_required(VERSION 3.31.5)
project(tetris VERSION 0.1.0 LANGUAGES C CXX)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")

find_package(raylib CONFIG REQUIRED)
file(GLOB SOURCES "src/*.cpp")
add_executable(tetris ${SOURCES})

target_link_libraries(tetris PRIVATE raylib)

