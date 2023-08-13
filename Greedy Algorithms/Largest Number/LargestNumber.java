import java.util.Scanner;


public class FormBigggestNumber {

	public static void main(String[] args) {

		Scanner scn = new Scanner(System.in);

		int tc = scn.nextInt();

		while (tc > 0) {
			
			int n = scn.nextInt();
			int[] arr = new int[n];

			for (int i = 0; i < arr.length; i++)
				arr[i] = scn.nextInt();

			bubbleSort(arr);

			for (int val : arr)
				System.out.print(val);

			System.out.println();

			tc--;
		}

	}

	public static void bubbleSort(int[] arr) {

		int n = arr.length;

		for (int count = 0; count <= n - 2; count++) {

			for (int j = 0; j <= n - count - 2; j++) {

				if (compare(arr[j], arr[j + 1])) {

					// swap
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}

		}

	}

	public static boolean compare(int n1, int n2) {

		String n1n2s = n1 + "" + n2;
		String n2n1s = n2 + "" + n1;

		int n1n2i = Integer.parseInt(n1n2s);
		int n2n1i = Integer.parseInt(n2n1s);

		if (n2n1i > n1n2i) {
			return true;
		} else {
			return false;
		}

	}

}
