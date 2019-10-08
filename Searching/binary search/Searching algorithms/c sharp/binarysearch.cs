using System;
using System.Text;

namespace SearchingAlgorithms
{
    class Program
    {
        private static int LinearSearch(int[] array, int x)
        {
            int i = 0;
            while (i < array.Length && array[i] != x)
                i = i + 1;
            if (i < array.Length)
                return i;
            else
                return -1;
        }

        private static int BinarySearch(int[] array, int x)
        {
            int med=0, inf, sup;
            if(array[array.Length-1] > array[0])
            {
                inf = array[0];
                sup = array[array.Length - 1];
            }else
            {
                inf = array[array.Length - 1];
                sup = array[0];
            }

            bool enc = false;
            while ((inf < sup) && (!enc))
            {
                med = (inf + sup) / 2;
                if (array[med] == x)
                    enc = true;
                else if (array[med] < x)
                    inf = med + 1;
                else
                    sup = med - 1;
            }
            if (enc)
                return med;
            else
                return -1;
        }

        static void Main(string[] args)
        {
            //Given a sorted array
            var array = new int[] { 0,1,2,3,4,5,6,7,8,9 };


            Console.WriteLine("Press any key...");
            Console.ReadKey();
        }
    }
}
