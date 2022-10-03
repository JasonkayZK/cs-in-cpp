## Algorithm
add_definitions("-Wall")

add_executable(shuffle_test shuffle_test.cc)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(shuffle_test
        PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main
        Algorithm)
