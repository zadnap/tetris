cmake_minimum_required(VERSION 3.31.5)
project(tetris VERSION 0.1.0 LANGUAGES C CXX)

enable_testing()
include(CTest)

include_directories(include)

find_package(raylib CONFIG REQUIRED)
file(GLOB SOURCES "src/*.cpp")
add_executable(tetris_main ${SOURCES})
target_link_libraries(tetris_main PRIVATE raylib)

add_subdirectory(tests)