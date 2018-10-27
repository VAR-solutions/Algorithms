n=int(input())
a=[int(i) for i in input().split()]
b=[1]*n
for i in range(1,n):
    for j in range(i-1):
        if a[i]>a[j]:
            b[i]=max(b[i],b[j]+1)

print(b[-1])
