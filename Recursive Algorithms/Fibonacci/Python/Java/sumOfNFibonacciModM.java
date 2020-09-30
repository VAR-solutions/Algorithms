import java.util.*;
import java.math.*;

class sumOfNFibonacciModM
{
    public static void main(String[] args)
    {
        Scanner sc =new Scanner(System.in);
        long m = sc.nextLong();
        long n = sc.nextLong();
        long a=0;
        long b=1;
        long sum = 0;
        n = (n+2)%60;
        m = (m+1)%60;
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
        sum = b;
        a = 0;
        b = 1;
        i = 0;
        while(i<m-1)
        {
            long c = (a+b)%10;
            a = b;
            b = c;
            ++i;
        }
        sum = sum - b;
        if(sum<0)
            sum+=10;
        System.out.println(sum%10);
    }
}
