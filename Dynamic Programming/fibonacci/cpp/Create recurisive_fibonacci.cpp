
 #include<iostream>
 using namespace std;

 int fib[100000] = {0};
 int fibonacci(int n)
 {
    if (n == 0) return 0;
    if (fib[n])
       return fib[n];
   fib[n] = fibonacci(n-1) + fibonacci(n-2);
   return fib[n];
 }

 int main ()
 {
   fib[0] = 0;
   fib[1] = 1;
   int n = 9;
     cout<<fibonacci(n)<<'\n';
   return 0;
 }
