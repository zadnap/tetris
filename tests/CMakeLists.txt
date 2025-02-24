find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(grid_test 
    grid_test.cpp 
    ${CMAKE_SOURCE_DIR}/src/grid.cpp
)
target_link_libraries(grid_test PRIVATE GTest::gtest_main)
gtest_discover_tests(grid_test)

add_executable(tetromino_test 
    tetromino_test.cpp 
    ${CMAKE_SOURCE_DIR}/src/tetrominoes.cpp 
    ${CMAKE_SOURCE_DIR}/src/tetromino.cpp 
    ${CMAKE_SOURCE_DIR}/src/position.cpp
)
target_link_libraries(tetromino_test PRIVATE GTest::gtest_main)
gtest_discover_tests(tetromino_test)