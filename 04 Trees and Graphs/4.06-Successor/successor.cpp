#include "tree.h"
#include <memory>

/* Goal: given a node in a BST, implement an algorithm to find it's in-order
   successor.

   A node's in-order successor in a BST is the next greater node in the BST.
   This node can be in one of two places:
   1. To the right of the predecessor
   2. One of the predecessor's ancestors

   To find this node, we first need to check if the given node has a right 
   subtree. If so, the successor is the leftmost node in the right subtree. 
   If not, we must keep visiting the next parent until we find a node that
   is greater than the node we were given.
*/

typedef std::shared_ptr<Tree::BinaryNode> PBNode;
PBNode leftmost(PBNode);

PBNode successor(PBNode n) {
  int val = n->val;
  /* If there is a right subtree, get the leftmost node in this subtree */
  if (n->right) return leftmost(n->right);
  /* Otherwise, keep visiting ancestor's until we find it */
  while(n = n->parent) if (n->val > val) return n;\
  /* No successor, return a null ptr */
  return nullptr;
}

PBNode leftmost(PBNode n) {
  if (!n->left) return n;
  return leftmost(n->left);
}

PBNode findNode(PBNode root, int n) {
  if (!root || n == root->val) return root;
  if (n < root->val) return findNode(root->left, n);
  if (n > root->val) return findNode(root->right, n);
}

int main() {
  std::cout << "Enter a binary search tree in it's array representation:"
	    << std::endl;
  PBNode tree = Tree::read(std::cin);
  std::cout << "Enter a node: ";
  int x;
  std::cin >> x;
  PBNode n = findNode(tree, x);
  if (!n) {
    std::cout << "invalid node." << std::endl;
    return -1;
  }
  PBNode s = successor(n);
  if (s) std::cout << "Successor: " << s->val << std::endl;
  else std::cout << "No successor." << std::endl;
  return 0;
}


