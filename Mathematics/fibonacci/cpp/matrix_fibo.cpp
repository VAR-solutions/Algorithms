#include<iostream>

using namespace::std;

int mat[2][2];

void power(int p)
{
if(p<2)return;
int i,j,k;
int temp[2][2];
temp[0][0] = mat[0][0]; 
temp[0][1] = mat[0][1]; 
temp[1][0] = mat[1][0]; 
temp[1][1] = mat[1][1];
int sol[2][2];
for(i=0;i<2;++i)
for(j=0;j<2;++j)
{
sol[i][j]=0;
for(k=0;k<2;++k)
sol[i][j]+=mat[i][k]*mat[k][j];
}

mat[0][0] = sol[0][0]; 
mat[0][1] = sol[0][1]; 
mat[1][0] = sol[1][0]; 
mat[1][1] = sol[1][1];

power(p/2);
if(p%2==1)
{
for(i=0;i<2;++i)
for(j=0;j<2;++j)
{
sol[i][j]=0;
for(k=0;k<2;++k)
sol[i][j]+=mat[i][k]*temp[k][j];
}
}

}

int main()
{

int fibo[2] = {0,1};
mat[0][0] = 1; 
mat[0][1] = 1; 
mat[1][0] = 1; 
mat[1][1] = 0;
int n;

cin>>n;
power(n-1);
cout<<mat[0][0]<<" "<<mat[0][1]<<endl;
cout<<mat[1][0]<<" "<<mat[1][1]<<endl;
cout<<"Fibo "<<n<<" :";
cout<<mat[0][0]<<endl; 
}