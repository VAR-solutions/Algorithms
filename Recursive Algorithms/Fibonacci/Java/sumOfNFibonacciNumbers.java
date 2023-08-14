import java.util.*;
import java.math.*;

class sumOfNFibonacciNumbers
{
    public static int getFrequency(int m)
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
        int exp = getFrequency(10);
        long a=0;
        long b=1;
        n = (n+2)%exp;
        if(n <= 1)
        {
            System.out.println(n-1);
            return;
        }
        long i=0;
        while(i<n-1)
        {
            long c = (a+b)%10;
            a = b;
            b = c;
            ++i;
        }
        b = b-1;
        if(b<0)
            b+=10;
        System.out.println(b%10);
    }
}
