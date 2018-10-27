/* CPP program to find length of the largest 
subarray which has all contiguous elements */
#include<bits/stdc++.h> 
using namespace std; 
#define ll long long 
ll int findLength(ll arr[],ll int n) 
{ 
	ll max_len = 1; 

	for (ll int i=0; i<n-1; i++) 
	{ 
		
		set<ll int> myset; 
		myset.insert(arr[i]); 

		
		ll int mn = arr[i], mx = arr[i]; 

		
		for (ll int j=i+1; j<n; j++) 
		{ 
			if (myset.find(arr[j]) != myset.end()) 
				break; 

			
			myset.insert(arr[j]); 
			mn = min(mn, arr[j]); 
			mx = max(mx, arr[j]); 

			
			if (mx - mn == j - i) 
				max_len = max(max_len, mx - mn + 1); 
		} 
	} 
	return max_len; 
} 
int main () 
{ 
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	
	cout << "Length of the longest contiguous subarray is " << findLength(arr, n); 
	
	
	return 0;
} 


