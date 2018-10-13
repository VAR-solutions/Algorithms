#include <bits/stdc++.h>

using namespace std;

int extended_bottom_cut_rod(vector <int> p, int n, vector <int> &r, vector <int> &s) {
    for (int i = 1; i < n + 1; i++) {
        int q = -1000000;
        for (int j = 1; j < i + 1; j++) {
            if(q < (p[j - 1] + r[i - j])) {
                q = p[j - 1] + r[i - j];
                s[i] = j;
            }
        }
        r[i] = q;
    }
    return r[n];
}

void print_cut_rod(vector <int> p, int n) {
    vector <int> r(n + 1); vector <int> s(n + 1);
    int min_cut_cost = extended_bottom_cut_rod(p, n, r, s);
    cout << min_cut_cost << endl; // print minimum cost to cut rod
    // print steps of cutting rod 
    while(n > 0) {
        cout << s[n] << " ";
        n -= s[n];
    }
}

int main() {
    int n; cin >> n;
    vector <int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    print_cut_rod(p, n);
}
