import java.util.*;

public class Rotation {

    /* The function we assume exists (my implementation) */
    public boolean isSubstring(String str1, String str2) {
	return (str1.contains(str2));
    }

    public boolean isRotation(String str1, String str2) {
	if (str1.length() != str2.length()) return false;
  
	int i = 0;
	/* Find a possible rotation point */
	for (int j = 0; j < str2.length(); ++j) {
	    if (str2.charAt(j) == str1.charAt(i)) ++i;
	    else i = 0;
	}

	return isSubstring(str2, str1.substring(i+1));
    }

    public static void main(String[] args) {
	Scanner in = new Scanner(System.in);
	System.out.print("Enter the first string: ");
	String str1 = in.next();
	System.out.print("Enter the second string: ");
	String str2 = in.next();
	System.out.println("String 2 " + ((new Rotation()).isRotation(str1, str2) ? "is" : "is not")
			   + " a rotation of string 1.");
    }
}
