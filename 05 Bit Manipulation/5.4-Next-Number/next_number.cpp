#include <iostream>

int getNextLargest(int n) {
  if (n == 0) return -1;
  int onesToRight = 0;
  int i = 0, k = n;
  /* Skip all trailing 0s */
  while ((k & 1) == 0) {
    ++i;
    k >>= 1;
  }

  /* Count 1s to right */
  while ((k & 1) == 1) {
    ++onesToRight;
    ++i;
    k >>= 1;
  }

  if (i == 31 || i == 0) return -1;

  n |= (1 << i);
  int mask = ~((1 << i) - 1);
  int ones = (1 << onesToRight-1) - 1;
  return (n & mask) | ones;
}

int getNextSmallest(int n) {
  if (n == 0) return -1;
  int zerosToRight = 0;
  int i = 0, k = n;
  /* Skip all trailing 1s */
  while ((k & 1) == 1) {
    ++i;
    k >>= 1;
  }

  /* Count 0s to right */
  while ((k & 1) == 0) {
    ++zerosToRight;
    ++i;
    k >>= 1;
  }

  if (i == 31 || i == 0) return -1;

  n &= ~(1 << i);
  int mask = ((1 << i) - 1);
  int zeros = ~((1 << zerosToRight-1) - 1);
  return (n | mask) & zeros;
}

int main() {
  std::cout << "Enter a number: ";
  int n;
  std::cin >> n;
  std::cout << "Next largest: " << getNextLargest(n) << std::endl;
  std::cout << "Next smallest: " << getNextSmallest(n) << std::endl;
  return 0;
}

