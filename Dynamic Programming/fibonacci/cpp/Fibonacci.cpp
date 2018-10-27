#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000005
int arr[SIZE]={0};
int main()
{
   arr[0]=0;
   arr[1]=1;
   
   for(int i=2;i<SIZE;i++)
   arr[i]=arr[i-1]+arr[i-2];
   
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       cout<<arr[n]<<endl;
   }
   
   return 0;
}
