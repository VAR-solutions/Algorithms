#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<int >a[],int row,int col,int n,int m){
    return (row>=0)&&(row<n)&&(col>=0)&&(col<m)&&(a[row][col]==1);
}

void dfs(vector<int >a[], int row,int col,int n,int m){
    int i;
    int rowArray[]={-1,-1,0,1,1,0,-1,1};
    int colArray[]={-1,0,-1,0,1,1,1,-1};
    
    a[row][col]=-1;
    for(i=0;i<8;i++){
        if(isSafe(a,row+rowArray[i],col+colArray[i],n,m)){
            dfs(a,row+rowArray[i],col+colArray[i],n,m);
        }
    }
    
}

int findIslands(vector<int> a[], int n, int m) {

    int i,j;
    int count=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]==1){
                dfs(a,i,j,n,m);
                count++;
            }
        }    
    }
    return count;


}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    	
    for(int i=0;i<n;i++){
        vector<int> temp(m);
        adj[i]=temp;
        for(int j=0;j<m;j++){
        	cin>>adj[i][j];
        }

    }
    cout<<findIslands(adj,n,m)<<"\n";

}
