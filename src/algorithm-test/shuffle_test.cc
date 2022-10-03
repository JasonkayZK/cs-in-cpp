//
// Created by Jasonkay on 2022/10/3.
//

#include "../algorithm/shuffle.hpp"
#include "../algorithm/generic.hpp"
#include "gtest/gtest.h"

namespace data_structure_test {

TEST(ShuffleTest, ShuffleDemo) {
  const int MAX_ELEMENTS = 10;
  int list[MAX_ELEMENTS];

  // generate random numbers and fill them to the list
  for (int i = 0; i < MAX_ELEMENTS; i++) {
    list[i] = i;
  }
  printf("The list before Shuffle is:\n");
  algorithm::print_list(list, MAX_ELEMENTS);

  // shuffle the list
  algorithm::Shuffle::shuffle<int>(list, MAX_ELEMENTS);

  // print the result
  printf("The list after using Yates' shuffle algorithm:\n");
  algorithm::print_list(list, MAX_ELEMENTS);

  SUCCEED();
}

} // data_structure

int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
