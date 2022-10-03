//
// Created by Jasonkay on 2022/10/3.
//

/**
 * FISHER YATES'S SHUFFLE
 *
 * Features:
 * 1. shuffle list in O(n) time.
 *
 * http://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
 */
#ifndef CS_IN_CPP_SRC_ALGORITHM_SHUFFLE_HPP_
#define CS_IN_CPP_SRC_ALGORITHM_SHUFFLE_HPP_

#include <random>

namespace algorithm {

class Shuffle {

 public:

  /**
   * shuffle the 'list' of length 'len'
   */
  template<typename T>
  static void shuffle(T *list, int len) {
    std::mt19937 rng(std::random_device{}());

    int i = len, j;
    T temp;

    if (i == 0) return;
    while (--i) {
      j = int(rng() % (i + 1));
      temp = list[i];
      list[i] = list[j];
      list[j] = temp;
    }
  }

};

} // algorithm

#endif //CS_IN_CPP_SRC_ALGORITHM_SHUFFLE_HPP_
