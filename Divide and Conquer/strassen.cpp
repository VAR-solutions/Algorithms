#include<bits/stdc++.h>
using namespace std;

auto strassen(auto m1,auto m2)
{
    int n=m1.length();
    int temp[n][n];
    if(n==1)
        temp[0][0]=m1[0][0]*m2[0][0];
    else
    {
        int a11[n/2][n/2];
        int a12[n/2][n/2];
        int a21[n/2][n/2];
        int a22[n/2][n/2];
        int b11[n/2][n/2];
        int b12[n/2][n/2];
        int b21[n/2][n/2];
        int b22[n/2][n/2];
        split(m1,a11,0,0);
        split(m1,a12,0,n/2);
        split(m1,a21,n/2,0);
        split(m1,a22,n/2,n/2);
        split(m2, b11, 0 , 0);
        split(m2, b12, 0 , n/2);
        split(m2, b21, n/2, 0);
        split(m2, b22, n/2, n/2);
        int M1[n][n]  = multiply(add(a11, a22), add(b11, b22));
        int M2[n][n] = multiply(add(a21, a22), b11);
        int M3[n][n] = multiply(a11, sub(b12, b22));
        int M4[n][n] = multiply(a22, sub(b21, b11));
        int M5[n][n] = multiply(add(a11, a12), b22);
        int M6[n][n] = multiply(sub(a21, a11), add(b11, b12));
        int M7[n][n]= multiply(sub(a12, a22), add(b21, b22));
        return temp;
    }

}
void split(int[]*x,int[]*y,int x1,int y1)
{

        for(int i1 = 0, i2 = x1; i1 < y.length; i1++, i2++)
            for(int j1 = 0, j2 = y1; j1 < y.length; j1++, j2++)
                y[i1][j1] = x[i2][j2];
}
int[][] add(int A[][], int B[][])
    {
        int n = A.length;
        int C[][] = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] + B[i][j];
        return C;
    }
int[][] sub(int A[][], int B[][])
    {
        int n = A.length;
        int C[][] = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] - B[i][j];
        return C;
    }
int main()
{
    int n;
    cout<<"Order of matrix?";
    cin>>n;
    int m1[n][n],m2[n][n];
    cout<<"Enter first matrix";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>m1[i][j];
        }
    }
    cout<<"Enter second matrix";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>m2[i][j];
        }
    }
    int c[n][n]=strassen(m1,m2);
}
