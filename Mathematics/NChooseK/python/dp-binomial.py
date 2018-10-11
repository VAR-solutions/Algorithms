def binomialCoeff(n, k):
    st = [[0 for i in range(k + 1)] for j in range(n + 1)]
    for i in range(n + 1):
        for j in range(min(i, k) + 1):
            if j == 0 or j == i:
                st[i][j] = 1
            else:
                st[i][j] = st[i - 1][j - 1] + st[i - 1][j]
    return st[n][k]

n, k = map(int, input().split())
print(binomialCoeff(n, k))
