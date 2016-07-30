#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string binaryToString(double x) {
  if (x < 0 || x > 1) return "ERROR";
  int count = 0;
  std::stringstream res;
  while (x > 0) {
    if (count++ >= 32) return "ERROR";
    double m = 2 * x;
    if (m >= 1) {
      res << 1;
      x = m - 1;
    } else {
      res << 0;
      x = m;
    }
  }
  return res.str();
}

int main() {
  std::cout << "Enter a double between 0 and 1: ";
  double x;
  std::cin >> x;
  std::cout << binaryToString(x) << std::endl;
  
  return 0;
}
