import java.io.*;
import java.util.*;

class FibForAnyN
{
	public static void main(String[] args)throws Exception
	{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		PrintWriter w=new PrintWriter(System.out);
		int n=Integer.parseInt(in.readLine());
		int[] fib=new int[n+1];
		fib[0]=0;
		fib[1]=1;
		fib[2]=1;
		for(int i=3;i<=n;i++)
		{
			fib[i]=fib[i-1]+fib[i-2];
		}
		w.println(fib[n]);
		w.close();
	}
}
