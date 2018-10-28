import java.util.Scanner;
class Fibonacci {

	public static void main(String args[]) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter Number of Fibonacci Terms");
    int n = in.nextInt();
    int first = 0;
    int second = 0;
    int third;
    System.out.println("Fibonnaci Terms are :");
    System.out.println(first);
    System.out.println(second);
    for(int i = 2 ;i <= n ; i++) {
      third = first + second;
      System.out.println(third);
      first = second;
      second = third;
    }
  }
}
