find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

macro(add_gtest_executable test_module)
    add_executable(${test_module}_test ${test_module}_test.cpp ${CMAKE_SOURCE_DIR}/src/${test_module}.cpp)
    target_link_libraries(${test_module}_test PRIVATE GTest::gtest_main)
    gtest_discover_tests(${test_module}_test)
endmacro()

add_gtest_executable(grid)