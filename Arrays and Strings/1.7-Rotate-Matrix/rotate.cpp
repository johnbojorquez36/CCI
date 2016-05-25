#include <iostream>
#include <sstream>
#include <vector>

bool rotate(std::vector<std::vector<int>>& M) {
  /* Make sure the matrix is square */
  if (M.size() == 0 || M.size() != M[0].size()) return false;

  /* We will rotate track by track (like a disk) starting with
     the outer track */
  for (int track = 0; track < M.size() / 2; ++track) {
    int begin = track;
    int end = M.size() - begin - 1;
    for (int i = begin; i < end; ++i) {
      int diff = i - begin;
      /* Temporarily store the value at the top */
      int temp = M[begin][i];
      /* Move from left to top */
      M[begin][i] = M[end - diff][begin];
      /* Move from bottom to left */
      M[end - diff][begin] = M[end][end - diff];
      /* Move from right to bottom */
      M[end][end - diff] = M[i][end];
      /* Move from temp (top) to right */
      M[i][end] = temp;
    }
  }
  /* Matrix was successfully rotated */
  return true;
}

void printMatrix(std::vector<std::vector<int>> M) {
  for (std::vector<int> v : M) {
    for (int x : v) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }
}

std::vector<std::vector<int>> readMatrix(std::istream& in) {
  std::vector<std::vector<int>> M;
  std::string line;
  while (getline(in, line)) {
    std::stringstream ls(line);
    int x;
    std::vector<int> v;
    while (ls >> x) {
      v.push_back(x);
    }
    M.push_back(v);
  }
  return M;
}



int main() {
  std::cout << "Enter an N x N matrix row by row (send EOF to end input): " << std::endl;
  std::vector<std::vector<int>> M = readMatrix(std::cin);
  std::cout << std::endl << "Rotated: " << std::endl;
  if (rotate(M)) printMatrix(M);
  else std::cout << "Invalid matrix dimensions." << std::endl;
  return 0;
}
