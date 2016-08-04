#include <iostream>
#include <vector>

/* Recursive approach */
int tripleStep(int n) {
  if (n <= 0) return 1;
  int step1 = tripleStep(n-1);
  int step2 = (n < 2) ? 0 : tripleStep(n-2);
  int step3 = (n < 3) ? 0 : tripleStep(n-3);
  return step1 + step2 + step3;
}

/* Bottom-up DP aproach */
int tripleStepDP(int n) {
  /* a, b, and c keep track of ways for last 3 steps */
  int a = 1;
  int b = a;
  int c = a + b;
  for (int i = 3; i <= n; ++i) {
    /* tripleStep(n) = tripleStep(n-3) + tripleStep(n-2) + tripleStep(n-1); */
    int next = a + b + c;
    a = b;
    b = c;
    c = next;
  }
  return c;
}

int main() {
  std::cout << "Enter the number of steps: ";
  int n;
  std::cin >> n;
  std::cout << "There are " << tripleStepDP(n) <<
    " ways to get up the stairs." << std::endl;
  return 0;
}
