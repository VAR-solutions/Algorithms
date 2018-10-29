// a C++ program to implement traveling salesman problem(TSP)  

#include <bits/stdc++.h> 
using namespace std; 
#define V 4 

// implementation of tsp logic
int travllingSalesmanProblem(int graph[][V], int s) 
{ 
	// keep all vertex aside from source vertex 
	vector<int> vertex; 
	for (int i = 0; i < V; i++) 
		if (i != s) 
			vertex.push_back(i); 

	// storing min weight hamiltonian cycle. 
	int min_path = INT_MAX; 
	do { 

		// store current Path weight(cost) 
		int current_pathweight = 0; 
		
		// calculate the current path weight 
		int k = s; 
		for (int i = 0; i < vertex.size(); i++) { 
			current_pathweight += graph[k][vertex[i]]; 
			k = vertex[i]; 
		} 
		current_pathweight += graph[k][s]; 

		// minimum is updated
		min_path = min(min_path, current_pathweight); 
		
	} while (next_permutation(vertex.begin(), vertex.end())); 

	return min_path; 
} 

// testing now
int main() 
{ 
	// representation of graph in terms of a matrix 
	int graph[][V] = { { 0, 10, 15, 20 }, 
					{ 10, 0, 35, 25 }, 
					{ 15, 35, 0, 30 }, 
					{ 20, 25, 30, 0 } }; 
	int s = 0; 
	cout << travllingSalesmanProblem(graph, s) << endl; 
	return 0; 
} 
