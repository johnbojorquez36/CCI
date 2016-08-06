#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int magicIndex(std::vector<int> nums, int low, int high) {
  if (high < low) {
    return -1;
  }
  int mid = (high + low) / 2;
  if (nums[mid] == mid) return mid;
  else if (nums[mid] < mid) return magicIndex(nums, mid+1, high);
  else return magicIndex(nums, low, mid-1);
}
  
int magicIndex(std::vector<int> nums) {
  return magicIndex(nums, 0, nums.size()-1);
}

/* Follow up: What if the integer's we're necessarily distinct? */
int magicIndexRepeat(std::vector<int> nums, int low, int high) {
  if (high < low) {
    return -1;
  }
  int mid = (high + low) / 2;
  if (nums[mid] == mid) return mid;

  int magicIndex = magicIndexRepeat(nums, low, nums[mid]);
  if (magicIndex >= 0) return magicIndex;
  return magicIndexRepeat(nums, mid+1, high);
}
  
int magicIndexRepeat(std::vector<int> nums) {
  return magicIndexRepeat(nums, 0, nums.size()-1);
}

std::vector<int> readVector(std::istream& in) {
  std::string line;
  std::vector<int> v;
  getline(in, line);
  std::stringstream ss(line);
  int x;
  while(ss >> x) v.push_back(x);
  return v;
}

int main() {
  std::cout << "Enter a list of distinct integers. They don't have to be sorted. "
	    << "Don't worry, I'll sort them ;): " << std::endl;
  std::vector<int> nums = readVector(std::cin);
  std::sort(nums.begin(), nums.end());
  std::cout << "The magic index is: " << magicIndex(nums) << std::endl;
  return 0;
}
