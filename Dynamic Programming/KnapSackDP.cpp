//watch the video and understand later implement
#include <iostream>
using namespace std;

int KnapSack(int W,int n, int wt[],int v[]){
    int T[n+1][W+1];

    for(int i=0;i<=n;i++){
        
        for(int j = 0; j <=W; j++)
        {
            if(i==0||j==0)
                T[i][j]=0;
            
            else if(wt[i-1]<=j)
                T[i][j] = max(v[i-1]+T[i-1][j-wt[i-1]],T[i-1][j]);

            else 
                T[i][j] = T[i-1][j];
        }
        
    }
    
    return T[n][W];
}


int main(int argc, char const *argv[])
{
    int W = 30,n = 3 ;
    int Value[] = {30, 90, 95}; 
    int Weights[] ={14, 18, 13}; 

    int result = KnapSack(W,n,Weights,Value);
    cout<<result;
    
    return 0;
}

