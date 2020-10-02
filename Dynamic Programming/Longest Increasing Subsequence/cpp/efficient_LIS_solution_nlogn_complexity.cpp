/*
Author: Shrey Rai
Program to find length of longest increasing subsequence in nlogn time complexity
Time Complexity: O(nlogn)
Efficient Solution of Longest Increasing Subsequence problem using Dynamic Programming.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,i,j;
    cin>>n; //Size of array
    ll a[n];
    vector<ll>v;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        vector<ll>::iterator it = lower_bound(v.begin(),v.end(),a[i]);
        if(it==v.end())
            v.push_back(a[i]);
        else
        {
            *it = a[i];
        }

    }
    cout<<v.size();
    return 0;

}
