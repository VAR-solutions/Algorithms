#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int ARRAY_LEN = 100001;
int A[ARRAY_LEN];

struct Node
{
    int mn, mx;
    vector <int> B;
    Node *c[2];

    Node(int _mn = INT_MAX, int _mx = INT_MIN)
    {
        mn = _mn;
        mx = _mx;
        c[0] = c[1] = nullptr;
    }
};

void delTree(Node *&x)
{
    if (x == nullptr) return;
    delTree(x->c[0]);
    delTree(x->c[1]);
    delete x;
}

inline void upd(Node *&x, int &v)
{
    if (x == nullptr) return;
    x->mn = min(x->mn,v);
    x->mx = max(x->mx,v);
    // updates min and max for a given node
}

void Build(Node *&x, int *from, int *to)
{
    if (x->mn == x->mx || from >= to) return;
    x->B.push_back(0);
    int mid = (x->mn+x->mx)>>1;
    Node *L = new Node, *R = new Node;
    auto f = [mid](int &x) { return (x <= mid); };

    for (auto it = from; it != to; ++it)
    {
        x->B.push_back(x->B.back()+f(*it));
        if (*it <= mid) upd(L,*it); else upd(R,*it);
    }

    auto pivot = stable_partition(from, to, f);
    x->c[0] = L, x->c[1] = R;
    Build(x->c[0], from, pivot);
    Build(x->c[1], pivot, to);
    if (L->mn == INT_MAX) x->c[0] = nullptr, delete L;
    if (R->mn == INT_MAX) x->c[1] = nullptr, delete R;
}

int Frequency(Node *x, int L, int R, int &v)
{
    while (x != nullptr)
    {
        if (v < x->mn || v > x->mx) return 0;
        if (x->mn == x->mx) return R-L;
        int mid = (x->mn+x->mx)>>1;

        if (v <= mid)
            L = x->B[L], R = x->B[R], x = x->c[0];
        else
            L -= x->B[L], R -= x->B[R], x = x->c[1];
    }

    return 0;
}

int LTE(Node *x, int L, int R, int &v)
{
    if (L > R || v < x->mn) return 0; // invalid range/all numbers are greater than v
    if (x->mx <= v) return R-L;
    return LTE(x->c[0], x->B[L], x->B[R], v)+LTE(x->c[1], L-x->B[L], R-x->B[R], v);
}

int Kth(Node *x, int L, int R, int k)
{
    if (L > R) return 0;
    if (x->mn == x->mx) return x->mn;
    int cntLeft = x->B[R]-x->B[L]; // how many numbers are in the left subtree
    if (k <= cntLeft) return Kth(x->c[0], x->B[L], x->B[R], k);
    return Kth(x->c[1], L-x->B[L], R-x->B[R], k-cntLeft);
}

int main()
{
    ios_base::sync_with_stdio(0);


    int n, q;
    cin >> n; // array length
    Node *root = new Node; // root of Wavelet tree

    for (int t1 = 1; t1 <= n; ++t1) // 1-indexed
    {
        cin >> A[t1];
        upd(root,A[t1]);
    }

    Build(root, A+1, A+n+1);
    cin >> q;

    while (q) // q queries
    {
        --q;
        char c;
        int L, R, v;
        cin >> c;

        if (c == 'F') // get frequency of v in range [L,R]
        {
            cin >> v >> L >> R;
            cout << Frequency(root, L-1, R, v) << '\n';
        }
        else if (c == 'L')
        {
            // get count of numbers that are
            // less than or equal to v in range [L,R]
            cin >> v >> L >> R;
            cout << LTE(root, L-1, R, v) << '\n';
        }
        else if (c == 'K') // get v-th number in range [L,R]
        {
            cin >> v >> L >> R;
            cout << Kth(root, L-1, R, v) << '\n';
        }
    }

    delTree(root), root = nullptr; // avoid memory leak


    return 0;
}