#include <iostream>
#include <string.h>
using namespace std;

int LCS(string X, string Y, int x, int y)
{
    if (x == 0 || y == 0)
        return 0;

    else if (X[x - 1] != Y[y - 1])
        return max(LCS(X, Y, x - 1, y), LCS(X, Y, x, y - 1));

    else
        return 1 + LCS(X, Y, x - 1, y - 1);
}

int main(int argc, char const *argv[])
{
    string X, Y;
    cin >> X >> Y;

    int x, y;
    x = X.length();
    y = Y.length();

    int result = LCS(X, Y, x, y);
    cout << result;
    return 0;
}
