import math
def gcdExtend(a,b,x,y):
    if a==0:
        x=0
        y=1
        return b
    x1=1
    y1=1
    g=gcdExtend(b%a,a,x1,y1)
    x=y1-(b//a)*x1
    y=x1
    return g

x=1
y=1
a,b=map(int,input().split())
ans_gcd=gcdExtend(a,b,x,y)
print("gcd of (",a,b,") is",ans_gcd)
