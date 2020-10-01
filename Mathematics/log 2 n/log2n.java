import java.util.*;
import java.lang.*;
import java.io.*;
class log2n
{
	public static double log2(int n)
	{
		return Math.log(n) / Math.log(2);
	}
	public static void main (String[] args) throws Exception
	{
		Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
		System.out.println(log2(n));
	}
}
