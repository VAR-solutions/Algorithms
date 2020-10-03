#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007;
using namespace std;
bool isvalid(int board[][10],int i,int j,int n)
{
    for(int k=0;k<i;k++)
    {
        if(board[k][j]==1)
        {
            return false;
        }
    }
    int x=i;
    int y=j;
    while(x>=0&&y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
     x=i;
     y=j;
    while(x>=0&&y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool showNqueen(int board[][10],int i,int n)
{
    if(i==n)
    {
       for(int a=0;a<n;a++)
       {
           for(int b=0;b<n;b++)
           {
               if(board[a][b]==1)
               {
                   cout<<"1 ";
               }else
               {
                   cout<<"0 ";
               }
           }
           cout<<endl;
       }


        return true;
    }
    for(int j=0;j<n;j++)
    {
        if(isvalid(board,i,j,n))
        {
            board[i][j]=1;
            if(showNqueen(board,i+1,n))
            {
                return true;
            }
            board[i][j]=0;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int board[10][10]={0};
    int n;
    cin>>n;
    bool f=showNqueen(board,0,n);
    return 0;
}
