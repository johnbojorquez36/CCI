#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int sparseFind(std::vector<std::string> strings, std::string target) {
  int low = 0, high = strings.size()-1;

  while (low < high) {
    int mid = (low + high) / 2;
    int lookAhead = mid;
    while(lookAhead <= high && strings[lookAhead].size() == 0) {
      ++lookAhead;
    }

    if (lookAhead > high) {
      high = mid - 1;
    } else if (strings[lookAhead].compare(target) == 0) {
      return lookAhead;
    } else if (strings[lookAhead].compare(target) < 0) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

std::vector<std::string> readVector(std::istream& in) {
  std::string x;
  std::string line;
  std::vector<std::string> nums;
  std::getline(in, line);
  std::stringstream ss(line);
  while (ss >> x) nums.push_back(x.compare("''") == 0? "" : x);
  return nums;
}


int main() {
  std::string target;
  std::cout << "Enter sorted array of strings interspersed with empty strings (indicated by two single quotes):" << std::endl;
  std::vector<std::string> strings = readVector(std::cin);
  std::cout << "Enter the target string: ";
  std::cin >> target;
  std::cout << "Found " << target << " at index " << sparseFind(strings, target) << std::endl;
  return 0;
}
