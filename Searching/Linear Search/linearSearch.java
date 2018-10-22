import java.util.*;
import java.io.*;

public class linearSearch {

	public static void main(String args[]) {
		int[] arr = new int[100];
		int n,element;
		Scanner s = new Scanner(System.in);
		System.out.println("Enter size of array");
		n = s.nextInt();
		System.out.println("Enter elements of array");
		for(int i=0;i<n;i++) {
			arr[i] = s.nextInt();
		}
		
		System.out.println("Enter element to be found.");
		element = s.nextInt();

		for(int i=0;i<n;i++) {
			if(arr[i]==element)
				System.out.println("Element found at "+(i+1));
		}

	}
}
