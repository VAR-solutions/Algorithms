n = int(input())
prime = [1]*(n + 1)

p = 2
while p*p <= n:
    if prime[p] == 1:
        for i in range(p*2, n + 1, p):
            prime[i] = 0
    p+= 1

for i in range(2, n + 1):
    if prime[i] == 1:
        print("p =  " + str(i))
