import java.util.*;
import java.io.*;
class Factorial {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    System.out.println("the factorial of this number is: " + factorial(n));
  }

  //a recursive function to calculate n!
  public int factorial(int n){
  	if(n==0)
		return 1;
	else
		return n*factorial(n-1);
  }
}

