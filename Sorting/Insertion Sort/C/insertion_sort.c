/* Insertion sort ascending order */
 
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, c, d, t;
 
  printf("Enter number of elements\n");
  do
  {
  scanf("%d", &n);
  }while(n > 101); // max = 100
  int *array = (int *)malloc(n * sizeof(int));
  printf("Enter %d integers\n", n);
 
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);
 
  for (c = 1 ; c <= n - 1; c++) {
    d = c;
 
    while ( d > 0 && array[d-1] > array[d]) {
      t          = array[d];
      array[d]   = array[d-1];
      array[d-1] = t;
 
      d--;
    }
  }
 
  printf("Sorted list in ascending order:\n");
 
  for (c = 0; c <= n - 1; c++) {
    printf("%d\n", array[c]);
  }
 
  return 0;
}