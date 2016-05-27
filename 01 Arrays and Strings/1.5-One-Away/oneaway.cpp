#include <iostream>
#include <string>
#include <cmath>

bool isOneAway(std::string& a, std::string& b) {

  /* The strings are obviously more than one edit apart */
  if (std::abs(a.size() - b.size()) > 1) return false;

  int i = 0, j = 0;
  bool editMade = false;

  while (i != a.size() && j != b.size()) {
    /* If two characters differ, and edit must be made */
    if (a[i] != b[j]) {
      /* If an edit has already been made, they can't be one away */
      if (editMade) return false;

      /* Increment i and j depending on which is missing a character */
      if (a.size() > b.size()) ++i;
      else if (a.size() < b.size()) ++j;
      else {
	++i;
	++j;
      }
      editMade = true;
    } else {
      ++i;
      ++j;
    }
  }

  return true;
}

int main() {
  std::string str1, str2;

  std::cout << "Enter a string: ";
  std::cin >> str1;
  std::cout << "Enter another string: ";
  std::cin >> str2;

  std::cout << "The strings " << (isOneAway(str1, str2) ? "are" : "are not") << " one away." << std::endl;
}
