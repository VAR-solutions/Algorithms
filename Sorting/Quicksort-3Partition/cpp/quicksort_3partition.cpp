#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

vector <int> partition3(vector<int> &a, int l, int r) {
    vector <int> res(2);
    int x = a[l];
    int i = l + 1; res[0] = l; res[1] = r;
    while(i <= r && res[0] <= res[1]) {
      if(a[i] < x) {
          swap(a[res[0]], a[i]);
          res[0]++; i++;
      }
      else if(a[i] > x) {
          swap(a[res[1]], a[i]);
          res[1]--;
      }
      else {
          i++;
      }
    }
    return res;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector <int> res = partition3(a, l, r);
  randomized_quick_sort(a, l, res[0] - 1);
  randomized_quick_sort(a, res[1] + 1, r);
}

int main() {
  int n; cin >> n;
  vector <int> a(n);
  for (int i = 0; i < a.size(); ++i) {
      cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (int i = 0; i < a.size(); ++i) {
      cout << a[i] << ' ';
  }
}
