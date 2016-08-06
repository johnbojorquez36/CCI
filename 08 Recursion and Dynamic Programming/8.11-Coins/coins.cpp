#include <iostream>
#include <vector>
#include <algorithm>

/* A simple DP approach */
int makeChangeDP(int n, std::vector<int> denoms) {
  std::vector<std::vector<int> > numWays(n+1, std::vector<int>(denoms.size(), 0));
  for (int i = 1; i < denoms.size(); ++i) numWays[0][i] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= denoms.size(); ++j) {
      int count = 0;
      int amountLeft = i - denoms[denoms.size() - j];
      if (amountLeft > 0) {
	/* Take ith coin, and don't move on */
	count += numWays[i - denoms[denoms.size() - j]][j];

	/* Take ith coin, and move on */
	count += numWays[i - denoms[denoms.size() - j]][j-1];
      } else if (amountLeft == 0) {
	count++;
      }
      
      /* Don't take ith coin, and move on */
      count += numWays[i][j-1];

      numWays[i][j] = count;
    } 
  }

  return numWays[n][denoms.size()];
}

/* Recursive approach */
int makeChange(int n, int i, std::vector<int> denoms) {
  if (n == 0 || n - denoms[i] == 0) return 1;
  if (i == denoms.size() || n < 0) return 0;
  int count = 0;

  /* Take ith coin, and don't move on */
  count += makeChange(n - denoms[i], i, denoms);

  /* Take ith coin, and move on */
  count += makeChange(n - denoms[i], i+1, denoms);

  /* Don't take ith coin, and move on */
  count += makeChange(n, i+1, denoms);

  return count;
}

int makeChange(int n, std::vector<int> denoms) {
  return makeChange(n, 0, denoms);
}

int main() {
  int n;
  std::cout << "Enter the amount you would like to make change with: ";
  std::cin >> n;

  int numWays = makeChangeDP(n, {1, 5, 10, 25});
  std::cout << "There " << (numWays == 1 ? "is " : "are ") << numWays 
	    << (numWays == 1 ? " way" : " ways") << " to make change." << std::endl;
  return 0;
}
