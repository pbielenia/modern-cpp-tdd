cmake_minimum_required(VERSION 3.13)

set(sources
    main.cpp
    src/SoundexTest.cpp
)

add_executable(unit_tests ${sources})
set_target_properties(unit_tests
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
target_link_libraries(unit_tests
    PUBLIC
        gtest
        gmock
        ${PROJECT_NAME}-src
)

add_test(unit_tests unit_tests)

add_custom_command(
     TARGET unit_tests
     COMMENT "Run tests"
     POST_BUILD 
     COMMAND ${CMAKE_BINARY_DIR}/unit_tests
)
