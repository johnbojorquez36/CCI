import java.util.*;

class Permutation {

    public static boolean permuation(String a, String b) {
	if (a.length() != b.length()) return false;
	HashMap<Character, Integer> counts = new HashMap<Character, Integer>();
	    
	char[] achars = a.toCharArray();
	char[] bchars = b.toCharArray();

	for (char c : achars) {
	    if (counts.get(c) == null)
		counts.put(c, 1);
	    else
		counts.put(c, counts.get(c) + 1);
	}
	for (char c : bchars) {
	    if (counts.get(c) == null) return false;
	    counts.put(c, counts.get(c) - 1);
	    if (counts.get(c) < 0) return false;
	}

	return true;

    }

    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	System.out.print("Enter a string: ");
	String a = sc.next();
	System.out.print("Enter another string: ");
	String b = sc.next();
	if (permuation(a, b))
	    System.out.println("The strings are permuations of each other");
	else
	    System.out.println("The strings are not permutations of each other");
		
    }

}
