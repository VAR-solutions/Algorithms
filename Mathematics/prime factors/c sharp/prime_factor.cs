using System;
					
public class Program
{
	public static void Main()
	{
		Console.WriteLine("-1 ->"+ IsPrime(-1));
		Console.WriteLine("0 ->"+IsPrime(-0));
		Console.WriteLine("1 ->"+IsPrime(1));
		Console.WriteLine("2 ->"+IsPrime(2));
		Console.WriteLine("23456788 ->"+IsPrime(23456788));
		Console.WriteLine("23456789 ->"+IsPrime(23456789));
	}
	
	
	public static bool IsPrime(int num)
	{
		//ref: https://en.wikipedia.org/wiki/Prime_number
		
		if (num <= 1) return false;
    	if (num == 2) return true;
    	if (num % 2 == 0) return false;
		
		var sqrt=(int)Math.Floor((Math.Sqrt(num)));
		
		for (int i = 3; i <= sqrt; i+=2) 
		{
			if((num%i) == 0)
			{
				return false;				
      		}
  		}	
		return true;
	}
}