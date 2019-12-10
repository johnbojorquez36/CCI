#include <iostream>
#include <string>

/* The function we assume exists (my implementation) */
bool isSubstring(std::string str1, std::string str2) {
  return (str1.find(str2) != std::string::npos);
}

bool isRotation(std::string str1, std::string str2) {
  if (str1.size() != str2.size()) return false;
  
  int i = 0;
  /* Find a possible rotation point */
  for (int j = 0; j < str2.size(); ++j) {
    if (str2[j] == str1[i]) ++i;
    else i = 0;
  }

  return isSubstring(str2, str1.substr(i+1));
}

int main() {
  std::string str1;
  std::string str2;

  std::cout << "Enter the first string: ";
  std::cin >> str1;
  std::cout << "Enter the second string: ";
  std::cin >> str2;
  std::cout << "String 2 " << (isRotation(str1, str2) ? "is" : "is not") << " a rotation of string 1." << std::endl;
  return 0;
}
