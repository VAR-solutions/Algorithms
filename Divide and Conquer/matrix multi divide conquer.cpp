#include<bits/stdc++.h>
using namespace std;
 vector<vector<int,int>>c;
void matrixmulti(vector<vector<int,int>>a,vector<vector<int,int>>b)
{
    int n=a.size();

    if(n<=2)
    {
    c[0][0]=a11*b11+a12*b21;
    c[0][1]=a11*b12+a12*b22;
    c[1][0]=a21*b11+a22*b21;
    c[1][1]=a21*b12+a22*b22;
    }
    vector<vector<int,int>>a11,b11,a12,b12,a21,b21,a22,b22;
    matrixmulti(a11,b11)+matrixmulti(a12,b21);
    matrixmulti(a11,b12)+matrixmulti(a12,b22);
    matrixmulti(a21,b11)+matrixmulti(a22,b21);
    matrixmulti(a21,b12)+matrixmulti(a22,b22);


}
int main()
{
    int n;
    cin>>n;
    vector<vector<int,int>>a;
    vector<vector<int,int>>b;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>b[i][j];
        }
    }
    matrixmulti(a,b);
}
