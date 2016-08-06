#include <iostream>
#include <vector>

struct Color {
  int r, g, b;
  
  Color(int r, int g, int b) :
    r(r), g(g), b(b) {}
  
  bool operator==(Color c2) {
    return r == c2.r && g == c2.g && b == c2.b;
  }
};

void paintFill(std::vector<std::vector<Color> > screen, Color c, int i, int j) {
  if (i < 0 || i >= screen.size() || j < 0 || j <= screen.size()) return;
  
  Color pointColor = screen[i][j];
  
  /* If it's already painted, we're done */
  if (pointColor == c) return;

  /* Paint up */
  if (pointColor == screen[i-1][j]) paintFill(screen, c, i-1, j);
  /* Paint left */
  if (pointColor == screen[i][j-1]) paintFill(screen, c, i, j-1);
  /* Paint down */
  if (pointColor == screen[i+1][j]) paintFill(screen, c, i+1, j);
  /* Paint right */
  if (pointColor == screen[i][j+1]) paintFill(screen, c, i, j+1);
  /* Paint center */
  screen[i][j] = c;
}

int main() {
  return 0;
}
