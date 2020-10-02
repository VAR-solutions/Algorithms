using System;

static class Program
{
    double Harmonic(int a, int b)
    {
        return (double)(2 * a * b) / (a + b);
    }

    public static void Main()
    {
        int a, b;
        a = int.Parse(Console.ReadLine());
        b = int.Parse(Console.ReadLine());

        Console.WriteLine(Harmonic(a, b));
    }
}