using System;

static class Program
{
    public static void Main()
    {
        int origNum, num, rem, sum = 0;

        Console.Write("Enter a positive integer: ");
        origNum = int.Parse(Console.ReadLine());
        num = origNum;

        while(num != 0)
        {
            rem = num % 10;
            sum += rem * rem * rem;
            num /= 10;
        }

        if (sum == origNum)
            Console.WriteLine($"{origNum} is an Armstrong number.");
        else
            Console.WriteLine($"{origNum} is not an Armstrong number.");
    }
}