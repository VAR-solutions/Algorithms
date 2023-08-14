#include <iostream> 
using namespace std; 

// A recursive function used by countWays 
int countWaysUtil(int n, int m) 
{ 
	int res[n]; 
	res[0] = 1; 
	res[1] = 1; 
	
	for(int i = 2; i < n; i++) 
	{ 
	res[i] = 0; 
		
	for(int j = 1; j <= m && j <= i; j++) 
		res[i] += res[i - j]; 
	} 
	return res[n - 1]; 
} 

// Returns number of ways to reach s'th stair 
int countWays(int s, int m) 
{ 
	return countWaysUtil(s + 1, m); 
} 
 
int main() 
{ 
	int s = 4, m = 2; 
	
	cout << "Number of ways = "
		<< countWays(s, m); 
		
	return 0; 
}