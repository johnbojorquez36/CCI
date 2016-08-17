#include <iostream>
#include <vector>
#include <sstream>

struct TreeNode  {
  int val;
  int leftSize = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;
  TreeNode(int v) :
    val(v) {}
};


TreeNode* insert(TreeNode* n, TreeNode* root) {
  if (!root) return n;
	
  if (n->val <= root->val) {
    root->leftSize++;
    root->left = insert(n, root->left);
  } else {
    root->right = insert(n, root->right);
  }

  return root;
}

TreeNode* insert(int val, TreeNode* root) {
  return insert(new TreeNode(val), root);
}

class RankStream {
  TreeNode* data = nullptr;

public:
  void track(int x) {
    data = insert(x, data);
  }
	
  int getRankOfNumber(int x) {
    return getRankOfNumber(x, data);
  }

private:
  int getRankOfNumber(int x, TreeNode* data) {
    if (!data) return 0;
    if (x == data->val) return data->leftSize;
    if (x < data->val) return getRankOfNumber(x, data->left);
    else return 1 + data->leftSize + getRankOfNumber(x, data->right);
  }
};

std::vector<int> readVector(std::istream& in) {
  int x;
  std::string line;
  std::vector<int> nums;
  std::getline(in, line);
  std::stringstream ss(line);
  while (ss >> x) nums.push_back(x);
  return nums;
}

int main() {
  int x;
  std::cout << "Enter a list of numbers: " << std::endl;
  std::vector<int> nums = readVector(std::cin);
  RankStream rs;
  for (int x : nums) rs.track(x);
  while (true) {
    std::cout << "Enter a number to get the rank of (Ctrl-z to quit): ";
    std::cin >> x;
    std::cout << "Rank: " << rs.getRankOfNumber(x) << std::endl;
  }
  return 0;
}
