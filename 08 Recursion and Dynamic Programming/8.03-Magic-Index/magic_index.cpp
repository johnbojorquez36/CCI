#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

/* Follow up: What if the integer's we're necessarily distinct?
   In this case, we would have to do a linear search for the magic index.
   There is no way to narrow the search space like before. For example,
   suppose we have the following list:
   
   5 5 5 5 5 5

   If we try to split up the search space as before, we will notice that the
   value at index 2 is greater than the index itself. Before, this would be useful
   information. We could then be sure that the magic index MUST exist to the left.
   However, with repeating elements, there is no way, just with this information,
   to decide whether the magic number is to the left or the right.
*/

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
