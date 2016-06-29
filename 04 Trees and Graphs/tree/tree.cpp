#include "tree.h"
#include <iostream>
#include <string>
#include <sstream>

namespace Tree {

  std::shared_ptr<BinaryNode> read(std::istream& in) {
    std::string line;
    std::getline(in, line);
    std::stringstream ss(line);
    std::vector<std::string> vals;
    std::string x;
    while (ss >> x) vals.push_back(x);
    return vectorToTree(vals);
  }

  std::shared_ptr<BinaryNode> vectorToTree(const std::vector<std::string>& v, int i) {
    if (i >= v.size()) return nullptr;
    if (v[i].compare("null") == 0) return nullptr;
    auto root = std::make_shared<BinaryNode>(std::stoi(v[i]));
    root->left = vectorToTree(v, i*2 + 1);
    if (root->left) root->left->parent = root;
    root->right = vectorToTree(v, i*2 + 2);
    if (root->right) root->right->parent = root;
    return root;
  }

  std::shared_ptr<BinaryNode> vectorToTree(const std::vector<std::string>& v) {
    return vectorToTree(v, 0);
  }

  void inorderPrint(std::shared_ptr<BinaryNode> tree) {
    if (!tree) return;
    inorderPrint(tree->left);
    std::cout << tree->val << " ";
    inorderPrint(tree->right);
  }

  std::shared_ptr<BinaryNode> find(std::shared_ptr<BinaryNode> root, int n) {
    if (nullptr == root) return root;
    if (n == root->val) return root;
    std::shared_ptr<BinaryNode> findLeft = find(root->left, n);
    std::shared_ptr<BinaryNode> findRight = find(root->right, n);
    if (findLeft) return findLeft;
    else return findRight;
  }

}
