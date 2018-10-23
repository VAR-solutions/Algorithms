def kadane(a,n):
    ans=max(a)
    s=0
    for e in a:
        s+=e
        if s<0:
            s=0
        ans = max(ans,s)

    return ans


n=int(input('Enter the size of array'+'\n'))
a=[int(i) for i in input().split()]
print(kadane(a,n))
