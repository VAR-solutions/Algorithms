/*
Input : - n : number of units
	  m : number of coin types
	  m space seperated integers respective values of coin type

Output:- Lonf=g Integer denoting number of ways we can get a sum of n from given infinte supply of m coins
*/
import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int m=s.nextInt();
        int[] c=new int[m];
        for(int i=0;i<m;i++)
            c[i]=s.nextInt();
        Arrays.sort(c);
        long[] dp=new long[n+1];
        dp[0]=1;
        for(int i=1;i<n+1;i++)
            dp[i]=0;
        for(int i=0;i<m;i++)
            {
            for(int j=c[i];j<n+1;j++)
                {
                dp[j]=dp[j]+dp[j-c[i]];
            }
        }
        System.out.println(dp[n]);
    }/* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    
}
