/*
 Problem :- Tower of Hanoi (The Tower of Hanoi is a mathematical game or puzzle. It consists of three rods and a number of disks of different sizes)
 Read more about problem :-https://en.wikipedia.org/wiki/Tower_of_Hanoi
 
 Algorithm Type : Recursive
 */
#include<bits/stdc++.h>
using namespace std;
void tower_of_hanoi(int n,char source,char helper,char desti)
{
  //base case
  if(n==0)
  {
      return;
  }
  //first transfer (n-1) disk from source to helper
  tower_of_hanoi(n-1,source,desti,helper);
  //1 disk from source to desti.
  cout<<"shift disk "<<n<<" from "<<source<<" to "<<desti<<endl;
  //next (n-1) from helper to desti
  tower_of_hanoi(n-1,helper,source,desti);
  return;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
   int n;
   cin>>n;
   //takes 2^n - 1 total move 
   char source='A';
   char helper='B';
   char desti='C';
   tower_of_hanoi(n,source,helper,desti); 
return 0;
}

