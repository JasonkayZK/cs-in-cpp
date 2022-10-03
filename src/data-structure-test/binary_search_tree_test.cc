//
// Created by Jasonkay on 2022/10/3.
//

#include "../data-structure/binary_search_tree.hpp"
#include "gtest/gtest.h"
#include <random>

namespace data_structure_test {

TEST(BinarySearchTreeTest, BinarySearchTreeDemo) {
  const int MAX_ELEMENTS = 30;
  int key[MAX_ELEMENTS];
  int value[MAX_ELEMENTS];

  data_structure::BinarySearchTree<int, int> t;

  // generate random numbers and fill them to the list
  int i;
  std::mt19937 rng(std::random_device{}());
  for (i = 0; i < MAX_ELEMENTS; i++) {
    key[i] = int(rng()) % 100;
    value[i] = int(rng()) % 1000;
  }

  for (i = 0; i < MAX_ELEMENTS; i++) {
    printf("insert %d->%d\n", key[i], value[i]);
    t.insert(key[i], value[i]);
  }
  ASSERT_EQ(MAX_ELEMENTS, t.get_len());

  t.print_tree();

  for (i = 0; i < MAX_ELEMENTS; i++) {
    auto item = t.find(key[i])->value;
    printf("getting %d->%d\n", key[i], item);
  }

  for (i = 0; i < MAX_ELEMENTS; i++) {
    t.delete_key(key[i]);
    t.print_tree();
    printf("deleted %d\n\n", key[i]);
    ASSERT_EQ(MAX_ELEMENTS - i - 1, t.get_len());
  }

  ASSERT_EQ(0, t.get_len());
}

} // data_structure

int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
