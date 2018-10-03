#include <iostream>
#include <string.h>
using namespace std;

// int max(int a,int b){
//     return (a<b)?a:b;
// }

int LCS(char *X,char *Y,int x, int y){
    int T[x+1][y+1];

    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++)
        {
            if(i==0||j==0)
                T[i][j] = 0;
            
            else if(X[i-1]==Y[j-1])
                T[i][j] = T[i-1][j-1]+1;
            
            else
                T[i][j] = max(T[i-1][j],T[i][j-1]);
        }
    }
    
    return T[x][y];
}


int main(int argc, char const *argv[])
{
    char X[] = "AGGTAB"; 
    char Y[] = "GXTXAYB";
    int x , y;
    x = strlen(X);
    y = strlen(Y);

    int result  = LCS(X,Y,x,y);
    cout<<result;


    
    return 0;
}
