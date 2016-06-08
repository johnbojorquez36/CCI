#include "tree.h"
#include <iostream>
#include <algorithm>
#include <cmath>

/* Goal: implement a an algorithm which checks if a binary tree is balanced.

   We have three conditions we need to check for any tree:
   1. The heights of the two subtrees differ by no more than 1
   2. The left subtree is balanced.
   3. The right subtree is balanced.

   Suppose we can determine whether or not the left and right subtrees are
   balanced. This leaves us with just the work of determining the height
   of the left and right subtrees. If we have to calculate the height of
   the left and right subtrees at each node, this will bring our total
   runtime to O(n^2). We can probably do better. What if we could calculate
   the height while we recursively determine if the left and right subtree
   are balanced? Since the function returns a boolean and not the height,
   we need to add an extra parameter as a reference to an int. This would
   bring the runtime down to O(n). Let's try it out.
*/

bool isBalanced(std::shared_ptr<Tree::BinaryNode> root, int& height) {
  if (!root) {
    height = 0;
    return true;
  }
  bool leftBalanced = isBalanced(root->left, height);
  int leftHeight = height;
  bool rightBalanced = isBalanced(root->right, height);
  int rightHeight = height;
  height = std::max(leftHeight+1, rightHeight+1);
  return (leftBalanced && rightBalanced &&
	  std::abs(leftHeight - rightHeight) < 2);
}

bool isBalanced(std::shared_ptr<Tree::BinaryNode> root) {
  int height = 0;
  return isBalanced(root, height);
}

int main() {
  std::cout << "Enter the array representation of a binary tree "
	    << "(ex. 1 3 4 null 8): "
	    << std::endl;
  std::shared_ptr<Tree::BinaryNode> root = Tree::read(std::cin);
  std::cout << "The tree " << (isBalanced(root) ? "is" : "is not")
	    << " balanced." << std::endl;
  return 0;
}
