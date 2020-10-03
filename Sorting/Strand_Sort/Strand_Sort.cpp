// CPP program to implement Strand Sort 
#include <bits/stdc++.h> 
using namespace std; 

// A recursive function to implement Strand 
// sort. 
// ip is input list of items (unsorted). 
// op is output list of items (sorted) 
void strandSort(deque<int> &ip, deque<int> &op) 
{ 
	// Base case : input is empty 
	if (ip.empty()) 
		return; 

	// Create a sorted sublist with 
	// first item of input list as 
	// first item of the sublist 
	deque<int> sublist; 
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

			// erase() on list removes an 
			// item and returns iterator to 
			// next of removed item. 
			it = ip.erase(it); 
		} 

		// Otherwise ignore current element 
		else
			it++; 
	} 

	// Merge current sublist into output 
	deque<int> dq2;
	merge(op.begin(),op.end(),sublist.begin(),sublist.end(),inserter(dq2 ,dq2.begin()));
	op = dq2;
	// Recur for remaining items in 
	// input and current items in op. 
	strandSort(ip,op); 
} 


int main(void) 
{ 
	int n;
	cin>>n;
	deque<int> ip(n); 
	for(int i=0 ; i<n ; i++){
		cin>>ip[i];
	}

	deque<int> op; 

	strandSort(ip, op); 

	for (auto x : op) 
		cout << x << " "; 
	return 0; 
} 
