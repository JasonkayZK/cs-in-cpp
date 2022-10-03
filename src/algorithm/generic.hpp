//
// Created by Jasonkay on 2022/10/3.
//

/**
 *
 * GENERIC METHODS FOR ALGORITHMS
 *
 */

#ifndef CS_IN_CPP_SRC_ALGORITHM_GENERIC_HPP_
#define CS_IN_CPP_SRC_ALGORITHM_GENERIC_HPP_

#include <iostream>

#define RANDOM_INIT()    srand(time(NULL))
#define RANDOM(L, R)    (L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

namespace algorithm {

/**
 * swap 2-element, original value
 */
template<typename T>
static inline void swap(T &x, T &y) {
  T _t(x);
  x = y;
  y = _t;
}

/**
 * print all of the elements in `list` with size `n`
 */
template<typename T>
static void print_list(T &list, int count) {
  int i;
  for (i = 0; i < count; i++)
    printf("%d\t ", list[i]);
  printf("\n");
}

/**
 * pass in array with *len
 * return new length
 */
template<typename T>
static uint32_t remove_dup(T a[], uint32_t len) {
  uint32_t i;
  uint32_t new_len = len;
  for (i = 0; i < new_len; i++) {
    T key = a[i];
    uint32_t j;
    for (j = i + 1; j < new_len; j++) {
      if (key == a[j]) {
        /* found dup, move left one position. */
        uint32_t k;
        for (k = j; k < new_len - 1; k++) {
          a[k] = a[k + 1];
        }
        --new_len;
      }
    }
  }

  return new_len;
}

} // algorithm

#endif //CS_IN_CPP_SRC_ALGORITHM_GENERIC_HPP_
