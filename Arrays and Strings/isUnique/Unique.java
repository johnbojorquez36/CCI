import java.util.*;

class Unique {

    public boolean isUnique(String str) {
	HashSet<Character> mem = new HashSet<Character>();
	for (int i = 0; i < str.length(); ++i)
	    if (!mem.add(str.charAt(i))) return false;
	return true;
    }

    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	System.out.print("Enter a string: ");
	String str = sc.next();
	Unique unq = new Unique();
	
	if (unq.isUnique(str))
	    System.out.println("The string is unique");
	else
	    System.out.println("the string is not unique");
    }
}
