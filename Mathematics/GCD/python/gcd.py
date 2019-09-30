# Calculate the gcd using the euclidean algorithm
# Accepts either 2 numbers, or 1 list
# By using a list, the gcd of multiple numbers can be calculated
def gcd(a,b = None):
    if b != None:
        if a % b == 0:
            return b
        else:
            return gcd( b, a % b)
    else:
        for i in range(len(a)):
            a[0] = gcd(a[0],a[i])
        return a[0]


# usage
print gcd([2,3,12])