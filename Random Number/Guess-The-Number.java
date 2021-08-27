import java.util.*;

public class Program
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    
	    Random rand = new Random();
	    
	    int number = rand.nextInt(100);
	    
	    System.out.println("Enter A number between 1 to 100");
	    int input = sc.nextInt();
	    int count=1;
	    while(input!=number){
	        if(input>number)
	            System.out.println("Number Guess by You is Higher");
	        else
	            System.out.println("Number Guess by You is Smaller");
	       System.out.println("1.Continue\n2.Exit");
	       int choice=sc.nextInt();
	       switch(choice){
	           case 1:
	               input=sc.nextInt();
	               break;
	           case 2:
	               System.exit(0);
	       }
	       count++;
	    }
	    
	    System.out.println("Congratulation You Guess Number Correctly in "+count);
		
	}
}
