#include "tree.h"
#include <iostream>

/* Goal: Implement an algorithm to check if a tree is a subtree of another.
   
   The most intuitive approach here is recursive. For each node in T1, if 
   the node's value is equal to the root's value of T2, examine that subtree
   to see if it's the same. It may seem that this runtime could be quadratic,
   but it turns out that on average, it's actually much better.
*/

typedef std::shared_ptr<Tree::BinaryNode> PBNode;

/* Checks if two binary trees are equal */
bool isEqual(PBNode T1,  PBNode T2) {
  if (!T1 && !T2) return true;
  if (!T1 || !T2) return false;
  return T1->val == T2->val && isEqual(T1->left, T2->left)
    && isEqual(T1->right, T2->right);
}

/* Checks if T2 is a subtree of T1 */
bool isSubtree(PBNode T1, PBNode T2) {
  if (!T2) return true;
  if (!T1) return false;
  return (T1->val == T2->val && isEqual(T1, T2)) ||
    isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

int main() {
  std::cout << "Enter the array representation of a binary tree for T1 "
	    << "(ex. 1 3 4 null 8): "
	    << std::endl;
  std::shared_ptr<Tree::BinaryNode> T1 = Tree::read(std::cin);
  std::cout << "Enter the array representation of a binary tree for T2 "
	    << "(ex. 1 3 4 null 8): "
	    << std::endl;
  std::shared_ptr<Tree::BinaryNode> T2 = Tree::read(std::cin);
  std::cout << "T2 " << (isSubtree(T1, T2) ? "is" : "is not")
	    << " a subtree of T1." << std::endl;
  return 0;
}
