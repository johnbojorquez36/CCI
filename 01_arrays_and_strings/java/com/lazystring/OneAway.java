package com.lazystring;

import java.util.*;

public class OneAway {
  public static boolean isOneAway(String a, String b) {
    if (Math.abs(a.length() - b.length()) > 1) {
        return false;
    }

    int i = 0, j = 0;
    boolean editMade = false;

    while (i != a.length() && j != b.length()) {
      boolean charactersMatch = a.charAt(i) == b.charAt(j);
      if (!charactersMatch && editMade) {
        return false;
      }

      editMade |= !charactersMatch;
      if (charactersMatch || a.length() >= b.length()) {
        i++;
      }
      if (charactersMatch || a.length() <= b.length()) {
        j++;
      }
    }

    return true;
  }
}
