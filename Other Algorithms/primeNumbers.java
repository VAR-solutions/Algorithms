import java.util.*;
import java.io.*;

class Prime {
  int n;

  Prime()
  {
    n=0;
  }

  void input(int a)
  {
    n=a;
  }

  void check()
  {
    int flag, i, j;
    for (i=2; i<=n; i++)
    {
      flag=1;
      for (j=2; j<i; j++)
      {
        if(i%j == 0)
          {flag= 0;  break;}
      }
      if (flag==1)
        System.out.println(i + " ");
    }
  }
}

class MyClass {

    public static void main(String[] args) {

        Prime p=new Prime();
        int num = 0;
        Scanner sc= new Scanner(System.in);

        System.out.println("Enter number: ");
        num=sc.nextInt();
        p.input(num);
        System.out.println("\nList of Prime numbers:\n");
        p.check();
    }
}
