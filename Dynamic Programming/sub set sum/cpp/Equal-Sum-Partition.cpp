#include <iostream>
#include <vector>
#include <numeric>
#define boost() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
using namespace std;
bool isSubset(const vector<int>& arr, int sum, int n) {
    bool t[n+1][sum+1];
    for (int j = 0; j < sum + 1; j++) {
        t[0][j] = false;
    }
    for (int i = 0; i < n + 1; i++) {
        t[i][0] = true;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (arr[i-1] <= j) {
                t[i][j] = (t[i-1][j - arr[i-1]] || t[i-1][j]);
            } else t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}
bool solve(const vector<int>& arr) {
    int n = arr.size(), sum(0);
    sum = accumulate(begin(arr), end(arr), 0);
    // equal partition will only exists if there exists total sum of vector where vector must be sum % 2 == 0
    // if sum % 2 != 0, return false, otherwise do same operation of Subset-Sum for target sum as sum / 2;
    if (sum % 2 != 0)
        return false;
    else
        return isSubset(arr, sum / 2, n);
}
int main() {
    boost();
    int n;
    // Enter size of vector
    cin >> n;
    vector<int> arr(n);
    // put element to the vector
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(arr) ? cout << "Yes, Equal Partition exists." : cout <<  "No, Equal Partition doesn't exists.";
    return 0;
}