#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n+1];
    arr[0]=arr[1]=1;
    for(int i=2; i<n+1; i++){
        arr[i]=i*arr[i-1];
    }
    cout<<arr[n];
    }
