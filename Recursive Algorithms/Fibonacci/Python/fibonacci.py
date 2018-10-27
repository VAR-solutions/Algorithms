def fib(n):
    if n <= 1:
        return n
    if a[n]:
        return a[n]
    else:
        ans = fib(n - 1) + fib(n - 2)
        a[n] = ans
        return ans


n = int(input("Enter a number\n"))
a = [0] * (n + 1)
print(fib(n))
