#include<stdio.h>

int greatCommonDiv(int a, int b){ //used euclidian method to calculate gcd of two numbers
  if(b==0){
    return a;
  }
  return(greatCommonDiv(b , a%b));
}
int main(int argc, char const *argv[]) {

int result=greatCommonDiv(35,45);

printf("Greatest divider is: %d\n",result);
  return 0;
}
