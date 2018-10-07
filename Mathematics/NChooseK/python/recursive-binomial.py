def binomialCoeff(n, k):
    if k == n or k == 0:
        return 1
    return binomialCoeff(n - 1, k) + binomialCoeff(n - 1, k - 1)

n, k = map(int, input().split())
print(binomialCoeff(n, k))
