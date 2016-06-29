#include "tree.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

/* Goal: implement a an algorithm which checks if a binary tree is a
   valid binary search tree.

   A BST must hold the following properties:
   1. The left subtree is a valid BST.
   2. The right subtree is a valid BST.
   3. All values in the left subtree are less than the root.
   4. All values in the right subtree are greater than the root.
   
   The tricky part is figuring out that every node in either
   the left or right subtree is within some limit. This will
   require us to pass the limits as extra parameters with each
   recursive call.
*/

bool isValidBST(std::shared_ptr<Tree::BinaryNode> root, int min, int max) {
  if (!root) return true;
  return isValidBST(root->left, min, root->val) &&
    isValidBST(root->right, root->val, max) &&
    root->val > min && root->val < max;
}

bool isValidBST(std::shared_ptr<Tree::BinaryNode> root) {
  return isValidBST(root, INT_MIN, INT_MAX);
}

int main() {
  std::cout << "Enter the array representation of a binary tree "
	    << "(ex. 1 3 4 null 8): "
	    << std::endl;
  std::shared_ptr<Tree::BinaryNode> root = Tree::read(std::cin);
  std::cout << "The tree " << (isValidBST(root) ? "is" : "is not")
	    << " a valid BST." << std::endl;
  return 0;
}
