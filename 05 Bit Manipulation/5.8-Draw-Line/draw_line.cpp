#include <iostream>
#include <cstdint>
#include <vector>

typedef uint8_t ubyte;

void drawByte(ubyte& b, int i, int j) {
  int mask = ((1 << i + 1) - 1) & ~((1 << j) - 1);
  b |= mask;
}

void drawLine(std::vector<ubyte>& screen, int width, int x1, int x2, int y) {
  int startByte = width*y + x1/8;
  int endByte = width*y + x2/8;
  int startBit = x1 % 8;
  int endBit = x2 % 8;
  drawByte(screen[startByte], startBit, 8); // Fill in starting byte
  drawByte(screen[endByte], endBit, 8); // Fill in ending byte
  /* Fill all the bytes inbetween */
  for (int i = startByte+1; i < endByte - 1; ++i) {
    drawByte(screen[i], 0, 8);
  }
}

int main() {
  return 0;
}
