import java.util.*;
import java.io.*;
class Fibo
{
  int result_rec(int n)
  {
    if(n<2)
      return n;
    else
      return (result_rec(n-1) + result_rec(n-2));
  }
}

class fibonacci_recursion
{
  public static void main(String args[])
  {
    int n;
    Scanner sc = new Scanner(System.in);
    Fibo f=new Fibo();
    n=sc.nextInt();
    System.out.println("Element in Fibonacci series at position " + n + " using recursion= " + f.result_rec(n-1));
  }
}