def fun(n):
    if n==0 or n==1:
        return 1
    else:
        return float(2*fun(n-1)+3*fun(n-2)+n*(7**n))


T=int(input())
for i in range(T):
    n=int(input())
    k=fun(n)
    print(f"Case {i+1}:",k)