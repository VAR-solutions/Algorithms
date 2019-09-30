using System;

public class Program
{
	public void Main()
	{
		var arrayToSearch = new int[]{1, 2, 3, 4, 5};
		// Should match at index 2
		Console.WriteLine(LinearSearch(arrayToSearch, 3));
		// 7 does not exist in the array to search, will return -1
		Console.WriteLine(LinearSearch(arrayToSearch, 7));
	}

	/// <summary>
	/// Searches through the arrayToSearch to find the target.
	///	Returns the index the target was found at, or -1 if no match was found
	/// </summary>
	public static int LinearSearch(int[] arrayToSearch, int target)
	{
		for (var i = 0; i < arrayToSearch.Length; i++)
		{
			if (arrayToSearch[i] == target)
				return i;
		}

		return -1;
	}
}