#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

void permutations(std::string str, int start, std::vector<std::string>& perms) {
  if (start == str.size()) {
    perms.push_back(str);
    return;
  }

  for (int i = start; i < str.size(); ++i) {
    std::swap(str[start], str[i]);
    permutations(str, start+1, perms);
    std::swap(str[start], str[i]);
  }
}

std::vector<std::string> permutations(std::string str) {
  std::vector<std::string> perms;
  permutations(str, 0, perms);
  return perms;
}

int main() {
  std::string str;
  std::cout << "Enter a string with all unique characters: " << std::endl;
  std::cin >> str;
  std::vector<std::string> perms = permutations(str);
  std::cout << "Permutations: " << std::endl;
  for (std::string perm : perms) std::cout << perm << std::endl;
  return 0;
}
