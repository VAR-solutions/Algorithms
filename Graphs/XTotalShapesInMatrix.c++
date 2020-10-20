#include<bits/stdc++.h>
using namespace std;


void dfs(vector<string> &arr,int n,int m,int i,int j,vector<vector<int>> &visited){
    
    if(i>=n||j>=m||i<0||j<0)
        return;
    visited[i][j]=1;
    if(arr[i][j]=='O')
        return ;
    
    if((i+1)<n&&visited[i+1][j]==0)
        dfs(arr,n,m,i+1,j,visited);
    if((j+1)<m&&visited[i][j+1]==0)
        dfs(arr,n,m,i,j+1,visited);
    if((i-1)>=0&&visited[i-1][j]==0)
        dfs(arr,n,m,i-1,j,visited);
    if((j-1)>=0&&visited[i][j-1]==0)
        dfs(arr,n,m,i,j-1,visited);
    
}
int Shape(vector<string> &arr,int n,int m) {
    //code here
    
    vector<vector<int>> visited(n,vector<int>(m,0));
    
    int i,j,count=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(visited[i][j]==0 && arr[i][j]=='X'){
                count++;
                //cout<<i<<" "<<j<<"\n";
                dfs(arr,n,m,i,j,visited);
            }
        }
    }
    return count; 
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<string> a;
    	
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        a.push_back(s);
    }
    cout<<Shape(a,n,m)<<"\n";

}
