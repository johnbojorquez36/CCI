#include "tree.h"
#include <iostream>
#include <memory>

/* Goal: implement an algorithm to find the first common ancestor of
   two nodes in a binary tree.

   Since the given tree is not necessarily a binary search tree, it
   is inevitable that we will need to search all of the nodes in our 
   tree to find the two given nodes. There is no way to narrow the
   search space based on properties of the tree. In our search for
   nodes a and b, there are a few scenarios:
   1. a is the root
   2. b is the root
   3. a and b exist in the left subtree
   4. a and b exist in the right subtree
   5. a exists in the right subtree, b in left
   6. b exists in the right subtree, a in left

   For scenarios 1 and 2, it is obvious that the root is the first
   common ancestor. This is also the case for 5 and 6. For 3, the 
   first common ancestor is located in the left subtree, so we must
   search there. We do the same for 4 with the right subtree.

   The problem is, writing an exists() function would cause us to
   duplicate work. As we are traversing the whole tree, for each node
   we would be traversing an entire subtree. Not good. So let's keep
   track of whether a and b exist and the first common ancestor all
   with a custom object that can be returned by the function.
*/

typedef std::shared_ptr<Tree::BinaryNode> PBNode;

struct Existence {
  bool existA;
  bool existB;
  PBNode fca;

  Existence(bool eA, bool eB, PBNode fca) :
    existA(eA), existB(eB), fca(fca) {}
};

Existence findExistence(PBNode root, PBNode a, PBNode b) {
  if (!root) return Existence(false, false, nullptr);
  
  Existence leftExistence = findExistence(root->left, a, b);
  if (leftExistence.existA && leftExistence.existB) {
    return leftExistence;
  }

  Existence rightExistence = findExistence(root->right, a, b);
  if (rightExistence.existA && rightExistence.existB) {
    return rightExistence;
  }
    
  bool existA = leftExistence.existA || rightExistence.existA || a == root;
  bool existB = leftExistence.existB || rightExistence.existB || b == root;
  PBNode fca;
  if (existA && existB) {
    fca = root;
  }

  return Existence(existA, existB, root);
}

PBNode firstCommonAncestor(PBNode root, PBNode a, PBNode b) {
  Existence e = findExistence(root, a, b);
  return e.fca;
}

int main() {
  std::cout << "Enter a binary search tree in it's array representation:"
	    << std::endl;
  PBNode tree = Tree::read(std::cin);
  int x,y;
  std::cout << "Enter a node: ";
  std::cin >> x;
  std::cout << "Enter another node: ";
  std::cin >> y;
  PBNode a = Tree::find(tree, x);
  PBNode b = Tree::find(tree, y);
  if (!a || !b) {
    std::cout << "invalid node." << std::endl;
    return -1;
  }

  PBNode s = firstCommonAncestor(tree, a, b);
  if (s) std::cout << "First common ancestor: " << s->val << std::endl;
  return 0;
}
