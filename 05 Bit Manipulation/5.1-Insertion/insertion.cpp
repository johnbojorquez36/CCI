#include <iostream>

int insert(int N, int M, int i, int j) {
  int mask = ((1 << i) - 1) | (-1 << (j + 1));
  return (N & mask) | (M << i);
}

int main() {
  int N, M, i, j;
  std::cout << "Please enter N M i j:" << std::endl;
  std::cin >> N >> M >> i >> j;
  std::cout << M << " inserted into " << N << ": " << insert(N, M, i, j) << std::endl;
  return 0;
}
