#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findTargetSumWays(vector<int>& v, int S) {
        int n = v.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += v[i];
        }
        // let subsets be s1 and s2
        // s1+s2 = sum and s1-s2 = S (i.e. given target)
        //solving these to equations-
        // thus we have to find the number of subsets with sum s1 = (sum+S)/2;
        if((sum + (long)S) % 2 == 1 || sum < S) return 0;
        int s = (sum+S)/2;
        int t[n+1][s+1];
         for(int i=0;i<=s;i++) // when array is null
        { 
            t[0][i]=0;
        }
        for(int i=0;i<=n;i++) // when sum is 0 we can have an empty subset so subset count is 1
        {    
          t[i][0]=1;
        }
        for(int i=1;i<n+1;++i){
            if(v[i-1]==0)
            {
               t[i][0]=2*t[i-1][0]; //consider all the subsets of 0 which were not considered earlier.
            }
            else
            {
                t[i][0]=t[i-1][0];
            }
        }
        // using top to down approach
        for(int i=1;i<=n;i++){
            for(int j=1;j<=s;j++){
                if(v[i-1]<=j){
                    t[i][j]=t[i-1][j-v[i-1]] + t[i-1][j];     //condn where we add included and excluded subset
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=s;j++){
        //         cout<<t[i][j]<<" ";
        //     }
        //         cout<<endl;
        // }
    return t[n][s];
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    int S;
    cin>>S;
    cout<<"Number of ways to assign symbols to make sum of integers equal to target " <<S<<" : " <<findTargetSumWays(v, S)<<endl;
    return 0;
}
