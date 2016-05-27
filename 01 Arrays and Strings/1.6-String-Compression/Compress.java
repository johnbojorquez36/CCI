import java.util.*;

public class Compress  {

    public String compress(String str) {
	StringBuilder compressed = new StringBuilder();
	int count = 0;
	
	for (int i = 0; i < str.length(); ++i) {
	    ++count;
	    if  (i == str.length() - 1  || str.charAt(i) != str.charAt(i+1)) {
		compressed.append(str.charAt(i));
		compressed.append(count);
		count = 0;
	    }
	}

	String compstr = compressed.toString();
	return compstr.length() > str.length() ? str : compstr;
    }

    public static void main(String[] args) {
	Compress comp = new Compress();
	System.out.print("Enter a string to compress: ");
	Scanner in = new Scanner(System.in);
	System.out.println(comp.compress(in.next()));
	in.close();
    }
}
