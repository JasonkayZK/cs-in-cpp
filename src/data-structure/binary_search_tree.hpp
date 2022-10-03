//
// Created by Jasonkay on 2022/10/3.
//
/**
 * BINARY SEARCH TREE
 *
 * Features:
 * 1. Expected search time is O(log(n)), with worst case O(n).
 * 2. Data should be !!!SHUFFLED!!! first before tree creation.
 * 3. First initialize the value of the root (pointer to the
 *    structure treeNode) with NULL. eg:
 *    treeNode *root = NULL
 *
 * http://en.wikipedia.org/wiki/Binary_search_tree
 */

#ifndef CS_IN_CPP_SRC_DATA_STRUCTURE_BINARY_SEARCH_TREE_HPP_
#define CS_IN_CPP_SRC_DATA_STRUCTURE_BINARY_SEARCH_TREE_HPP_

#include <iostream>
#include <exception>

namespace data_structure {

template<typename K, typename V>
class BinarySearchTree {

 private:

  struct treeNode;

 public:

  BinarySearchTree() : m_root(nullptr), len(0) {};

  BinarySearchTree(const BinarySearchTree &) = delete;

  BinarySearchTree &operator=(const BinarySearchTree &) = delete;

  ~BinarySearchTree() {
    this->_destruct(m_root);
  }

  [[nodiscard]] long long int get_len() const {
    return len;
  }

  /**
   * find key
   */
  treeNode *find(const K &key) {
    treeNode *n = m_root;
    while (n != nullptr && key != n->key) {
      if (key < n->key) {
        n = n->left;
      } else {
        n = n->right;
      }
    }

    return n;
  }

  /**
   * insert a new data into the binary search tree.
   */
  void insert(const K &key, const V &value) {
    auto *item = new treeNode(key, value);

    // Find the node
    treeNode *n = m_root;
    treeNode *y;
    while (n != nullptr) {
      y = n;
      if (key < n->key) {
        n = n->left;
      } else {
        n = n->right;
      }
    }

    // Insert node
    item->parent = y;
    if (y == nullptr) {
      m_root = item;
    } else if (key < y->key) {
      y->left = item;
    } else {
      y->right = item;
    }

    ++len;
  }

  /**
   * delete a key from the binary search tree.
   */
  bool delete_key(const K &key) {
    treeNode *z = find(key);
    if (z == nullptr) {
      return false;
    }

    if (z->left == nullptr) {
      _transplant(z, z->right);
    } else if (z->right == nullptr) {
      _transplant(z, z->left);
    } else {
      // find the minimum element of the right subtree
      treeNode *y = minimum(z->right);
      if (y->parent != z) {
        // replace y with right-child
        _transplant(y, y->right);
        // replace right-child of y with the right-child of z
        y->right = z->right;
        // make y the parent of the right-child
        y->right->parent = y;
      }

      // replace z with y
      _transplant(z, y);
      y->left = z->left;
      y->left->parent = y;
    }

    delete z;
    --len;

    return true;
  }

  /**
   * find the minimum element of the subtree
   */
  treeNode *minimum(treeNode *x) {
    if (x == nullptr)return nullptr;

    while (x->left != nullptr) {
      x = x->left;
    }
    return x;
  }

  void print_tree(int indent = 0) {
    this->_print_tree(m_root, indent);
  }

 private:

  /**
   * binary search tree definition.
   */
  struct treeNode {
    K key; // key
    V value; // data
    treeNode *parent; // parent
    treeNode *left; // left child
    treeNode *right; // right child

    treeNode(K key, V value)
        : key(key), value(value), parent(nullptr), left(nullptr), right(nullptr) {}
  };

  class BSTException : public std::exception {
   public:
    [[nodiscard]] const char *what() const noexcept override {
      return "key does not exist";
    }
  } not_found_exception;

  /**
   * the root
   */
  treeNode *m_root;

  long long len;

 private:

  void _destruct(treeNode *n) {
    if (n == nullptr) return;
    _destruct(n->left);
    _destruct(n->right);
    delete n;
  }

  void _print_tree(treeNode *n, int indent) {
    if (n == nullptr) return;
    _print_tree(n->right, indent + 1);
    std::string indent_str = indent <= 0 ? "" : std::string(indent, ' ');
    std::cout << indent_str << "[" << n->key << "," << n->value << "]" << std::endl;
    _print_tree(n->left, indent + 1);
  }

  /**
   * replace node u with v.
   */
  void _transplant(treeNode *u, treeNode *v) {
    if (u->parent == nullptr) {
      m_root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }

    if (v != nullptr) {
      v->parent = u->parent;
    }
  }

};

} // data_structure

#endif //CS_IN_CPP_SRC_DATA_STRUCTURE_BINARY_SEARCH_TREE_HPP_
