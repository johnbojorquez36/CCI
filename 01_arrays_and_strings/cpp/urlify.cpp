#include <iostream>
#include <string>

void urlify(std::string &str, int length) {
  int numSpaces = 0;

  /* Count the number of spaces */
  for (int i = 0; i < length; ++i) {
    if (str[i] == ' ') ++numSpaces;
  }

  /* Start copying from the end of the actual string */
  int srcIndex = length - 1;
  /* Copy to the last index of the padded string */
  int destIndex = length + numSpaces * 2 - 1;

  while (srcIndex >= 0) {
    /* For each space, put a '%20' */
    if (str[srcIndex] == ' ') {
      str[destIndex--] = '0';
      str[destIndex--] = '2';
      str[destIndex] = '%';
    } else {
      str[destIndex] = str[srcIndex];
    }
    srcIndex--;
    destIndex--;
  }
}

void padWithSpaces(std::string& str) {
  int len = str.size();

  for (int i = 0; i < len; ++i) {
    if (str[i] == ' ') str += "  ";
  }
}

int main(int argc, char** argv) {
  std::string str;
  std::cout << "Enter a string to URLify: " << std::endl;
  std::getline(std::cin, str);

  int trueLength = str.size();
  padWithSpaces(str);
  
  urlify(str, trueLength);
  std::cout << str << std::endl;
  
  return 0;
}

