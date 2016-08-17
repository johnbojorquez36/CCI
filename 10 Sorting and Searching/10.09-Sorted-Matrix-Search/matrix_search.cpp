#include <algorithm>
#include <vector>

struct Cell {
  int row;
  int col;

  Cell(int r, int c) :
    row(r), col(c) {}
	
  bool within(std::vector<std::vector<int>>& matrix) {
    return row >= 0 && col >= 0 && row < matrix.size()
					 && col < matrix[0].size();
  }

  bool operator<(Cell& c) {
    return row <= c.row && col <= c.col;
  }
};

Cell findElement(std::vector<std::vector<int>>&, Cell, Cell, int);

Cell average(Cell c1, Cell c2) {
  return Cell((c1.row + c2.row) / 2, (c1.col + c2.col) / 2);
}

Cell partitionFind(std::vector<std::vector<int>>& matrix, Cell topLeft, Cell 
		   bottomRight, Cell pivot, int target) {
  Cell lowerLeftBegin(pivot.row, topLeft.col);
  Cell lowerLeftEnd(bottomRight.row, pivot.col - 1);
  Cell upperRightBegin(topLeft.row, pivot.col);
  Cell upperRightEnd(pivot.row - 1, bottomRight.col);

  Cell resultLowerLeft = findElement(matrix, lowerLeftBegin, lowerLeftEnd, target);
  if (!resultLowerLeft.within(matrix)) {
    return findElement(matrix, upperRightBegin, upperRightEnd, target);
  }

  return resultLowerLeft;
}

Cell findElement(std::vector<std::vector<int>>& matrix, Cell topLeft, Cell bottomRight, int target) {
  if (!topLeft.within(matrix) || !bottomRight.within(matrix)) {
    return Cell(-1, -1);
  } else if (matrix[topLeft.row][topLeft.col] == target) {
    return topLeft;
  } else if (bottomRight < topLeft) {
    return Cell(-1, -1);
  }

  Cell start = topLeft;
  int dist = std::min(bottomRight.row - topLeft.row, bottomRight.col - topLeft.col);
  Cell end = Cell(start.row + dist, start.col + dist);

  while (start < end) {
    Cell mid = average(topLeft, bottomRight);
    if (target > matrix[mid.row][mid.col]) {
      start.row = mid.row + 1;
      start.col = mid.col + 1;
    } else {
      end.row = mid.row - 1;
      end.col = mid.col - 1;
    }
  }

  return partitionFind(matrix, topLeft, bottomRight, start, target);
}

Cell findElement(std::vector<std::vector<int>>& matrix, int x) {
  Cell begin(0, 0);
  Cell end(matrix.size() - 1, matrix[0].size() - 1);
  return findElement(matrix, begin, end, x);
}
