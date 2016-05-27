import java.util.*;
import java.io.*;

public class Rotate {

    public boolean rotate(int[][] M) {
	if (M.length == 0 || M[0].length != M.length) return false;

	for (int track = 0; track < M.length / 2; ++track) {
	    int begin = track;
	    int end = M.length - begin - 1;
	    for (int i = begin; i < end; ++i) {
		int diff = i - begin;
		int temp = M[track][i];
		M[track][i] = M[end - diff][begin];
		M[end - diff][begin] = M[end][end - diff];
		M[end][end - diff] = M[i][end];
		M[i][end] = temp;
	    }
	}

	return true;
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
	System.out.println("Enter an N x N matrix row by row (send EOF to end input): ");
	int[][] M = readMatrix(System.in);
	System.out.println("\nRotated:");
	if ((new Rotate()).rotate(M)) {
	    printMatrix(M);
	} else {
	    System.out.println("Invalid matrix dimensions.");
	}
    }
}
