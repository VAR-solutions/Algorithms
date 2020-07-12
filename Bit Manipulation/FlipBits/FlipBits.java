//Counting the number of flipped bits to be flipped to covert A into B
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class FlipBits
{
	public static long countFlippedBits(long A,long B){
		long ans=A^B;
		long count=0;
		while(ans>0){
			count+=ans&1;
			ans>>=1;
		}
		return count;
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner scan=new Scanner(System.in);
		long A=scan.nextLong();
		long B=scan.nextLong();
		long ans=countFlippedBits(A,B);
		System.out.println(ans);
	}
}
