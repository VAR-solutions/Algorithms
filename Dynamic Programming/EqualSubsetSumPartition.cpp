#include <bits/stdc++.h>
using namespace std;

class PartitionSet {
public:
  bool canPartition(const vector<int> &num) {
    int n = num.size();
    // find the total sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += num[i];
    }

    // if 'sum' is a an odd number, we can't have two subsets with same total
    if (sum % 2 != 0) {
      return false;
    }

    // we are trying to find a subset of given numbers that has a total sum of ‘sum/2’.
    sum /= 2;

    vector<vector<bool>> dp(n, vector<bool>(sum + 1));

    // populate the sum=0 column, as we can always have '0' sum without including any element
    for (int i = 0; i < n; i++) {
      dp[i][0] = true;
    }

    // with only one number, we can form a subset only when the required sum is
    // equal to its value
    for (int s = 1; s <= sum; s++) {
      dp[0][s] = (num[0] == s ? true : false);
    }

    // process all subsets for all sums
    for (int i = 1; i < n; i++) {
      for (int s = 1; s <= sum; s++) {
        // if we can get the sum 's' without the number at index 'i'
        if (dp[i - 1][s]) {
          dp[i][s] = dp[i - 1][s];
        } else if (s >= num[i]) { // else if we can find a subset to get the remaining sum
          dp[i][s] = dp[i - 1][s - num[i]];
        }
      }
    }

    // the bottom-right corner will have our answer.
    return dp[n - 1][sum];
  }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 4};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 1, 3, 4, 7};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{2, 3, 4, 6};
  cout << ps.canPartition(num) << endl;
}

// This code is contributed by Ritika Rawat
