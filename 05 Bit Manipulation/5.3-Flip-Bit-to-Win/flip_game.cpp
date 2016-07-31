#include <iostream>
#include <algorithm>

int flipBit(int n, bool canFlip, int sofar) {
  if (n == 0) return sofar + canFlip;
  if ((n & 1) == 0) {
    if (canFlip) {
      int flip = flipBit(n >> 1, false, sofar+1);
      int noflip = flipBit(n >> 1, true, 0);
      return std::max(flip, noflip);
    } else {
      return sofar;
    }
  } else {
    return flipBit(n>>1, canFlip, sofar+1);
  }
}

int main() {
  std::cout << "Enter and integer: ";
  int n;
  std::cin >> n;
  std::cout << "Longest sequence of 1s after flip: " << flipBit(n, true, 0) << std::endl;
  return 0;
}
