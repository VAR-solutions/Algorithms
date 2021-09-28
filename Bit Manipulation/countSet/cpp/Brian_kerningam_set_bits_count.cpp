#include<iostream>
 int countBits(int n){
 int res=0;
 while(n>0){
  n=n&(n-1);
  res++;
 }
 return res;
 }
 
 int main(){
 cout<<"enter the number"<<endl;
 int num;
 cin>>num;
 cout<<countBits(num)<<endl;
 
 return0;
 }
