/*
This CPP Program is used to find the lower_bound of a given element in an array/vector
This also works on a condition that the given array/vector must be sorted
This returns the location of the element of the vector/array that is just lower or equal to the given element/number
*/

#include<bits/stdc++.h>

using namespace std;


int main() {


int n;

cin>>n; // no. of elements in the vector/array

vector<int> v; //initialising the vector

for(int j=0;j<n;j++) {
	int h;

	cin>>h; 

	v.push_back(h); // taking in the vector elements as input
}


sort(v.begin(),v.end()); // sorting the vector

int j;

cin>>j;


vector<int>::iterator lo1; // iterator for going through the vector


lo1=lower_bound(v.begin(),v.end(),j); // lower bound function

cout<<"The lower bound for the element "<<j<<" is at position"<<(lo1-v.begin());

// lower bound result for the desired number
	return 0;
}