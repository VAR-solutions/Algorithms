#include<bits/stdc++.h>

using namespace std;

vector <int> find_max_crossing_subarray(vector <int> A, int low, int mid, int high) {
    // res[0] is max_left index, res[1] is max_right index, res[2] is the max sum value
    vector <int> res(3);
    int sum = 0; int left_sum = -1000000; int right_sum = -1000000;
    for (int i = mid; i > low - 1; i--) {
        sum += A[i];
        if(sum > left_sum) {
            left_sum = sum;
            res[0] = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i < high + 1; i++) {
        sum += A[i];
        if(sum > right_sum) {
            right_sum = sum;
            res[1] = i;
        }
    }
    res[2] = left_sum + right_sum;
    return res;
}

vector <int> find_max_subarray(vector <int> A, int low, int high) {
    if(high == low) {
        vector <int> res(3);
        res[0] = low; res[1] = high; res[2] = A[low];
        return res;
    }
    int mid = (low + high)/2;
    vector <int> res(3);
    vector <int> left_res = find_max_subarray(A, low, mid);
    vector <int> right_res = find_max_subarray(A, mid + 1, high);
    vector <int> cross_res = find_max_crossing_subarray(A, low, mid, high);

    if(left_res[2] >= right_res[2] && left_res[2] >= cross_res[2]) {
        res = left_res;
    }
    else if(right_res[2] >= left_res[2] && right_res[2] >= cross_res[2]) {
        res = right_res;
    }
    else {
        res = cross_res;
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    vector <int> res = find_max_subarray(A, 0, n - 1);
    cout << res[0] << " " << res[1] << " " << res[2];
    return 0;
}
