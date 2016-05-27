import java.util.*;
import java.io.*;

public class ZeroMatrix {

    public void zeroRow(int[][] M, int i) {
	for (int j = 0; j < M[i].length; ++j) {
	    M[i][j] = 0;
	}
    }

    public void zeroCol(int[][] M, int j) {
	for (int i = 0; i < M.length; ++i) {
	    M[i][j] = 0;
	}
    }

    public void zeroMatrix(int[][] M) {
	/* Keep track of which rows and columns have zeroes */
        boolean[] zrows = new boolean[M.length];
        boolean[] zcols = new boolean[M[0].length];

	for (int i = 0; i < M.length; ++i) {
	    for (int j = 0; j < M[0].length; ++j) {
		if (M[i][j] == 0) {
		    zrows[i] = true;
		    zcols[j] = true;
		}
	    }
	}

	for (int i = 0; i < zrows.length; ++i) {
	    if (zrows[i]) zeroRow(M, i);
	}

	for (int i = 0; i < zcols.length; ++i) {
	    if (zcols[i]) zeroCol(M, i);
	}
    }

    public static void printMatrix(int[][] M) {
	for (int[] v : M) {
	    for (int x : v) {
		System.out.print(x + " ");
	    }
	    System.out.println();
	}
    }

    public static int[][] readMatrix(InputStream stream) {
	Scanner in = new Scanner(stream);
	ArrayList<ArrayList<Integer>> rows = new ArrayList<ArrayList<Integer>>();
	while (in.hasNext()) {
	    ArrayList<Integer> row = new ArrayList<Integer>();
	    String line = in.nextLine();
	    for (String s : line.split("\\s+")) {
		row.add(Integer.parseInt(s));
	    }
	    rows.add(row);
	}

	int[][] M = new int[rows.size()][];
	int i = 0;
	for (ArrayList<Integer> row : rows) {
	    int[] data = new int[row.size()];
	    for (int j = 0; j < data.length; ++j) {
		data[j] = row.get(j);
	    }
	    M[i++] = data;
	}

	return M;
    }

    public static void main(String[] args) {
	System.out.println("Enter a matrix row by row (send EOF to end input): ");
	int[][] M = readMatrix(System.in);
	System.out.println("\nZero matrix:");
        (new ZeroMatrix()).zeroMatrix(M);
	printMatrix(M);
    }
}
