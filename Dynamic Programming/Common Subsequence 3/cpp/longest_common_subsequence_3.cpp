// Longest Common Sequence of 3 Sequences
#include <bits/stdc++.h>
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  int n = a.size(); int m = b.size(); int p = c.size();
  vector < vector < vector <int> > > dp(n + 1, vector < vector <int> > (m + 1, vector <int> (p + 1)));
  for (int i = 0; i < n + 1; ++i) {
    for (int j = 0; j < m + 1; ++j) {
      for (int k = 0; k < p + 1; ++k){
        if(i == 0 || j == 0 || k == 0) {
          dp[i][j][k] = 0;
        }
        else if(a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) {
          dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
        }
        else {
          dp[i][j][k] = max(dp[i][j - 1][k], max(dp[i - 1][j][k], dp[i][j][k - 1]));
        }
      }
    }
  }
  return dp[n][m][p];
}

int main() {
  size_t an; cin >> an; vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    cin >> a[i];
  }
  size_t bn; cin >> bn; vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    cin >> b[i];
  }
  size_t cn; cin >> cn; vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    cin >> c[i];
  }
  cout << lcs3(a, b, c) << endl;
}
