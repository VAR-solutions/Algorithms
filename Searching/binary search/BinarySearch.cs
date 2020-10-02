// C# program to illustrate the 
// Array.BinarySearch(Array, Object) 
// Method 
using System; 

class GFG { 

	// Main Method 
	public static void Main(String[] args) 
	{ 

		// taking an 1-D Array 
		int[] arr = new int[7] { 1, 5, 7, 4, 6, 2, 3 }; 

		// for this method array 
		// must be sorted 
		Array.Sort(arr); 

		Console.Write("The elements of Sorted Array: "); 

		// calling the method to 
		// print the values 
		display(arr); 

		// taking the element which is 
		// to search for in a variable 
		// It is not present in the array 
		object s = 8; 

		// calling the method containing 
		// BinarySearch method 
		result(arr, s); 

		// taking the element which is 
		// to search for in a variable 
		// It is present in the array 
		object s1 = 4; 

		// calling the method containing 
		// BinarySearch method 
		result(arr, s1); 
	} 

	// containg BinarySearch Method 
	static void result(int[] arr2, object k) 
	{ 

		// using the method 
		int res = Array.BinarySearch(arr2, k); 

		if (res < 0) { 
			Console.WriteLine("\nThe element to search for "
								+ "({0}) is not found.", 
							k); 
		} 

		else { 
			Console.WriteLine("The element to search for "
								+ "({0}) is at index {1}.", 
							k, res); 
		} 
	} 

	// display method 
	static void display(int[] arr1) 
	{ 

		// Displaying Elements of array 
		foreach(int i in arr1) 
			Console.Write(i + " "); 
	} 
} 
