cmake_minimum_required(VERSION 3.13)

find_package(GTest)

set(sources
    src/SoundexTest.cpp
)

add_executable(unit_tests ${sources})
set_target_properties(unit_tests
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
target_link_libraries(unit_tests
    PUBLIC
        GTest::GTest
        GTest::Main
        ${PROJECT_NAME}-src
)

add_test(unit_tests unit_tests)

add_custom_command(
     TARGET unit_tests
     COMMENT "Run tests"
     POST_BUILD 
     COMMAND ${CMAKE_BINARY_DIR}/unit_tests
)
