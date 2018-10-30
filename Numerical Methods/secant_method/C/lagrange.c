#include<stdio.h>
#include<conio.h>
#define MaxN 90
 
void main()
{
 float arr_x[MaxN+1], arr_y[MaxN+1], numerator, denominator, x, y=0;
 int i, j, n;
 clrscr();
 printf("Enter the value of n: \n");
 scanf("%d", &n);
 printf("Enter the values of x and y: \n");
 for(i=0; i<=n; i++)
  scanf("%f%f", &arr_x[i], &arr_y[i]);
 printf("Enter the value of x at which value of y is to be calculated: ");
 scanf("%f", &x);
 for (i=0; i<=n; i++)
 {
  numerator=1;
  denominator=1;
  for (j=0; j<=n; j++)
   if(j!=i)
   {
    numerator *= x-arr_x[j];
    denominator *= arr_x[i]-arr_x[j];
   }
  y+=(numerator/denominator)*arr_y[i];
 }
 printf("When x=%4.1f y=%7.1f\n",x,y);
 getch();
}