#! python 3

# base, exponent, and prime (mod)
x = 2
y = 32
p = 1023

def power(x, y, p):
    res = 1
    x = x%p
    while y>0:
        if y%2 == 1:
            res = (res*x)%p
        y = y/2
        x = (x*x)%p
    return res

print(power(x,y,p))
