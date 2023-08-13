//Kumar Ankit
#include<stdio.h>
#include<stdlib.h>

int fib(int n){//using recursion
    if(n==0 || n==1) return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    printf("Enter position of term to be printed from fibonacci series: ");
    int n;
    scanf("%d", &n);
    printf("Required answer is %d\n", fib(n));
    return 0;
}
