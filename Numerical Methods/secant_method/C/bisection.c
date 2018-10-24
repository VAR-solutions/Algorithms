#include<stdio.h>
#include <math.h>

//#define ESP 0.001
//#define F(x) (x)*(x)*(x) + (x)*(x) + (x) + 7
double F(float x)
{
return ((x*x*x)-x-1);

}
void main()
{
  int i = 1;
  float x0,x1,x2;
  double f1,f2,f0,t;

  printf("\nEnter the value of x0: ");
  scanf("%f",&x0);

  printf("\nEnter the value of x1: ");
  scanf("%f",&x1);

  printf("\niteration\t x0\t       x1\t x2\t   f0\t   f1\t   f2");
  do{

  x2=(x0+x1)/2;
 /* f0=F(x0);
  f1=F(x1);
  f2=F(x2);*/
  printf("\n%d %f %f %f %lf %lf %lf", i, x0,x1,x2,F(x0),F(x1),F(x2));
  if(F(x0)*F(x2)<0)
   {
    x1=x2;
   }
   else
   {
    x0=x2;
   }
   i++;
  }while(fabs(F(x2))>0.001);

printf("\n\nApp.root = %f",x2);

}
