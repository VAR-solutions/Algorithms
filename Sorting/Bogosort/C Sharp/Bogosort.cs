// C# implementation of Bogo Sort 
using System; 
	
class GFG 
{ 
	// To Swap two given numbers 
	static void Swap<T>(ref T lhs, ref T rhs) 
	{ 
		T temp; 
		temp = lhs; 
		lhs = rhs; 
		rhs = temp; 
	} 
	
	// To check if array is sorted or not 
	public static bool isSorted(int[] a, int n) 
	{ 
		int i = 0; 
		while(i<n-1) 
		{ 
			if(a[i]>a[i+1]) 
				return false; 
			i++; 
		} 
		return true; 
	} 
		
	// To generate permuatation of the array 
	public static void shuffle(int[] a, int n) 
	{ 
		Random rnd = new Random(); 
		for (int i=0; i < n; i++) 
			Swap(ref a[i], ref a[rnd.Next(0,n)]); 
	} 
		
	// Sorts array a[0..n-1] using Bogo sort 
	public static void bogosort(int[] a, int n) 
	{ 
		// if array is not sorted then shuffle 
		// the array again 
		while ( !isSorted(a, n) ) 
			shuffle(a, n); 
	} 
		
	// prints the array 
	public static void printArray(int[] a, int n) 
	{ 
		for (int i=0; i<n; i++) 
			Console.Write(a[i] + " "); 
		Console.Write("\n"); 
	} 
	
	// Driver code 
	static void Main() 
	{ 
		int[] a = {3, 2, 5, 1, 0, 4}; 
		int n = a.Length; 
		bogosort(a, n); 
		Console.Write("Sorted array :\n"); 
		printArray(a,n); 
	} 
	//This code is contributed by DrRoot_ 
} 
