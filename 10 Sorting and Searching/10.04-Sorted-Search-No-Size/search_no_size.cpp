#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

class Listy {
  std::vector<int> nums;
  
public:
  void push_back(int x) {
    nums.push_back(x);
  }
  
  int elementAt(int i) {
    return i >= nums.size()? -1 : nums[i];
  }
  
  std::vector<int>::iterator begin() {
    return nums.begin();
  }
  
  std::vector<int>::iterator end() {
    return nums.end();
  }
};

int findInListy(Listy L, int target) {
  int low = 0;
  int high = 1;

  /* Determine a reasonable range to look in */
  while (L.elementAt(high) >= 0) {
    if (L.elementAt(high) == target) {
      return high;
    } else if (L.elementAt(high) > target) {
      break;
    }
    low = high;
    high *= 2;
  }
  /* Binary search for value (note that the range will be at most n) */
  while (low < high) {
    int mid = (low + high)/2;
    if (L.elementAt(mid) == target) {
      return mid;
    } else if (L.elementAt(mid) > target || L.elementAt(mid) == -1) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

Listy readListy(std::istream& in) {
  int x;
  std::string line;
  Listy nums;
  std::getline(in, line);
  std::stringstream ss(line);
  while (ss >> x) nums.push_back(x);
  return nums;
}

int main() {\
  int target;
  std::cout << "Enter the an array of integers (I'll sort it):" << std::endl;
  Listy nums = readListy(std::cin);
  std::cout << "Enter the target element: ";
  std::cin >> target;
  std::sort(nums.begin(), nums.end());
  for (int x : nums) std::cout << x << " ";
  std::cout << std::endl;
  std::cout << "Found " << target << " at index " << findInListy(nums, target) << std::endl;
  return 0;
}
