#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>

int indexOfMax(std::vector<int>& nums, int i, int j, int k) {
  int maxNum = std::max(nums[i], std::max(nums[j], nums[k]));
  if (nums[i] == maxNum) return i;
  if (nums[j] == maxNum) return j;
  else return k;
}

void valleySort(std::vector<int>& nums) {
  for (int i = 1; i < nums.size(); i +=2) {
    int j = indexOfMax(nums, i - 1, i, i == nums.size()? i : i + 1);
    std::swap(nums[i], nums[j]);
  }
}

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
  std::cout << "Enter a list of integers: " << std::endl;
  std::vector<int> nums = readVector(std::cin);
  valleySort(nums);
  std::cout << "Valley sorted: " << std::endl;
  for (int x : nums) std::cout << x << " ";
  std::cout << std::endl;
  return 0;
}
