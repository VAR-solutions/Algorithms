//problem
//Given a vector of integers, find the highest product you can get from three of the integers.
//The input vectorOfInts will always have at least three integers.

//solution
// we want to do it in O(n) instead of O(n3) or O(nlgn)
//so we need to follow greedy approach
//we are storing 3 highest as well as 2 lowest values to get highest multiplication result
//as 2 negative values can also be positive after multiplication
#include<iostream>
#include<bits/stdc++.h>
#define pb push_back
#define INF 1e9
#define ll long long
using namespace std;

void solve()
{
	int n,temp;   //n = no. of values in list, temp is used for input
	cin>>n;
	vector<int> ar;   //ar is for storing problem list,
	for(int i = 0; i<n; i++) 
	{
		cin>>temp;
		ar.pb(temp);     //input
	}
	int low1= INF;
	ll  low2=INF, high1=-INF, high2=-INF, high3=-INF, ans=1;   //storing maximum as well as lowest
	for(int i=0; i<n; i++) //loop is for finding highest and lowest
	{
		if(high1<ar[i])
		{
			high3 = high2;
			high2 = high1;
			high1 = ar[i];
			
		}
		else if(high2<ar[i])
		{
			high3 = high2;
			high2 = ar[i];
		}
		else if(high3<ar[i])
		{
			high3 = ar[i];
		}
		
		if(low1>ar[i])
		{
			low2 = low1;
			low1 = ar[i];
		}
		else if(low2>ar[i]){
			low2 = ar[i];
		}
	}
	ans = high3* (low1*low2<high1*high2?high1*high2:low1*low2); //getting answer
	cout<< ans<<"\n";
}

int main()
{
	int t;  //test cases
	cin>>t;
	while(t--)
	{
		solve(); //calling solve method to print output
	}
	return 0;
}
