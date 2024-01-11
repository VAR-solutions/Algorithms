import timeit

def Sieve(n):
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p*2,n+1,p):
                prime[i] = False
        p += 1
    c = 0
    for p in range(2,n):
        if prime[p]:
            print(p)
            c += 1
    return c
t0 = timeit.default_timer()
c = Sieve(100000)
print("Total prime numbers in range: ", c)
t1 = timeit.default_timer()
print("Time required: ", t1-t0 )
