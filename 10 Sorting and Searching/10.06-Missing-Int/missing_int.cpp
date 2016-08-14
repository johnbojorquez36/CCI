#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

/* Constraint: 4 billion non-negative ints, with 1 GB of memory */
int findMissing(istream& in) {
  size_t numBits = (size_t) INT_MAX + 1;
  vector<int> bitMap(ceil(numBits/32), 0);
  int x;
  while (in >> x) {
    bitMap[x / 32] |= 1 << (x % 32); // Set the xth bit
  }

  for (int i = 0; i < bitMap.size(); ++i) {
    for (int j = 0; j < 32; ++j) {
      if (bitMap[i] & (1 << j) == 0) {
	return i * 32 + j;
      }
    }
  }
  return -1;
}

vector<int> getRangeCounts(istream& in, int blockSize, int numBlocks) {
  vector<int> rangeCounts(numBlocks, 0);
  int x;
  while (in >> x) {
    rangeCounts[x / blockSize]++;
  }
  return rangeCounts;
}



int findMissingInRange(istream& in, int min, int max) {
  size_t numBits = (size_t) max - min + 1;
  vector<int> bitMap(ceil(numBits/32), 0);
  int x;
  while (in >> x) {
    if (x >= min && x <= max)
      bitMap[x / 32] |= 1 << (x % 32); // Set the xth bit
  }

  for (int i = 0; i < bitMap.size(); ++i) {
    for (int j = 0; j < 32; ++j) {
      if (bitMap[i] & (1 << j) == 0) {
	return i * 32 + j;
      }
    }
  }
  return -1;
}

/* Constraints: 1 billion non-negative ints with 10 MB of memory */
int findMissing2(istream& in) {
  int rangeSize = (1 << 20);
  int numBlocks = INT_MAX / rangeSize + 1;

  vector<int> rangeCounts = getRangeCounts(in, rangeSize, 
					   numBlocks);
  int blockIndex = -1;
  for (int i = 0; i < rangeCounts.size(); ++i) {
    if (rangeCounts[i] < rangeSize) {
      blockIndex = i;
      break;
    }
  }

  if (blockIndex < 0) return -1;
	
  int min = blockIndex * rangeSize;
  int max = min + rangeSize - 1;
  int missingIndex = findMissingInRange(in, min, max);
  return min + missingIndex;
}
