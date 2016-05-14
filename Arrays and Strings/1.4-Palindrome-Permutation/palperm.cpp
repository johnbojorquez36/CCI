#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

bool isPalPerm(std::string str) {
  std::unordered_map<char, int> counts;
  int numChars = 0;

  for (char c : str) {
    if (c != ' ') {
      ++numChars;
      ++counts[std::tolower(c)];
    }
  }

  bool evenLength = numChars % 2 == 0;
  bool oneOddCount = false;

  for (std::pair<const char, int>& entry : counts) {
    if (entry.second % 2) {
      /* If there are an even number of characters and a character appears an
	 odd number of times */
      if (evenLength) return false;
      /* Odd number of characters and more than one character appears an odd
	 number of times */
      else if (oneOddCount) return false;
      /* First character to appear an odd number of times */
      else oneOddCount = true;
    }
  }

  return true;
}

int main() {
  std::cout << "Enter a string: " << std:: endl;
  std::string str;
  std::getline(std::cin, str);
  bool palperm = isPalPerm(str);
  std::cout << "The string " << (palperm ? "is" : "isn't") << " a permutation of a palindrome." << std::endl;
  return 0;
}


