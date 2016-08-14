#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <unordered_map>

std::string sortString(std::string str) {
  std::vector<std::string> buckets(256, "");
  for (char c : str) buckets[c] += c;
  std::string result;
  for (std::string s : buckets) result += s;
  return result;
}

std::vector<std::string> groupAnagrams(std::vector<std::string> strings) {
  std::unordered_map<std::string,int> anagramCounts;
  for (std::string s : strings) anagramCounts[sortString(s)]++;
  std::vector<std::string> anagramsSorted;
  for (std::pair<std::string,int> p : anagramCounts) {
    for (int i = 0; i < p.second; ++i) {
      anagramsSorted.push_back(p.first);
    }
  }
  return anagramsSorted;
}

std::vector<std::string> readVector(std::istream& in) {
  std::string x;
  std::string line;
  std::vector<std::string> nums;
  std::getline(in, line);
  std::stringstream ss(line);
  while (ss >> x) nums.push_back(x);
  return nums;
}


int main() {
  std::cout << "Enter an array of strings (single words):" << std::endl;
  std::vector<std::string> strings = readVector(std::cin);
  std::vector<std::string> sortedAnagrams = groupAnagrams(strings);
  std::cout << "Grouped anagrams:" << std::endl;
  for (std::string s : sortedAnagrams) std::cout << s << ", ";
  std::cout << "\b\b " << std::endl;
  return 0;
}
