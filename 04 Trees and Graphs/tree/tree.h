#pragma once
#include <memory>
#include <vector>
#include <iostream>

namespace Tree {
  struct BinaryNode {
    int val;
    std::shared_ptr<BinaryNode> parent = nullptr;
    std::shared_ptr<BinaryNode> left = nullptr;
    std::shared_ptr<BinaryNode> right = nullptr;

    BinaryNode(int val) : val(val) {}
  };

  std::shared_ptr<BinaryNode> read(std::istream&);
  std::shared_ptr<BinaryNode> vectorToTree(const std::vector<std::string>&);
  std::shared_ptr<BinaryNode> find(std::shared_ptr<BinaryNode>, int);
  void inorderPrint(std::shared_ptr<BinaryNode> tree);
}
