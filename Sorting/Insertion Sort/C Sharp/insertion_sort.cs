// Insertion Sort in C#

using System;

namespace InsertionSort
{
  class Program
  {
    public static void InsertionSort(int[] array)
    {
      int key;
      for (int i = 0; i < array.Length; i++)
      {
        key = array[i];                     //set current element as key
        int j = i - 1;
        while (j >= 0 && key < array[j])    //compare key with previous elements until previous element is greater than key
        {
          array[j + 1] = array[j];
          j--;
        }
        array[j + 1] = key;                 //set key to its position
      }
    }

    static void Main(string[] args)
    {
      int n;

      // get size of array
      Console.Write("Enter length of array:");
      n = Convert.ToInt32(Console.ReadLine());

      // get array
      int[] array = new int[n];
      Console.Write("Enter array:");
      for (int i = 0; i < n; i++)
      {
        array[i] = Convert.ToInt32(Console.ReadLine());
      }

      InsertionSort(array);

      // output sorted array
      Console.Write("Sorted array:");
      foreach (int value in array)
        Console.Write(" {0}", value);
      Console.Write("\n");
    }
  }
}