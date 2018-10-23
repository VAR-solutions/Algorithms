import java.util.*;
import java.io.*;

public class palindrome {
	public static void main(String args[]) {
		int num,d,r,n;
		Scanner s = new Scanner(System.in);
		r=0;
		System.out.println("Enter a number: ");
		num = s.nextInt();
		n = num;
		do {
			d = num%10;
			r = (r*10) + d;
			num = num/10;
		} while(num!=0);

		System.out.println(n+"  "+r);

		if(n==r) 
			System.out.println("It is a palindrome");
		else
			System.out.println("It is not a palindrome");

	}
}
