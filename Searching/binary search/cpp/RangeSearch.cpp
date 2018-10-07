// Find the range of a particular element occuring in a given sorted array.
// If the element doesn't exist, return 1.

#include <bits/stdc++.h>

using namespace std;

int findleft(const vector<int>& A, int B, int low, int high){
    int res = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(A[mid] == B){
            res = mid;
            high = mid-1;
        }else if(A[mid] < B){
            low = mid+1;
        }else high = mid-1;
    }
    if(res == -1)
        return res;
    return low;
}

int findright(const vector<int>& A, int B, int low, int high){
    int res = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(A[mid] == B){
            res = mid;
            low = mid+1;
        }else if(A[mid] > B){
            high = mid-1;
        }else low = mid+1;
    }
    if(res == -1)return -1;
    return low-1;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v({1,2,2,3,3,3,4,4,4,4,5,6,7,8,8,8,8,8});

    cout << "The input vector is: " << endl;
    for(auto i: v){
        cout << i << " ";
    }
    cout << endl;

    cout << "The first and last index of occurance of element '8' is : " << findleft(v, 8, 0, v.size()-1)
                                                                         << "  " 
                                                                         << findright(v, 8, 0, v.size()-1) 
                                                                         << endl;

    cout << "The first and last index of occurance of element '1' is : " << findleft(v, 1, 0, v.size()-1)
                                                                         << "  " 
                                                                         << findright(v, 1, 0, v.size()-1) 
                                                                         << endl;

    cout << "The first and last index of occurance of element '10' is : " << findleft(v, 10, 0, v.size()-1)
                                                                         << "  " 
                                                                         << findright(v, 10, 0, v.size()-1) 
                                                                         << endl;

    return 0;
}