find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(board_test 
    board_test.cpp 
    ${CMAKE_SOURCE_DIR}/src/board.cpp
)
target_link_libraries(board_test PRIVATE GTest::gtest_main)
gtest_discover_tests(board_test)

add_executable(tetromino_test 
    tetromino_test.cpp 
    ${CMAKE_SOURCE_DIR}/src/tetrominoes.cpp 
    ${CMAKE_SOURCE_DIR}/src/tetromino.cpp 
    ${CMAKE_SOURCE_DIR}/src/position.cpp
)
target_link_libraries(tetromino_test PRIVATE GTest::gtest_main)
gtest_discover_tests(tetromino_test)