
// Subset Sum Problem (DP)
#include <bits/stdc++.h>

using namespace std;

// Returns true if there is a subset of set[] with sun equal to given sum

bool isSubsetSum(int set[], int n, int sum){
  bool subset[n+1][sum+1];
  for (int i = 0; i <= n; i++)
  subset[i][0] = true;
  for (int i = 1; i <= sum; i++)
  subset[0][i] = false;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= sum; j++){
      if(j<set[i-1])
      subset[i][j] = subset[i-1][j];
      if (j >= set[i-1])
      subset[i][j] = subset[i-1][j] || subset[i - 1][j-set[i-1]];
    }
  }
  return subset[n][sum];
}

int main()
{
  int n,sum;
  //input n - size of set and sum to which it has to be compared
  cin>>n>>sum;
  int set[n];
  //input elements of set
  for(int i=0;i<n;i++)
    cin>>set[i];
  if (isSubsetSum(set, n, sum) == true)
    cout<<"Found a subset with sum : "<<sum<<endl;
  else
    cout<<"No subset found with given sum : "<<sum<<endl;
  return 0;
}
