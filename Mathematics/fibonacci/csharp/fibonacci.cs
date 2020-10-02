using System;

static class Program
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int a = 0;
        int b = 1;

        if(n == 0)
        {
            Console.WriteLine(a);
            return;
        }

        for (int i = 2; i <= n; i++)
        {
            int c = a + b;
            a = b;
            b = c;
        }

        Console.WriteLine(b);
    }
}