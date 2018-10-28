def ackermann(m, n):
    print('A({},{})'.format(m, n))
    if m == 0:
        return n + 1
    if n == 0:
        return ackermann(m - 1, 1)
    n2 = ackermann(m, n - 1)
    return ackermann(m - 1, n2)

print(ackermann(2,2))