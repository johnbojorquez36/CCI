import java.util.*;

public class OneAway {

    public boolean isOneAway(String a, String b) {

	if (Math.abs(a.length() - b.length()) > 1) return false;

	int i = 0, j = 0;
	boolean editMade = false;

	while (i != a.length() && j != b.length()) {
	    if (a.charAt(i) != b.charAt(j)) {
		if (editMade) return false;
		if (a.length() > b.length()) ++i;
		else if (a.length() < b.length()) ++j;
		else {
		    ++i;
		    ++j;
		}
		editMade = true;
	    } else {
		++i;
		++j;
	    }
	}

	return true;
    }

    public static void main(String[] args) {
	String str1, str2;
	Scanner in = new Scanner(System.in);
	System.out.println("Enter a string: ");
	str1 = in.next();
	System.out.println("Enter another string: ");
	str2 = in.next();
	in.close();

	OneAway oneaway = new OneAway();
	System.out.println("The strings " + (oneaway.isOneAway(str1, str2) ?
					     "are" : "are not") + " one away.");
    }
}
