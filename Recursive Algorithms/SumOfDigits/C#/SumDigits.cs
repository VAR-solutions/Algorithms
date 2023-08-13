using System;

public class SumDigits
    {
        private static int sumOfDigits(int n)      // Recursive Function to calculate sum Of Digits of a number
        {
            if (n == 0) return 0;

            return n % 10 + sumOfDigits(n / 10);
        }
        public static void Main(string[] args)
        {
            int n;      //the number whose next power is to be calculated

            Console.Write("Enter the number whose sum of digits is to be calculated:");
            n = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine(sumOfDigits(n));
        }
    }
