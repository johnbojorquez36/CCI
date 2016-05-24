#include <string>
#include <iostream>
#include <sstream>

std::string compress(std::string str) {
  int count = 0;
  char lastChar = str[0];
  std::ostringstream compressed;

  for (auto it = str.begin(); it != str.end(); ++it) {
    /* If the current character is different from the last
       or we've reached the end of the string */
    if (*it != lastChar || std::next(it) == str.end()) {
      compressed << lastChar << count;
      count = 0;
    } else {
      ++count;
    }
    lastChar = *it;
  }

  std::string compstr = compressed.str();
  return compstr.size() >= str.size() ? str : compstr;
}

int main() {
  std::cout << "Enter a string to compress: ";
  std::string str;
  std::cin >> str;
  std::cout << compress(str) << std::endl;
  return 0;
}
