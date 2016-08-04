#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>

/********** Recursive approach ************/
bool findPath(std::vector<std::vector<char> >& grid, int row, int col, std::list<char>& path) {
  if (row == grid.size()-1 && col == grid[row].size()-1) return true;
  if (row >= grid.size() || col >= grid[row].size()) return false;
  if (grid[row][col] == 'W') return false;
  bool pathDown, pathRight;
  if (pathDown = findPath(grid, row+1, col, path)) path.push_front('D');
  else if (pathRight = findPath(grid, row, col+1, path)) path.push_front('R');
  return pathDown || pathRight;
}

std::list<char> findPath(std::vector<std::vector<char> >& grid) {
  std::list<char> path;
  findPath(grid, 0, 0, path);
  return path;
}

std::vector<std::vector<char> > makeGrid(int n, int m) {
  return std::vector<std::vector<char> >(n, std::vector<char>(m, 'O'));
}

/********** Top-down dynamic programming approach ************/
bool findPathDP(std::vector<std::vector<char> >& grid, int row, int col, std::list<char>& path, std::vector<std::vector<int> >& isPath) {
  if (row == grid.size()-1 && col == grid[row].size()-1) return true;
  if (row >= grid.size() || col >= grid[row].size()) return false;
  if (grid[row][col] == 'W') return false;

  if (isPath[row][col] >= 0) {
    return isPath[row][col];
  }
  
  if (isPath[row][col] = findPath(grid, row+1, col, path) == 1) path.push_front('D');
  else if (isPath[row][col] = findPath(grid, row, col+1, path) == 1) path.push_front('R');
  return isPath[row][col] == 1;
}

std::list<char> findPathDP(std::vector<std::vector<char> >& grid) {
  std::list<char> path;
  std::vector<std::vector<int> > isPath(grid.size(), std::vector<int>(grid[0].size(), -1)); // -1: Unvisited, 0: False, 1: True
  findPathDP(grid, 0, 0, path, isPath);
  return path;
}

void printGrid(std::vector<std::vector<char> >& grid) {
  for (std::vector<char> row : grid) {
    for (char cell : row) {
      std::cout << cell << " ";
    }
    std::cout << std::endl;
  }
}

void insertWall(std::vector<std::vector<char> >& grid, int i, int j) {
  if (i < 0 || j < 0) return;
  if (i >= grid.size() || j >= grid[i].size()) return;
  grid[i][j] = 'W';
}

int main() {
  std::cout << "=====================================" << std::endl
	    << "= Welcome to the robot path finder! =" << std::endl
	    << "=====================================" << std::endl
	    << "Enter the dimensions of your grid: ";
  int n, m;
  std::cin >> n >> m;
  std::cin.get();
  if (n <= 0 || m <= 0) {
    std::cout << "Invalid grid dimensions. Exiting" << std::endl;
    return -1;
  }
  std::vector<std::vector<char> > grid = makeGrid(n, m);
  std::cout << std::endl << "Here is your grid:" << std::endl << std::endl;
  printGrid(grid);
  std::cout << std::endl << "Time to enter the locations of your walls."
	    << " Type 'done' when you're done." << std::endl;
  std::string input = "";
  while (std::cin) {
    std::cout << "Wall location: ";
    getline(std::cin, input);
    if (input.compare("done") == 0) break;
    std::stringstream ss(input);
    int i, j;
    ss >> i >> j;
    insertWall(grid, i, j);
  }
  
  std::cout << std::endl << "Grid with walls:" << std::endl;
  printGrid(grid);

  std::cout << std::endl << "Path of robot: " << std::endl;
  std::list<char> path = findPathDP(grid);
  if (path.empty()) std::cout << "No path." << std::endl;
  else {
    for (char dir : path) std::cout << dir << " ";
    std::cout << std::endl;
  }
  return 0;
}
