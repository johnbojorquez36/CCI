#include <iostream>

int numToConvert(int a, int b) {
  int count = 0;
  while (a | b) {
    if (!((a & 1) && (b & 1))) ++count;
    a >>= 1;
    b >>= 1;
  }
  return count;
}

int main() {
  std::cout << "Enter two integers: ";
  int a, b;
  std::cin >> a >> b;
  std::cout << "Number of bits to convert: " << numToConvert(a, b) << std::endl;
  return 0;
}
