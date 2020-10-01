/*Program to find if number exists in sorted array */
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int n, int num){
    int lo = 0, hi = n-1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] == num) {
            return 1;
        }
        if(arr[mid] > num) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int num;
    cin >> num;
    bool f = BinarySearch(arr, n, num);
    if(f) {
        cout << "Number is present in the given array";
    }
    else {
        cout << "Number is not present in the given array";
    }
    return 0;
}
