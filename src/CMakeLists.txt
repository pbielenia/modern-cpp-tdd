cmake_minimum_required(VERSION 3.13)

set(target_name ${PROJECT_NAME}-src)
set(sources
    src/Soundex.cpp
)

message(${CMAKE_CURRENT_SOURCE_DIR})

add_library(${target_name} ${sources})
target_compile_features(${target_name} PUBLIC cxx_std_17)
target_include_directories(${target_name}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
