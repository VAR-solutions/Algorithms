// Longest Icreasing Subsequence with BIT
// O(NloN) complexity

#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

void update(int index, int val, int (&bit)[MAXN]) {
    int size = sizeof(bit) / sizeof(*bit);
    for (int i = index; i <= size; i += (i & -i)) {
        bit[i] = max(bit[i], val);
    }
}

int getMax(int index, int (&bit)[MAXN]) {
    int res = 0;
    for (int i = index; i; i -= (i & -i)) {
        res = max(res, bit[i]);
    }

    return res;
}

int findLISBit(int arr[],int length) {
    int bit[MAXN];
    memset(bit, 0, sizeof bit);

    int res = 0;

    for (int i = 0; i < length; i++) {
        int current = getMax(arr[i], bit); 
        update(arr[i], current + 1, bit);
    }

    return getMax(MAXN - 5, bit);
}

int main() {
    int arr[] = { 1, 4, 2, 10, 8 };
    int lisLength = findLISBit(arr,5);
    cout << "Longest Increasing Subsequence Length is : " << lisLength << endl;
}