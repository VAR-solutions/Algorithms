/*Radix sort
A sorting technique that sorts the elements by first grouping the individual digits of the same place value.
Then, sort the elements according to their increasing/decreasing order.*/

#include <stdio.h>

int max(int num[], int n);

void radix_sort(int num[], int n);

int main()
{
   int i, n;
   printf("Enter the number of elements: ");
   scanf("%d", &n);
   int num[n];
   printf("Enter the numbers: ");
   for (i = 0; i < n; i++)
   {
      scanf("%d", &num[i]);
   }
   radix_sort(num, n);

   printf("\n The Sorted list is  : ");

   for (i = 0; i < n; i++)
      printf("%d ", num[i]);

   printf("\n");
   return 0;
}

int max(int num[], int n)
{
   int max = num[0];
   for (int i = 1; i < n; i++)
      if (num[i] > max)
         max = num[i];
   return max;
}

void radix_sort(int num[], int n)
{
   int box[10][10], box_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
   lar = max(num, n);
   while (lar > 0)
   {
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++)
   {
      for (i = 0; i < 10; i++)
      {
         box_cnt[i] = 0;
      }
      for (i = 0; i < n; i++)
      {
         r = (num[i] / divisor) % 10;
         box[r][box_cnt[r]] = num[i];
         box_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++)
      {
         for (j = 0; j < box_cnt[k]; j++)
         {
            num[i] = box[k][j];
            i++;
         }
      }
      divisor *= 10;
      printf("\tAfter Pass %d : ", pass + 1);
      for (i = 0; i < n; i++)
         printf("%d ", num[i]);
      printf("\n");
   }
}
