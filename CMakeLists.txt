cmake_minimum_required(VERSION 3.31.5)
project(tetris VERSION 1.0.1 LANGUAGES C CXX)

include(CPack)
enable_testing()
include(CTest)

set(CPACK_PACKAGE_NAME "Tetris")
set(CPACK_PACKAGE_CONTACT "nguyenbahoangminh06@gmail.com")
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_DIRECTORY "${CPACK_PACKAGE_DIRECTORY}")

include_directories(include)

find_package(raylib CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
file(GLOB SOURCES "src/*.cpp")
add_executable(tetris_main ${SOURCES})
target_link_libraries(tetris_main PRIVATE raylib glfw winmm)

add_subdirectory(tests)

install(TARGETS tetris_main DESTINATION .)
install(DIRECTORY assets/audio/ DESTINATION assets/audio)