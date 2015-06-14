project(libcontainers)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

add_library(containers STATIC
    src/vector.c
    include/vector.h

    src/hashmap.c
    include/hashmap.h

    include/common.h
)


add_executable(libcontainers_tests
    tests/main.c)

target_link_libraries(libcontainers_tests containers)
