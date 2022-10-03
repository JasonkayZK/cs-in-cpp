cmake_minimum_required(VERSION 3.16)
project(cs-in-cpp)

# Os check
if (CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif (CMAKE_HOST_APPLE)
    set(MACOS 1)
elseif (CMAKE_HOST_UNIX)
    set(LINUX 1)
endif ()

set(CMAKE_CXX_STANDARD 20)

# Placeholder
aux_source_directory(./src DIR_SRCS)

## Algorithm
add_subdirectory(${PROJECT_SOURCE_DIR}/src/algorithm)
include_directories(${PROJECT_SOURCE_DIR}/src/algorithm)

## DataStructure
add_subdirectory(${PROJECT_SOURCE_DIR}/src/data-structure)
include_directories(${PROJECT_SOURCE_DIR}/src/data-structure)

## Algorithm Test Cases
add_subdirectory(${PROJECT_SOURCE_DIR}/src/algorithm-test)

## DataStructure Test Cases
add_subdirectory(${PROJECT_SOURCE_DIR}/src/data-structure-test)
