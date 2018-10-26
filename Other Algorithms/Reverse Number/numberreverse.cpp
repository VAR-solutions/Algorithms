//reversing a number
#include<iostream>
using namespace std;
int main()
{int n,rev=0,num;
cout<<"Enter the no. to be reversed :" ;
cin>>num;
while(num)
{n=num%10;
rev=rev*10+n;
num=num/10;
 }
 cout<<"The reverse number is "<<rev; 
}
