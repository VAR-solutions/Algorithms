#include<iostream>

using namespace std;

int SumArray(int arr[], int n){
if(n == 1){
  return arr[0];
  }
else {
  return arr[n-1] + SumArray(arr, n-1);
}
}

int main(){
int n;
cin >> n;
int arr[n]
for(int i = 0; i < n; i++){
cin >> arr[n];
}
cout << SumArray(arr, n);
}
