import java.util.*;

public class PalPerm {

    public boolean isPalPerm(String str) {
	String lstr = str.toLowerCase();
	HashMap<Character, Integer> counts = new HashMap<Character, Integer>();
	int numChars = 0;

	for (int i = 0; i < lstr.length(); ++i) {
	    char c = lstr.charAt(i);
	    if (c != ' ')  {
		/* This is why I hate you Java */
		if (!counts.containsKey(c)) {
		    counts.put(c, 1);
		} else {
		    counts.put(c, counts.get(c) + 1);
		}
		++numChars;
	    }
	}

	boolean evenLength = numChars % 2 == 0;
	boolean oneOddCount = false;

	for (Map.Entry<Character, Integer> entry : counts.entrySet()) {
	    if (entry.getValue() % 2 != 0) {
		if (evenLength) return false;
	        else if (oneOddCount) return false;
		else oneOddCount = true;
	    }
	}

	return true;
    }

    public static void main(String[] args)  {
	System.out.println("Enter a string: ");
	Scanner in = new Scanner(System.in);

	PalPerm pal = new PalPerm();
	System.out.println("The string " + (pal.isPalPerm(in.nextLine()) ? "is" : "isn't") + " a permutation of a palindrome.");

	in.close();
    }
}
