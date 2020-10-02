/*

A fibonacci series is a special series wherein every number (except for 0 and 1) is a sum of the previous 2 numbers.
example:
    0 1 1 2 3 5 8 .....
    here,
        8 = 5+3
        5 = 3+2
        3 = 2+1
A fibonacci series forms the basis of the geometric pattern that the universe forms into. Its relevance comes into play when we aggregate the series to find it matching to the golden ratio

The following program is an efficient way of finding the fibonacci series upto the Nth term via dynamic programming


*/

class fibonacci { 

	// Function to find the fibonacci series 
	static int fib(int n) 
	{ 
		int f[] = new int[n + 2];      // To store the fibonacci numbers
		int i; 
    
		f[0] = 0; 
		f[1] = 1;     // initial numbers of the fibonacci series (pre known)

		for (i = 2; i <= n; i++) { 

			// Add the previous 2 numbers 
			// in the series and store it 
			f[i] = f[i - 1] + f[i - 2]; 
		} 

		// Nth Fibonacci Number 
		return f[n]; 
	} 

	public static void
	main(String args[]) 
	{ 
		int N = 10; // taking N as 10. It can be inputted via user as well

		// Print first 10 term 
		for (int i = 0; i < N; i++) 
			System.out.print(fib(i) + " "); 
	} 
} 
