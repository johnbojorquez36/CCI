#include <iostream>
#include <vector>

bool isValidPlacement(std::vector<int>& board, int row, int col) {
  for (int j = 0; j < col; ++j) {
    int existingRow = board[j];

    if (existingRow == row) return false;

    int rowDiff = abs(row - existingRow);
    int colDiff = col - j;
    if (rowDiff == colDiff) return false;
  }
	
  return true;
}

void enumerateEightQueens(int col, std::vector<int>& board, std::vector<std::vector<int> >& solution) {
  if (col == board.size()) {
    solution.push_back(board);
  }
	
  for (int i = 0; i < board.size(); ++i) {
    /* Check if we can place a queen */
    if (isValidPlacement(board, i, col)) {
      board[col] = i; // Place the queen at row i
      enumerateEightQueens(col + 1, board, solution);
    }
  }
}

int main() {
  std::vector<std::vector<int> > solutions;
  std::vector<int> board(8);
  enumerateEightQueens(0, board, solutions);
  for (std::vector<int> board : solutions) {
    for (int x : board) std::cout << x << " ";
    std::cout << std::endl;
  }
  return 0;
}
