#include<bits/stdc++.h>
using namespace std;


int trappingWater(int arr[], int n){

    int i,j,k;
    int leftMax[n];
    int ans=0;
    int rightMax[n];
    leftMax[0]={0};
    rightMax[n-1]={0};
    for(i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],arr[i-1]);
    }
    
    for(i=n-2;i>=0;i--){
        rightMax[i]=max(rightMax[i+1],arr[i+1]);
    }
    
    for(i=0;i<n;i++){
        if((min(leftMax[i],rightMax[i])-arr[i])>0)
        ans+=(min(leftMax[i],rightMax[i])-arr[i]);
        
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    	cin>>a[i];
    cout<<trappingWater(a,n)<<"\n";

}
