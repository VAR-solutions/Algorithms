#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n //size of the array
	int *arr = new int[n];

	for(int i=0; i<n;i++) 
		cin>>arr[i];
	int maxSoFar = INT_MIN, maxEndingHere = 0;
	for(int i=0; i<n; i++){
		maxEndingHere += arr[i];
		if(maxEndingHere > maxSoFar)
			maxSoFar = maxEndingHere;
		if(maxEndingHere < 0)
			maxEndingHere = 0;
	}
	return maxSoFar;
}