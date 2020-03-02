cmake_minimum_required(VERSION 3.13)
project(soundex)

add_subdirectory(libs/googletest)
add_subdirectory(src)
add_subdirectory(tests)

enable_testing()

set_target_properties(unit_tests
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
