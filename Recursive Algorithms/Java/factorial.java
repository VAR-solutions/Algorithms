import java.util.Scanner;


public class Factorial {
	
	static int findFactorial( Integer number )
		{
			if( number == 0 )
				return 1;
			else if( number==1 )
				return 1;
	
    return number*findFactorial(number-1);
		}

	public static void main(String[] args) {
		
		System.out.println("Enter the number for Factoial");
		Scanner read = new Scanner(System.in);
		String input = read.nextLine();
  
    //Ensuring that the input is only a number
		while ( ! input.matches("[0-9]+") )
		{
			System.out.println("Enter a valid number");
			input = read.nextLine();
		}
		Integer number=Integer.parseInt(input);
		Integer factorial = findFactorial(number);
		System.out.println("Factorial of " + number + " is " + factorial);
		
	}
	
}
