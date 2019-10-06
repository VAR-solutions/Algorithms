#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;

    int p[n], at[n], bt[n], wt[n], tat[n], twt = 0, ttat = 0;

    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> at[i] >> bt[i];
    }

    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    while (complete != n) {

        for (int j = 0; j < n; j++) {

            if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;

            }

        }
        if (check == false) {
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;

            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
    cout << "Processes " <<" Burst time " <<" Waiting time " << " Turn around time\n";
    for (int i = 0; i < n; i++) {
        twt = twt + wt[i];
        ttat = ttat + tat[i];
        cout << " " << p[i] << "\t\t" <<bt[i] << "\t\t " << wt[i] <<"\t\t " << tat[i] << endl;
    }
    cout << "\nAverage waiting time = " <<
        (float) twt / (float) n;
    cout << "\nAverage turn around time = " <<
        (float) ttat / (float) n;
    return 0;
}
