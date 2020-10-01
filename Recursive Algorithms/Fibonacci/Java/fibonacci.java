import java.util.*;
import java.math.*;

class fibonacci
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        // Getting input from system.
        BigInteger n = new BigInteger(sc.nextLine(), 10);
        
        // Base cases
        if(n.toString(10).equals("0"))
        {
            System.out.println(0);
            return;
        }
        else if(n.toString(10).equals("1"))
        {
            System.out.println(1);
            return;
        }
        
        // Initialization of base numbers for n>=2
        BigInteger a = new BigInteger("0", 10);
        BigInteger b = new BigInteger("1", 10);
        BigInteger i = new BigInteger("2", 10);
        
        // main loop to get the nth fibonacci number
        while(i.compareTo(n) == -1 || i.compareTo(n) == 0)
        {
            BigInteger c = a.add(b);
            a = b;
            b = c;
            i = i.add(new BigInteger("1",10));
        }
        System.out.println(b.toString(10));
    }
}
