#include <vector>
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

void permutations(std::string str, int start, std::unordered_set<std::string>& perms) {
  if (start == str.size()) {
    perms.insert(str);
    return;
  }

  for (int i = start; i < str.size(); ++i) {
    if (i == start || str[i] != str[start]) {
      std::swap(str[start], str[i]);
      permutations(str, start+1, perms);
      std::swap(str[start], str[i]);
    }
  }
}

std::unordered_set<std::string> permutations(std::string str) {
  std::unordered_set<std::string> perms;
  permutations(str, 0, perms);
  return perms;
}

int main() {
  std::string str;
  std::cout << "Enter a string (it can have duplicates!): " << std::endl;
  std::cin >> str;
  std::unordered_set<std::string> perms = permutations(str);
  std::cout << "Permutations: " << std::endl;
  for (std::string perm : perms) std::cout << perm << std::endl;
  return 0;
}
