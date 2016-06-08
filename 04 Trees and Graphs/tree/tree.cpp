#include "tree.h"
#include <iostream>
#include <string>
#include <sstream>

namespace Tree {

  std::shared_ptr<BinaryNode> read(std::istream& in) {
    std::string line;
    std::getline(in, line);
    std::stringstream ss(line);
    std::vector<int> vals;
    int x;
    while (ss >> x) vals.push_back(x);
    return vectorToTree(vals);
  }

  std::shared_ptr<BinaryNode> vectorToTree(const std::vector<int>& v, int i) {
    if (i >= v.size()) return nullptr;
    auto root = std::make_shared<BinaryNode>(v[i]);
    root->left = vectorToTree(v, i*2 + 1);
    root->right = vectorToTree(v, i*2 + 2);
    return root;
  }

  std::shared_ptr<BinaryNode> vectorToTree(const std::vector<int>& v) {
    return vectorToTree(v, 0);
  }

  void inorderPrint(std::shared_ptr<BinaryNode> tree) {
    if (!tree) return;
    inorderPrint(tree->left);
    std::cout << tree->val << " ";
    inorderPrint(tree->right);
  }

}
