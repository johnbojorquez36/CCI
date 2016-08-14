#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

int findRotated(std::vector<int> nums, int target, int low, int high) {
  if (high <= low) return -1;

  int mid = (high + low) / 2;
  if (nums[mid] == target) {
    return mid;
  } else if (nums[high] == target) {
    return high;
  } else if (nums[low] == target) {
    return low;
  } else if (nums[mid] > nums[high] && (target < nums[high] || target > nums[mid])) {
    return findRotated(nums, target, mid+1, high-1);
  } else if (nums[mid] < nums[high] && target > nums[mid] && target < nums[high]) {
    return findRotated(nums, target, mid+1, high-1);
  } else {
    return findRotated(nums, target, low+1, mid-1);
  }
}


int findRotated(std::vector<int>& nums, int target) {
  return findRotated(nums, target, 0, nums.size()-1);
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

int main() {\
  int k;
  int target;
  std::cout << "Enter the an array of integers (I'll sort it):" << std::endl;
  std::vector<int> nums = readVector(std::cin);
  std::cout << "Enter the amount to rotate by: ";
  std::cin >> k;
  std::cout << "Enter the target element: ";
  std::cin >> target;
  std::sort(nums.begin(), nums.end());
  
  std::vector<int> rotated(nums.size());
  for (int i = 0; i < rotated.size(); ++i) {
    rotated[(i + k) % rotated.size()] = nums[i];
  }

  std::cout << "Found " << target << " at index " << findRotated(rotated, target) << std::endl;
  return 0;
}
