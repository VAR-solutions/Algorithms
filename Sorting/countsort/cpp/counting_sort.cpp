#include <bits/stdc++.h>

using namespace std;

void count_sort(std::vector<int> &v, int mx)
{
    int a[mx + 1];
    memset(a, 0, sizeof a);
    for (int i = 0; i < v.size(); i++)
    {
        a[v[i]]++;
    }

    int ptr = 0;
    for (int i = 0; i < mx + 1; i++)
    {
        if (a[i] != 0)
        {
            while (a[i] != 0)
            {
                v[ptr++] = i;
                a[i]--;
            }
        }
    }
}

int main(void)
{
    std::vector<int> v;
    v.resize(5);
    v = {4, 5, 7, 1, 0};
    int mx = 7;

    count_sort(v, mx);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}