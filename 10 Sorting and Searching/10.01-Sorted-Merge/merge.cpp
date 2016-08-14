#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

void mergeInto(std::vector<int>& A, std::vector<int>& B) {
  int i = A.size() -  B.size() - 1;
  int j = B.size() - 1;
  int insert = A.size() - 1;

  while (i >= 0 && j >= 0) {
    if (A[i] > B[j]) {
      A[insert--] = A[i--];
    } else {
      A[insert--] = B[j--];
    }
  }

  while (i >= 0) A[insert--] = A[i--];
  while (j >= 0) A[insert--] = B[j--];

}

std::vector<int> readVector(std::istream& in) {
  int x;
  std::string line;
  std::vector<int> nums;
  std::getline(in, line);
  std::stringstream ss(line);
  while (ss >> x) nums.push_back(x);
  return nums;
}

int main() {
  std::cout << "Enter the first array (I'll sort it, don't worry ;) ):" << std::endl;
  std::vector<int> A = readVector(std::cin);
  std::cout << "Enter the second array:" << std::endl;
  std::vector<int> B = readVector(std::cin);
  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());
  A.resize(A.size() + B.size(), 0);
  mergeInto(A, B);

  std::cout << "Merged:" << std::endl;
  for (int x : A) std::cout << x << ", ";
  std::cout << "\b\b " << std::endl;
  return 0;
}
