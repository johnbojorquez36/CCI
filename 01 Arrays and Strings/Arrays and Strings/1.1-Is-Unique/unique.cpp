#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

template<typename T>
bool containsKey(unordered_set<T> m, T key) {
  return m.find(key) != m.end();
}

bool isUnique(string str) {
  unordered_set<char> mem; // Hash set for "remembering" characters
  for (char c : str) {
    // Check if the character has already been seen
    if (containsKey(mem, c)) return false;
    // "Remember" the character
    mem.insert(c);
  }
  return true;
}

int main() {
  string s;
  cout << "Enter a string: " << endl;
  cin >> s;
  cout << (isUnique(s) ? "The string is unique" : "The string is not unique") << endl;
  return 0;
}
