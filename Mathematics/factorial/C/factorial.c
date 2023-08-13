#include <stdio.h>

long long factorial(int n){
    if (n <= 1){
       return 1;
    }
    return n * factorial(n - 1);
}

int main(){
    printf("Enter an integer (<= 20) to find its factorial\n");
    int n;
    scanf("%d", &n);
    if(n < 0){
      printf("Factorial of negative integers is not defined.\n");
    }else{
      printf("Result: %lld\n", factorial(n));
    }
}
