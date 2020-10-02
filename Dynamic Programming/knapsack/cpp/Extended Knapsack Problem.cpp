// C++ code for the extended 
// Knapsack Approach 

#include <bits/stdc++.h> 
using namespace std; 
#define N 100 
#define W 100 
#define K 100 

int dp[N][W][K]; 
int solve(int profit[], 
		int weight[], 
		int n, int max_W, 
		int max_E) 
{ 

	// for each element given 
	for (int i = 1; i <= n; i++) { 

		// For each possible 
		// weight value 
		for (int j = 1; j <= max_W; j++) { 

			// For each case where 
			// the total elements are 
			// less than the constraint 
			for (int k = 1; k <= max_E; k++) { 

				// To ensure that we dont 
				// go out of the array 
				if (j >= weight[i]) { 

					dp[i][j][k] 
						= max( 
							dp[i - 1][j][k], 
							dp[i - 1] 
							[j - weight[i]] 
							[k - 1] 
								+ profit[i]); 
				} 
				else { 
					dp[i][j][k] 
						= dp[i - 1][j][k]; 
				} 
			} 
		} 
	} 

	return dp[n][max_W][max_E]; 
} 

// Driver Code 
int main() 
{ 

	memset(dp, 0, sizeof(dp)); 

	int n = 5; 
	int profit[] = { 2, 7, 1, 5, 3 }; 
	int weight[] = { 2, 5, 2, 3, 4 }; 
	int max_weight = 8; 
	int max_element = 2; 
	cout << solve(profit, 
				weight, n, 
				max_weight, 
				max_element) 
		<< "\n"; 

	return 0; 
} 
