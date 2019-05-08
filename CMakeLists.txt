cmake_minimum_required(VERSION 3.0)

project(kalkulator)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")


file(GLOB_RECURSE SOURCE_FILES "ONP/*.cpp")
file(GLOB_RECURSE HEADER_FILES "ONP /*.h")

set (INCLUDE_DIRS "")
foreach(_headerFile ${HEADER_FILES})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

add_executable(kalkulator ${SOURCE_FILES})

target_include_directories(kalkulator PRIVATE ${INCLUDE_DIRS})
