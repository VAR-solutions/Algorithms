def fib(n):
    if n == 0: return 0

    # Initial values of fibonacci series
    f = [1, 1]

    for i in range(2, n):
        # Use modulus to switch array indexes
        f[i%2] = f[0] + f[1]

    return f[(n+1)%2]

n = 9
print(fib(n))
