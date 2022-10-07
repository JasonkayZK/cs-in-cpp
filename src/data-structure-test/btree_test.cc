//
// Created by Jasonkay on 2022/10/3.
//

#include "../data-structure/b_tree.hpp"
#include "gtest/gtest.h"
#include <random>

namespace data_structure_test {

TEST(BTreeTest, BTreeDemo) {

}

} // data_structure

int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
