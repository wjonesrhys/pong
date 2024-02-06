cmake_minimum_required(VERSION 3.16)
project(sfml_test)

include_directories(
        ${PROJECT_SOURCE_DIR}/headers
        ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/includes/*.h"
    "${PROJECT_SOURCE_DIR}/includes/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.c"
    "${PROJECT_SOURCE_DIR}/main.cpp"
)

add_executable(main ${all_SRCS})

target_link_libraries(main PRIVATE sfml-graphics)
target_link_libraries(main PRIVATE sfml-window)
target_link_libraries(main PRIVATE sfml-system)
target_compile_features(main PRIVATE cxx_std_17)