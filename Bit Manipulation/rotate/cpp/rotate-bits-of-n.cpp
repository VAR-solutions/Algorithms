#include<bits/stdc++.h>
//max bits
#define INT_BITS 32

int leftRotate(int n, unsigned int d){
   return n << d%INT_BITS;
}

int rightRotate(int n, unsigned int d){
   return n >> d%INT_BITS;
}

int main(){
  int n,d;
  //input n (number) and d (no. of bits)
  std::cin>>n>>d;
  std::cout<<"Left Rotation of "<<n<<" by "<<d<<" is "<<leftRotate(n,d) <<std::endl;
  std::cout<<"Right Rotation of "<<n<<" by "<<d<<" is "<<rightRotate(n,d) <<std::endl;
  return 0;
}
