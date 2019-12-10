package com.lazystring;

import java.util.*;

public class URLify {
  public static void urlify(char[] str, int length) {
    int numSpaces = 0;
    for (int i = 0; i < length; ++i) {
        if (str[i] == ' ') ++numSpaces;
    }

    // Where to start copying characters *to*.
    int dstIndex = length + numSpaces * 2 - 1;

    // Process characters starting at the end of the string.
    for (int srcIndex = length - 1; srcIndex >= 0; srcIndex--) {
      char c = str[srcIndex];
      if (c == ' ') {
        str[dstIndex--] = '0';
        str[dstIndex--] = '2';
        str[dstIndex--] = '%';
      } else {
        str[dstIndex--] = c;
      }
    }
  }
}
