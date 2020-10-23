/*
  program to count all possible paths in a matrix
*/

import java.io.*;

public class NumberOfPath {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(read.readLine());  //read test case
		while(T--> 0) {
			String s = read.readLine(); //read size of matrix (i.e 2 3)
			String[] str = s.split(" ");
			int m = Integer.parseInt(str[0]);
			int n = Integer.parseInt(str[1]);
			System.out.println(countPath(m,n));
		}

	}

	private static int countPath(int m, int n) {
		if (m==1 || n==1) {
			return 1;
		}
		return countPath(m-1, n)+countPath(m, n-1);
	}

}
