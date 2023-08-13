/* 
 * Selection Sort implementation in C#;
 * Author : Shreyansh Anchlia;
 * Input : Array elements;
 * Output : Sorted array elements;
*/

using System;

namespace SelectionSort
{
	class Program
	{
		static void Main(string[] args)
		{
			int[] array = { 3, 2, 6, 7, 1, 5, 8, 4, 9, 0 };

			Console.WriteLine("Before: ");
			PrintArray(array);

			SelectionSort(array);

			Console.WriteLine("\n\nAfter: ");
			PrintArray(array);

			Console.WriteLine("\n\nPress any key to exit.");
			Console.ReadKey();
		}

		public static void SelectionSort(int[] array)
		{
			for (int i = 0; i < array.Length - 1; i++)
			{
				int smallestNumber = i;
				for (int j = i + 1; j < array.Length; j++)
				{
					if (array[j] < array[smallestNumber])
					{
						smallestNumber = j;
					}
				}
				if (i != smallestNumber)	//to avoid swapping with itself
				{
					//swapping with the smallest nummber
					int temp = array[i];
					array[i] = array[smallestNumber];
					array[smallestNumber] = temp;
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