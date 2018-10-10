#include <bits/stdc++.h>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  for(int i = 1; i < n; i++) {
      int w = weights[i];
      int v = values[i];
      double key = (double)v/w;
      int j = i - 1;
      while(j >= 0 && (double)values[j]/weights[j] < key) {
          weights[j+1] = weights[j];
          values[j+1] = values[j];
          j--;
      }
      weights[j+1] = w;
      values[j+1] = v;
  }
  for(int i = 0; i < n; i++) {
      if(capacity == 0) {
          return value;
      }
      int a = min(weights[i], capacity);
      value += a*((double)values[i]/weights[i]);
      weights[i] -= a;
      capacity -= a;
  }
  return value;
}

int main() {
  int n; int capacity;
  cin >> n >> capacity;
  vector <int> values(n); vector <int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }
  double optimal_value = get_optimal_value(capacity, weights, values);
  cout << optimal_value << endl;
  return 0;
}
