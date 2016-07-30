#include "tree.h"
#include <string>
#include <unordered_set>

typedef std::shared_ptr<Tree::BinaryNode> PBNode;

int numPathsWithSum(PBNode root, int sum, int sofar, std::unordered_set<int>& pathSums) {
  if (!root) return 0;
  pathSums.insert(sofar+root->val);
  return pathSums.count(sum - root->val) +
    numPathsWithSum(root->left, sum, sofar+root->val, pathSums) +
    numPathsWithSum(root->right, sum, sofar+root->val, pathSums);
}

int numPathsWithSum(PBNode root, int sum) {
  std::unordered_set<int> pathSums;
  return numPathsWithSum(root, sum, 0, pathSums);
}

int main() {
    std::cout << "Enter the array representation of a binary tree for T1 "
	    << "(ex. 1 3 4 null 8): "
	    << std::endl;
    std::shared_ptr<Tree::BinaryNode> T = Tree::read(std::cin);
    std::cout << "Enter a target sum: ";
    int target;
    std::cin >> target;
    std::cout << "Number of paths that sum " << target << ": " << numPathsWithSum(T, target) << std::endl;
}
