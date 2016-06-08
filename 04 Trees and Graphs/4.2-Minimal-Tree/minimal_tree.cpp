#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <memory>
#include "tree.h"

/* Goal: Write an algorithm to construct a binary search tree with minimal
   height from a list of integers.

   What is true about a binary tree with minimal height? It must be 
   balanced. If the tree is balanced, then the root of the binary search
   tree is the median element. Since the list we are given is already sorted,
   we can find the median easily in constant time. Now that we have the
   root, we need to construct the left and the right subtrees. These are
   just smaller instances of the same problem! We wish to construct minimal
   binary search trees for the first and the second half of the list which
   we can easily do using recursion. Recursively, we can think about it like
   this:

   Suppose we already know how to make a BST of minimal height for the first
   and second half of the list. To make a minimal BST for the whole list,
   we just join the BSTs for each half at the median.

   The runtime of this algorithm will be O(n).
*/


template <class Iterator>
std::shared_ptr<Tree::BinaryNode> makeTree(Iterator begin, Iterator end) {
  /* If there are no elements, the tree is empty */
  if (begin >= end) return nullptr;
  /* Compute the median and make it the root node */
  auto mid = begin + (end - begin) / 2;
  std::shared_ptr<Tree::BinaryNode> root = std::make_shared<Tree::BinaryNode>(*mid);
  /* Recursively build the left and the right subtrees */
  root->left = makeTree(begin, mid);
  root->right = makeTree(mid+1, end);
  return root;
}

std::shared_ptr<Tree::BinaryNode> makeTree(std::vector<int> vals) {
  return makeTree(vals.begin(), vals.end());
}

std::vector<int> readList(std::istream& in) {
  std::string line;
  getline(in, line);
  std::stringstream ss(line);
  int x;
  std::vector<int> vals;
  while (ss >> x) vals.push_back(x);
  return vals;
}

int main() {
  std::cout << "Enter a list of integers:" << std::endl;
  std::vector<int> vals = readList(std::cin);
  std::sort(vals.begin(), vals.end());
  std::shared_ptr<Tree::BinaryNode> tree = makeTree(vals);
  std::cout << "Inorder printing of tree: " << std::endl;
  inorderPrint(tree);
  std::cout << std::endl;
  return 0;
}
