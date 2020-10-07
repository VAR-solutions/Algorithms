#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

int gridUniquePath(int a,int b){
	/* If either 1 row or 1 column are there then the only way to end
	         is to traverse through that row or column respectively.*/
	if(a==1 || b==1)
		return 1;
	/*If there are more than one row and column then u need to move 
	        either right or down reducing one row or one column respectively
	        and adding that way in answer*/
	else
		return gridUniquePath(a-1,b)+gridUniquePath(a,b-1);
}

int gridUniquePathDP(int a,int b){
	int dp[a+1][b+1];

	//Store the result(memoization) and fill it in bottom-up manner
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			if(i==1 || j==1)
				dp[i][j]=1;
			else
				dp[i][j]=dp[i-1][j]+dp[i][j-1];

	return dp[a][b];
}

int main(){
	int a,b; //a and b are the dimensions of the matrix;
	cin>>a>>b; //take the user-input;

	//Recursive implementation(exponential time-complexity)
	int ans1=gridUniquePath(a,b);
	cout<<ans1<<endl;

	//Dynamic Programming Solution( 0(n^2) time-complexity )
	int ans2=gridUniquePathDP(a,b);
	cout<<ans2<<endl;

	return 0;
}