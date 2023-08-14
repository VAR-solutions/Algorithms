import java.util.*;
import java.math.*;

class sumOfSquaredFibonacciNumbers
{
    public static void main(String[] args)
    {
        Scanner sc =new Scanner(System.in);
        long n = sc.nextLong();
        long a=0;
        long b=1;
        n = (n)%60;
        if(n == 1)
        {
            System.out.println(1);
            return;
        }
        else if(n == 0)
        {
            System.out.println(0);
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
        long c = (a+b)%10;
        b = (b*c)%10;
        if(b<0)
            b+=10;
        System.out.println(b%10);
    }
}
