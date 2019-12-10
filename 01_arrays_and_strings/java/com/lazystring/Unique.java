package com.lazystring;

import java.util.HashSet;

class Unique {
	public static boolean isUnique(String str) {
		HashSet<Character> seen_characters = new HashSet<>();
		for (char c : str.toCharArray()) {
			if (!seen_characters.add(c)) {
				return false;
			}
		}

		return true;
    }
}
