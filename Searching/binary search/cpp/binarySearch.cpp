#include<iostream>
using namespace std;
bool BinarySearch(int arr[], int n, int k){
    int s=0;int e=n-1;
    while (s<=e){
        int mid=(s+e)/2;
        if (arr[mid]==k) return true;
        if (arr[mid]<k){
            s=mid+1;
        } else {
            e=mid-1;
        }
    }
    return false;
}
int main(){
    int n; cin>>n;
    int arr[n];
    cout<<"Enter The elements of the array"<<endl;
    for (int i=0;i<n;i++) cin>>arr[i];
    cout<<"Enter the key value you want to search"<<endl;
    int k; cin>>k;
    if (BinarySearch(arr,n,k)) cout<<"Element is found"<<endl;
}
