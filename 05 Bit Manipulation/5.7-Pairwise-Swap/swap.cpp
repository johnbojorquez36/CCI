#include <iostream>

int pairwiseSwap(int n) {
  return ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
}

int main() {
  std::cout << "Enter an integer: ";
  int n;
  std::cin >> n;
  std::cout << "Pairwise swapped: " << pairwiseSwap(n) << std::endl;
  return 0;
}

