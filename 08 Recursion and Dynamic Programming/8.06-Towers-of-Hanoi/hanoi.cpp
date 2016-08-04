#include <iostream>
#include <chrono>
#include <stack>


void solveHanoi(std::stack<int>& source, std::stack<int>& temp, std::stack<int>& dest, int n) {
  if (n == 0) return;
  /* Move n-1 disks from source peg to temp */
  solveHanoi(source, dest, temp, n-1);

  /* Move the nth disk from source to dest */
  dest.push(source.top());
  source.pop();

  /* Move the n-1 disks from temp to dest */
  solveHanoi(temp, source, dest, n-1);
}

int main() {
  int n;
  std::stack<int> peg1;
  std::stack<int> peg2;
  std::stack<int> peg3;
  
  std::cout << "Enter the number of disks to use: ";
  std::cin >> n;
  
  for (int i = n; i > 0; --i) peg1.push(i);
  solveHanoi(peg1, peg2, peg3, n);
  
  std::cout << "Disks on the third peg after solving: " << std::endl;
  while(!peg3.empty()) {
    std::cout << peg3.top() << ", ";
    peg3.pop();
  }
  std::cout << "\b\b " << std::endl;
  
  return 0;
}
