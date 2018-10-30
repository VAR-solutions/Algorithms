#include <stdio.h>
void main()
{
  int num,rev=0,i,temp;
  printf("Enter the number you want to reverse\n");
  scanf("%d",&num);
  temp=num;
  while(num!=0)
    {
     i=num%10;
     rev=(rev*10)+i;
     num=num/10;
    }
  printf("Reverse of the number %d is %d",temp,rev);
}
