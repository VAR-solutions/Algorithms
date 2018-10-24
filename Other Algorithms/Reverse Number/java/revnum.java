import java.util.*;
import java.io.*;

public class revnum {
	public static void main(String args[]) {
		int num,rev,digit,n;
		rev = 0;
		Scanner inp = new Scanner(System.in);
		System.out.println("Enter number: ");
		n = inp.nextInt();
		num = n;
		do {
			digit = num%10;
			rev = (rev*10)+digit;
			num = num/10;
		} while(num!=0);

		System.out.println("Reverse of "+n+" is "+rev);
	}
}
