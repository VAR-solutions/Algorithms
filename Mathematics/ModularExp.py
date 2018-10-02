#! python 3
def  power(x, y ,p ) :
    res = 1
    x = x%p
    while(y>0) :
        if y %2 == 1 :
            res = (res*x) % p
        y = y/2
        x = (x*x)%p
    return res



print( power(2,32,1023))
