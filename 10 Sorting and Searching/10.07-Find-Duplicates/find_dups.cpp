#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class BitSet {
  std::vector<int> bitSet;

public:
  BitSet(int numBits) :
    bitSet((numBits >> 5) + 1) {}
  
  bool contains(int n) {
    return bitSet[n >> 5] & (1 << (n % 32));
  }

  void insert(int n) {
    bitSet[n >> 5] |= (1 << (n % 32));
  }
};

/* Memory limit: 4KB */
void printDups(std::vector<int>& nums) {
  BitSet seen(32000);

  int x;
  for (int x : nums) {
    if (seen.contains(x)) {
      std::cout << x << std::endl;
    } else {
      seen.insert(x);
    }
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
  std::cout << "Enter a list of integers in the range [1, 32000]: " << std::endl;
  std::vector<int> nums = readVector(std::cin);
  std::cout << "Duplicates: " << std::endl;
  printDups(nums);
  return 0;
}
