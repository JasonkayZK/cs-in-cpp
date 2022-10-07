add_executable(binary_search_tree_test ./binary_search_tree_test.cc)
add_executable(btree_test btree_test.cc)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(binary_search_tree_test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
target_link_libraries(btree_test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
