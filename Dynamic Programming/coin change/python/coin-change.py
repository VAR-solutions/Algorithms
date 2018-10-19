def getWays(n, c):
    r=[0]*(n+1)
    r[0]=1
    for i in range(len(c)):
        for j in range(n+1):
            if j>=c[i]:
                r[j]+=r[j-c[i]]
    return r[n]
nm = input().split()
n = int(nm[0])
m = int(nm[1])
c = list(map(int, input().rstrip().split()))
print(getWays(n,c))
