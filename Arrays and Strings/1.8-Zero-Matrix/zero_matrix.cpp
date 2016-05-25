#include <iostream>
#include <vector>
#include <sstream>

void zeroRow(std::vector<std::vector<int>>& M, int i) {
  for (int j = 0; j < M[i].size(); ++j) {
    M[i][j] = 0;
  }
}

void zeroCol(std::vector<std::vector<int>>& M, int j) {
  for (int i = 0; i < M.size(); ++i) {
    M[i][j] = 0;
  }
}

void zeroMatrix(std::vector<std::vector<int>>& M) {
  /* Keep track of which rows and columns have zeroes */
  std::vector<bool> zrows(M.size());
  std::vector<bool> zcols(M[0].size());

  for (int i = 0; i < M.size(); ++i) {
    for (int j = 0; j < M[0].size(); ++j) {
      if (M[i][j] == 0) {
        zrows[i] = true;
	zcols[j] = true;
      }
    }
  }

  for (int i = 0; i < zrows.size(); ++i) {
    if (zrows[i]) zeroRow(M, i);
  }

    for (int i = 0; i < zcols.size(); ++i) {
      if (zcols[i]) zeroCol(M, i);
  }
}

void printMatrix(std::vector<std::vector<int>>& M) {
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
  std::cout << "Enter a matrix row by row (send EOF to end input): " << std::endl;
  std::vector<std::vector<int>> M = readMatrix(std::cin);
  std::cout << std::endl << "Zero Matrix: " << std::endl;
  zeroMatrix(M);
  printMatrix(M);
  return 0;
}


