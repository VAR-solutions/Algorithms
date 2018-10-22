/*
Input :- No of test cases
	No of integers
	Integers separated by space

Output - Maximum Contiguous Subarray
*/

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int tc=s.nextInt();
        while(tc-->0)
            {
            int n=s.nextInt();
            int[] a=new int[n];
            for(int i=0;i<n;i++)
                a[i]=s.nextInt();
            int[] max=new int[n];
            int max1=a[0];
            max[0]=a[0];
            int ans=0;
            for(int i=1;i<n;i++)
                {
                    max[i]=Math.max(a[i],max[i-1]+a[i]);
                    if(max1<max[i])
                        max1=max[i];
                //System.out.println(max);
                }
            
            Arrays.sort(a);
            int ans1=0;
            if(a[n-1]<0)
                ans1=a[n-1];
            else
                {
                int i=n-1;
                while(i>=0&&a[i]>0)
                {ans1+=a[i];
                i--;
                }
            }
            System.out.println(max1+" "+ans1);
            }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}
