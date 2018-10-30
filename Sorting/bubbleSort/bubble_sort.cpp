#include <iostream>
using namespace std;
#define for_i0n for(int i=0;i<n;i++)
#define for_ji1n for(int j=0;j<n - i - 1;j++) 
int main() {
  int array[] = {4,1,9,6,2};
  // bubble sort
  
  for_i0n {
    for_ji1n {
      if(array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  
  cout<<"Updated Array : "<<endl;
  for(int i=0;i<n;i++) {
    cout<<array[i]<<" ";
  }
  cout<<endl;
  return 0;
}
