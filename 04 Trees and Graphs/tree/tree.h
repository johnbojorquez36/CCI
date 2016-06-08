#pragma once
#include <memory>
#include <vector>
#include <iostream>

namespace Tree {
  struct BinaryNode {
    int val;
    std::shared_ptr<BinaryNode> left;
    std::shared_ptr<BinaryNode> right;

    BinaryNode(int val) : val(val) {}
  };

  std::shared_ptr<BinaryNode> read(std::istream&);
  std::shared_ptr<BinaryNode> vectorToTree(const std::vector<std::string>&);
  void inorderPrint(std::shared_ptr<BinaryNode> tree);
}
