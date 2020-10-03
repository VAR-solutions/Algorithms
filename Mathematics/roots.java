import java.io.*;
import java.util.*;

class Quadsol
{
  double x1,x2;

  void calc(int a,int b, int c)
  {
    int d= b*b - (4*a*c);
    if(d<0)
      System.out.println("No Real Solutions");
    else
    {
      x1= (-b + Math.sqrt(d))/2*a;
      x2= (-b - Math.sqrt(d))/2*a;
      display();
    }
  }

  void display()
  {
    System.out.println("Solutions: x1= " + x1 + ", x2= " + x2);
  }
}

class myclass
{
  public static void main(String args[])
  {
    int a, b, c;
    Quadsol q= new Quadsol();
    Scanner sc= new Scanner(System.in);
    System.out.println("Enter a: ");
    a= sc.nextInt();
    System.out.println("Enter b: ");
    b= sc.nextInt();
    System.out.println("Enter c: ");
    c= sc.nextInt();
    q.calc(a,b,c);
  }
}