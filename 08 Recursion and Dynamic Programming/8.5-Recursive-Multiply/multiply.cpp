#include <iostream>

int multiply(int a, int b) {
  if (a == 0) return 0;
  /* We can use the fact that a * b = (a / 2) * b * 2 */
  return (multiply(a - (a % 2) >> 1, b) << 1) + (a % 2 ? b : 0);
}

int main() {
  std::cout << "Enter two positive integers to multiply: ";
  int a, b;
  std::cin >> a >> b;
  std::cout << a << " * " << b << " = " << multiply(a, b) << std::endl;
  return 0;
}
