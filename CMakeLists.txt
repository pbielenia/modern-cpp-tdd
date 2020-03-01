cmake_minimum_required(VERSION 3.13)
project(soundex)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

set_target_properties(unit_tests
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
