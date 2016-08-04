#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

void permutations(std::unordered_map<char,int>& freq, std::string perm, std::vector<std::string>& perms) {
  bool charsLeft = false;
  for (std::pair<char,int> p: freq) {
    if (freq[p.first]) {
      charsLeft = true;
      freq[p.first]--;
      permutations(freq, perm + p.first, perms);
      freq[p.first]++;
    }
  }
  
  if (!charsLeft) perms.push_back(perm);
}

std::vector<std::string> permutations(std::string str) {
  std::vector<std::string> perms;
  std::unordered_map<char,int> freq;
  for (char c : str) freq[c]++;
  permutations(freq, "", perms);
  return perms;
}

int main() {
  std::string str;
  std::cout << "Enter a string (it can have duplicates!): " << std::endl;
  std::cin >> str;
  std::vector<std::string> perms = permutations(str);
  std::cout << "Permutations: " << std::endl;
  for (std::string perm : perms) std::cout << perm << std::endl;
  return 0;
}
