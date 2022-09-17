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
add_executable(main ${DIR_SRCS})

# Libraries
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target/libs)

## Algorithm
add_subdirectory(src/algorithm)

## DataStructure
add_subdirectory(src/data-structure)

# Additional libraries from vcpkg
find_package(GTest CONFIG REQUIRED)
target_link_libraries(main PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
