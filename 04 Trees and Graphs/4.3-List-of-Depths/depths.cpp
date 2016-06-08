#include "tree.h"
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <memory>
#include <cmath>

/* Goal: Implement an algorithm which creates a list of lists of nodes
   at each level of a binary tree.

   We could do this recursively, but it wouldn't be very elegant. We 
   would need to keep track of the current depth as well as pass a 
   reference to the list of lists for each recursive call. Actually
   it's not that bad. We could also use BFS to do this iteratively.
   I'll implement both below.
*/

typedef std::shared_ptr<Tree::BinaryNode> PBNode;

/* Iterative solution using BFS */
std::vector<std::list<PBNode>> depths(PBNode root) {
  /* The frontier will hold the nodes which we plan to visit */
  std::queue<PBNode> frontier;
  /* A vector of lists of nodes at each level */
  std::vector<std::list<PBNode>> depthLists;
  
  frontier.push(root);
  /* Keep track of how many nodes we've visited */
  int count = 1;
  while (!frontier.empty()) {
    int depth = log2(count++);
    /* If we haven't been to this depth yet, make a new list */
    if (depth >= depthLists.size()) depthLists.push_back(std::list<PBNode>());
    PBNode n = frontier.front();
    frontier.pop();
    depthLists[depth].push_back(n);
    if (n->left) frontier.push(n->left);
    if (n->right) frontier.push(n->right);
  }

  return depthLists;
}

/* Recursive solution, wow actually pretty elegant */
void depthsRec(PBNode root, std::vector<std::list<PBNode>>& depthLists, int depth) {
  if (!root) return;
  if (depth >= depthLists.size()) depthLists.push_back(std::list<PBNode>());
  depthLists[depth].push_back(root);
  depthsRec(root->left, depthLists, depth + 1);
  depthsRec(root->right, depthLists, depth + 1);
}

std::vector<std::list<PBNode>> depthsRec(PBNode root) {
  std::vector<std::list<PBNode>> depthLists;
  depthsRec(root, depthLists, 0);
  return depthLists;
}

int main() {
  std::cout << "Enter the array representation of a binary tree (ex. 1 3 4 null 8): "
	    << std::endl;
  PBNode root = Tree::read(std::cin);
  std::vector<std::list<PBNode>> depthLists = depths(root);
  std::cout << "Depth lists: " << std::endl;
  for (std::list<PBNode> depthList : depthLists) {
    for (PBNode n : depthList) {
      std::cout << n->val << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
