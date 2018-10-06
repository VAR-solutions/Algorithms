import java.util.*;
import java.io.*;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int a = 0;
    int b = 1;
    if(n==0) {
      System.out.println(a);
      return;
    }
    for(int i = 2; i<=n; i++) {
      int c = a+b;
      a = b;
      b = c;
    }
    System.out.println(b);
  }
}
