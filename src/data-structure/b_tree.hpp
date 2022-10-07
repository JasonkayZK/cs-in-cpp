//
// Created by Jasonkay on 2022/10/4.
//

/**
 * B-TREE
 *
 * In computer science, a B-tree is a tree data structure that keeps data sorted
 * and allows searches, sequential access, insertions, and deletions in
 * logarithmic time. The B-tree is a generalization of a binary search tree in
 * that a node can have more than two children. (Comer 1979, p. 123) Unlike
 * self-balancing binary search trees, the B-tree is optimized for systems that
 * read and write large blocks of data. It is commonly used in databases and
 * filesystems.
 *
 * NOTES ON PRACTICAL USAGE:
 *   1. Implement a buffer manager for B-Tree, such as using Hash<idx, node> and
 * LRU, to control which node is in memory, and of course O_DIRECT flag.
 *   2. Extend the node struct with satellite data pointer(offset), enlarge the
 * node size to 2*PAGE or even more.
 *
 * http://en.wikipedia.org/wiki/B-tree
 */

#ifndef CS_IN_CPP_SRC_DATA_STRUCTURE_B_TREE_HPP_
#define CS_IN_CPP_SRC_DATA_STRUCTURE_B_TREE_HPP_

#include <cstdio>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <memory>

#define BLOCK_SIZE    4096
#define T            255
#define LEAF        0x0001
#define ON_DISK        0x0002
#define MARK_FREE    0x0004

namespace data_structure {

class BTree {

};

} // data_structure

#endif //CS_IN_CPP_SRC_DATA_STRUCTURE_B_TREE_HPP_
