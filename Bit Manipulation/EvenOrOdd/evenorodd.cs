using System;
					
public class Program
{
	public static void Main()
	{
		for (int i = 0; i < 10; i++) {
		    if ((i&1) == 1) {
				Console.WriteLine(i + " odd");
		    } else {
			    Console.WriteLine(i + " even");
            }
        }
    }
}
