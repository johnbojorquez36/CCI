#include <string>
#include <iostream>
#include <sstream>

std::string compress(std::string str) {
  int count = 0;
  std::ostringstream compressed;

  for (auto it = str.begin(); it != str.end(); ++it) {
    ++count;
    /* If the next character is different from the last current
       or we've reached the end of the string */
    if (std::next(it) == str.end() || *std::next(it) != *it) {
      compressed << *it << count;
      count = 0;
    }
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
