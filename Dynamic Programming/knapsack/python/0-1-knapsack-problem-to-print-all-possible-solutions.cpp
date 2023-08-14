// C++ implementation to print all 
// the possible solutions of the 
// 0/1 Knapsack problem 

#include <bits/stdc++.h> 

using namespace std; 

// Utility function to find the 
// maximum of the two elements 
int max(int a, int b) { 
	return (a > b) ? a : b; 
} 

// Function to find the all the 
// possible solutions of the 
// 0/1 knapSack problem 
int knapSack(int W, vector<int> wt, 
			vector<int> val, int n) 
{ 
	// Mapping weights with Profits 
	map<int, int> umap; 
	
	set<vector<pair<int, int>>> set_sol; 
	// Making Pairs and inserting 
	// into the map 
	for (int i = 0; i < n; i++) { 
		umap.insert({ wt[i], val[i] }); 
	} 

	int result = INT_MIN; 
	int remaining_weight; 
	int sum = 0; 
	
	// Loop to iterate over all the 
	// possible permutations of array 
	do { 
		sum = 0; 
		
		// Initially bag will be empty 
		remaining_weight = W; 
		vector<pair<int, int>> possible; 
		
		// Loop to fill up the bag 
		// untill there is no weight 
		// such which is less than 
		// remaining weight of the 
		// 0-1 knapSack 
		for (int i = 0; i < n; i++) { 
			if (wt[i] <= remaining_weight) { 

				remaining_weight -= wt[i]; 
				auto itr = umap.find(wt[i]); 
				sum += (itr->second); 
				possible.push_back({itr->first, 
					itr->second 
				}); 
			} 
		} 
		sort(possible.begin(), possible.end()); 
		if (sum > result) { 
			result = sum; 
		} 
		if (set_sol.find(possible) == 
						set_sol.end()){ 
			for (auto sol: possible){ 
				cout << sol.first << ": "
					<< sol.second << ", "; 
			} 
			cout << endl; 
			set_sol.insert(possible); 
		} 
		
	} while ( 
		next_permutation(wt.begin(), 
						wt.end())); 
	return result; 
} 

// Driver Code 
int main() 
{ 
	vector<int> val{ 60, 100, 120 }; 
	vector<int> wt{ 10, 20, 30 }; 
	int W = 50; 
	int n = val.size(); 
	int maximum = knapSack(W, wt, val, n); 
	cout << "Maximum Profit = "; 
	cout << maximum; 
	return 0; 
} 
