import java.util.*;

class Multiple_of_eight
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int result=n;
		result=(result>>3)<<3;
		if(result==n)
		System.out.println("Multiple of 8");
		else
		System.out.println("Not a Multiple of 8");
	}
}
