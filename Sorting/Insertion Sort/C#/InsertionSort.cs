using System;

namespace Algorithms
{
    class InsertionSort
    {
        static int[] Sort(int[] numbers)
        {
            for (int i = 0; i < numbers.Length - 1; i++)
            {
                for (int j = i + 1; j > 0; j--)
                {
                    if (numbers[j - 1] > numbers[j])
                    {
                        int temp = numbers[j - 1];
                        numbers[j - 1] = numbers[j];
                        numbers[j] = temp;
                    }
                }
            }
            return numbers;
        }

        static void Main(string[] args)
        {
            int[] numbers = { 1, 9, -4, 15, 79, 2, 4, -10 };
            numbers = Sort(numbers);

            foreach (var number in numbers)
            {
                Console.WriteLine(number);
            }
        }
    }
}
