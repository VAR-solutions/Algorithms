
#include <bits/stdc++.h> 
using namespace std; 

// A recursive function to implement Strand 
// sort. 
// ip is input list of items (unsorted). 
// op is output list of items (sorted) 
void strandSort(list<int> &ip, list<int> &op) 
{ 
	// Base case : input is empty 
	if (ip.empty()) 
		return; 

	
	list<int> sublist; 
	sublist.push_back(ip.front()); 
	ip.pop_front(); 
	
	// Traverse remaining items of ip list 
	for (auto it = ip.begin(); it != ip.end(); ) { 

		// If current item of input list 
		// is greater than last added item 
		// to sublist, move current item 
		// to sublist as sorted order is 
		// maintained. 
		if (*it > sublist.back()) { 
			sublist.push_back(*it); 

			it = ip.erase(it); 
		} 

		// Otherwise ignore current element 
		else
			it++; 
	} 

	// Merge current sublist into output 
	op.merge(sublist); 

	// Recur for remaining items in 
	// input and current items in op. 
	strandSort(ip, op); 
} 

 
int main(void) 
{ 
	list<int> ip{10, 5, 30, 40, 2, 4, 9}; 

	// To store sorted output list 
	list<int> op; 

	// Sorting the list 
	strandSort(ip, op); 

	// Printing the sorted list 
	for (auto x : op) 
		cout << x << " "; 
	return 0; 
} 

