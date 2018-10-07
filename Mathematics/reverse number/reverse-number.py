def reverse_number(n):
    res = 0
    while n > 0:
        res = res*10 + n % 10
        n //= 10
    return res

inp = int(input())
print(reverse_number(inp))
