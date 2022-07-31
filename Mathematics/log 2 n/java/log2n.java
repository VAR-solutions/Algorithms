import java.util.Scanner;
public class log2n
{
  public static void main(String args[])
  {
    Scanner input = new Scanner(System.in);
    double x = input.nextDouble();
    System.out.println(log(x));
  }
  
  public static int log(double d)
  {
    if(d < 2.0)
      return 0.0;
    else
    {
      1 + log(d/2.0);
    }
  }
}
