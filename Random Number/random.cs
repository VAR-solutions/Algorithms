using System;

namespace RandomNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            Random random = new Random();

            // Generate Random Number
            int num = random.Next();

            // Generate Number < 1000
            int numLess1000 = random.Next(1000);

            // Generate Number between a MIN & MAX Value
            int numMinMax = random.Next(10, 99);

            Console.WriteLine($" Random Number: {num} \n Less than 1000: {numLess1000} \n Min Max: {numMinMax} ");

            Console.ReadLine();
        }
    }
}
