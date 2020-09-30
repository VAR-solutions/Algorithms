// This code is the generalized form for fibonacci number: Question : find the nth Fibonacci number and find (fn)%m.

import java.util.*;
import java.math.*;

class sumOfNFibonacci
{

    // Finding the pisano series for number m.
    public static int getPisanoNumber(int m)
    {
        long a = 0;
        long b = 1;
        int i;
        for(i=0;i<m*m; ++i)
        {
            long c = (a+b)%m;
            a = b;
            b = c;
            if(a == 0 && b == 1)
            {
                break;
            }
        }
        return i+1;
    }

    
    public static void main(String[] args)
    {
        Scanner sc =new Scanner(System.in);
        long n = sc.nextLong();
        int m = sc.nextInt();
        int exp = getPisanoNumber(m); // Pisano number
        long a=0;
        long b=1;
        
        // Reducing the size of n i.e. optimizing the number n according to pisano number.
        n = n%exp;
        
        // finally finding the fibonacci number.
        if(n <= 1)
        {
            System.out.println(n);
            return;
        }
        long i=0;
        while(i<n-1)
        {
            long c = (a+b)%m;
            a = b;
            b = c;
            ++i;
        }
        System.out.println(b);
    }
}
