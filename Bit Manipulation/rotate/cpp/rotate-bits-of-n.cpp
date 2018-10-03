#include<bits/stdc++.h>
//max bits
#define INT_BITS 32

int leftRotate(int n, unsigned int d){
   return (n << d)|(n >> (INT_BITS - d));
}

int rightRotate(int n, unsigned int d){
   return (n >> d)|(n << (INT_BITS - d));
}

int main(){
  int n,d;
  //input n (number) and d (no. of bits)
  cin>>n>>d;
  cout<<"Left Rotation of "<<n<<" by "<<d<<" is "<<leftRotate(n,d) <<endl;
  cout<<"Right Rotation of "<<n<<" by "<<d<<" is "<<rightRotate(n,d) <<endl
  return 0;
}
