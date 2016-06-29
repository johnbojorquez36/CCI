#include <random>
#include <iostream>


/* Goal: implement a binary tree which supports the method getRandomNode()

   If we imagine the tree as an array, it seems pretty obvious to compute
   a random index and return that node. We could actually implement something
   similar by keeping track of the size of each subtree. Then, all we need to
   do is compute a random index, and do a binary search for it using the size
   of each subtree.

   Apparently we can assume this is a BST.
*/

/* Not going to test this one */

class RandomNodeTree {
  std::random_device randev;
  std::mt19937 gen;

  struct TreeNode  {
    int size = 0;
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
  };

  TreeNode* root = nullptr;

public:

  RandomNodeTree() : randev(), gen(randev()), root(nullptr) {}

  TreeNode* insert(TreeNode* root, int x) {
    if (!root) {
      TreeNode* n = new TreeNode;
      n->val = x;
      return n;
    }

    if (x < root->val) {
      root->left = insert(root->left, x);
    } else {
      root->right = insert(root->right, x);
    }
    root->size++;
    return root;
  }
  
  void insert(int x) {
    root = insert(root, x);
  }

  TreeNode* find(TreeNode* root, int x) {
    if (!root || x == root->val) return root;
    if (x < root->val) return find(root->left, x);
    else return find(root->right, x);
  }
  
  TreeNode* find(int x) {
    return find(root, x);
  }

  TreeNode* getNode(TreeNode* root, int i) {
    int sizeLeft = root->left? root->left->size : 0;
    int sizeRight = root->right? root->right->size : 0;

    if (i < sizeLeft) return getNode(root->left, i);
    else if (i == sizeLeft) return root;
    else return getNode(root->left, i);
  }

  TreeNode* getRandomNode() {
    if (!root) return root;
    std::uniform_int_distribution<int> dist(0, root->size);
    int rand = dist(gen);
    return getNode(root, rand);
  }
};
