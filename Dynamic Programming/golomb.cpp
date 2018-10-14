// C++ Program to find first 
// n terms of Golomb sequence. 
#include <bits/stdc++.h> 
using namespace std; 

// Return the nth element 
// of Golomb sequence 
int findGolomb(int n) 
{ 
	// base case 
	if (n == 1) 
		return 1; 

	// Recursive Step 
	return 1 + findGolomb(n - 
			findGolomb(findGolomb(n - 1))); 
} 

// Print the first n 
// term of Golomb Sequence 
void printGolomb(int n) 
{ 
	// Finding first n 
	// terms of Golomb Sequence. 
	for (int i = 1; i <= n; i++) 
		cout << findGolomb(i) << " "; 
} 

// Driver Code 
int main() 
{ 
	int n = 9; 
	printGolomb(n); 
	return 0; 
} 
