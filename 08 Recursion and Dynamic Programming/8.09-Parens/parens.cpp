#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

std::unordered_set<std::string> parens(int n) {
  if (n == 1) return {"()"};
  std::unordered_set<std::string> parenCombos;
  for (std::string s : parens(n-1)) {
    for (int i = 0; i < s.size()-1; ++i) {
      if (s[i] == '(') {
	std::string scp(s);
	scp.insert(i+1, "()");
	parenCombos.insert(scp);
      }
    }
    parenCombos.insert("()" + s);
  }
  return parenCombos;
}

/* More efficient version */
void parens2(int i, int leftParens, int rightParens, std::string parenStr, std::vector<std::string>& combos) {
  if (i == parenStr.size()) {
    combos.push_back(parenStr);
    return;
  }

  if (leftParens < rightParens && rightParens > 0) {
    parenStr[i] = ')';
    parens2(i+1, leftParens, rightParens-1, parenStr, combos);
  }
  
  if (leftParens > 0) {
    parenStr[i] = '(';
    parens2(i+1, leftParens-1, rightParens, parenStr, combos);
  }
}

std::vector<std::string> parens2(int n) {
  std::vector<std::string> combos;
  parens2(0, n, n, std::string(n*2, ' '), combos);
  return combos;
}

int main() {
  int n;
  std::cout << "Enter a positive integer n: ";
  std::cin >> n;
  std::vector<std::string> parenCombos = parens2(n);
  for (std::string s : parenCombos) std::cout << s << ", ";
  std::cout << "\b\b " << std::endl;
}
