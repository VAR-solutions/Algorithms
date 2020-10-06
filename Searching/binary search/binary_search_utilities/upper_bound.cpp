/*
This is a CPP program to get an upper bound for an element.
It works on a condition that the array/vector on which it works must be sorted.
This returns the location of the element in the vector just greater than the given element.
*/


#include<bits/stdc++.h>

using namespace std;


int main() {

int n;

cin>>n; // taking in the no. if elements in the array

vector<int> v;

for(int i=0;i<n;i++) {  // taking in the elements details
	int h;

	cin>>h;

	v.push_back(h);
}


cout<<"Please enter the number whose upper bound is to be found!";

int j;

cin>>j; // element to be proceed with its upper bound

sort(v.begin(),v.end()); //sorting the vector as the upper_bound function works on a sorted array

vector<int>::iterator up1; // initialising a vector array


up1=upper_bound(v.begin(),v.end(),j); // using the upper_bound function


cout<<"The upper bound for element "<<j<<" is at position "<<(up1-v.begin());

	return 0;
}