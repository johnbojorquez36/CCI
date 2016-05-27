import java.util.*;

public class URLify {

    public void urlify(char[] str, int length) {
	int numSpaces = 0;

	/* Count the number of spaces */
	for (int i = 0; i < length; ++i) {
	    if (str[i] == ' ') ++numSpaces;
	}

	/* Start copying from the end of the actual string */
	int srcIndex = length - 1;
	/* Copy to the last index of the padded string */
	int dstIndex = length + numSpaces * 2 - 1;

	while (srcIndex >= 0) {
	    /* For each space, put a '%20' */
	    if (str[srcIndex] == ' ') {
		str[dstIndex--] = '0';
		str[dstIndex--] = '2';
		str[dstIndex] = '%';
	    } else {
		str[dstIndex] = str[srcIndex];
	    }
	    --dstIndex;
	    --srcIndex;
	}
    }

    public static char[] toPaddedArray(String str) {
	int numSpaces = 0;

	for (int i = 0; i < str.length(); ++i) {
	    if (str.charAt(i) == ' ') {
		++numSpaces;
	    }
	}

	char[] pstr = new char[str.length() + numSpaces * 2];

	for (int i = 0; i < str.length(); ++i) {
	    pstr[i] = str.charAt(i);
	}

	return pstr;
    }
    
    public static void main(String[] args) {
	System.out.println("Enter a string to URLify: ");
	Scanner in = new Scanner(System.in);
	String str = in.nextLine();
	int trueLength = str.length();
	
	char[] paddedStr = toPaddedArray(str);

	URLify urlifier = new URLify();
	urlifier.urlify(paddedStr, trueLength);

	str = new String(paddedStr);
	System.out.println(str);

	in.close();
    }
}
