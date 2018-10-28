import java.util.Scanner;
public class reverse_number
{
  public static void main(String args[])
  {
    Scanner input = new Scanner(System.in);
    int num = input.nextInt();
    System.out.println(reverse(num));
  }
  
  public static String reverse(int x)
   {
      String s = x + ""; //convert it to string
      
      if(s.length() == 1) 
    	  return s;
      else
    	  return s.substring(s.length() - 1) + reverse(x / 10); 
   }
}
