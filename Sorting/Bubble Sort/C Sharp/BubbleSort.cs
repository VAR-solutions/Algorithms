/* 
 * Bubble Sort implementation in C#;
 * Author : Lucas Madeira;
 * Input : Array elements;
 * Output : Sorted array elements;
*/

using System;

namespace BubbleSort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = { 3, 2, 6, 7, 1, 5, 8, 4, 9, 0 };

            Console.WriteLine("Before: ");
            PrintArray(array);

            BubbleSort(array);

            Console.WriteLine("\n\nAfter: ");
            PrintArray(array);

            Console.WriteLine("\n\nPress any key to exit.");
            Console.ReadKey();
        }

        public static void BubbleSort(int[] array)
        {
            for (int i = 0; i < array.Length - 1; i++)
            {
                for (int j = 0; j < array.Length - (i + 1); j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        int aux = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = aux;
                    }
                }
            }
        }

        public static void PrintArray(int[] array)
        {
            foreach (int value in array)
                Console.Write(" {0}", value);
        }
    }
}
