#include <iostream>
#include <map>
#include <string>

using namespace std;

bool permutation(const string &a, const string &b) {
  if (a.size() != b.size()) return false;
  map<char, int> counts;
  for (char c : a) ++counts[c];
  for (char c : b) {
    --counts[c];
    if (counts[c] < 0) return false;
  }
  return true;
}

int main() {
  string a, b;
  cout << "Enter a string: ";
  cin >> a;
  cout << "Enter another string: ";
  cin >> b;
  cout << (permutation(a, b) ? "The strings are permuations of each other"
	   : "The strings are not permuations of each other") << endl;
}
