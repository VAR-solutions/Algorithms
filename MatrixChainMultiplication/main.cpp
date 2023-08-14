#include <stdio.h>
#include<iostream>

using namespace std;
long int m[20][20];
int s[20][20];
int p[20],i,j,n;

void add_bracket(int i,int j)
{
if (i == j)
cout<<" A "<<i;
else
   {
      cout<<"( ";
      add_bracket(i, s[i][j]);
      add_bracket(s[i][j] + 1, j);
      cout<<" )";
   }
}

void mat(void)
{
long int q;
int k;
for(i=n;i>0;i--)
 {
   for(j=i;j<=n;j++)
    {
     if(i==j)
       m[i][j]=0;
     else
       {
        for(k=i;k<j;k++)
        {
         q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
         if(q<m[i][j])
          {
            m[i][j]=q;
            s[i][j]=k;
          }
         }
        }
      }
 }
}



int main()
{
int k;
cout<<"Enter the no. of elements: ";
cin>>n;
for(i=1;i<=n;i++){
for(j=i+1;j<=n;j++){
 m[i][i]=0;
 m[i][j]= 999999999;
 s[i][j]=0;
}}
cout<<"\nEnter the dimensions: \n";
for(k=0;k<=n;k++){
  cout<<"p"<<k<<" ";
  cin>>p[k];
}
mat();
cout<<"\nCost Matrix M:\n";
for(i=1;i<=n;i++)
 for(j=i;j<=n;j++)
  cout<<"m["<<i<<"]["<<j<<"]:"<<m[i][j]<<endl;


i=1,j=n;
cout<<"\nMultiplication Sequence : ";
add_bracket(i,j);
cout<<"\nMinimum number of multiplications is :"<< m[1][n];

                          return 0;

}
