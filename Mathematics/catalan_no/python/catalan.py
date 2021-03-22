#Python program for nth Catalan Number

# Returns value of Binomial Coefficient C(n, k)
def binomialCoefficient(n, k):
 
    # since C(n, k) = C(n, n - k)
    if (k > n - k):
        k = n - k
 
    # initialize result
    res = 1
 
    # Calculate value of [n * (n-1) *---* (n-k + 1)]
    # / [k * (k-1) *----* 1]
    for i in range(k):
        res = res * (n - i)
        res = res / (i + 1)
    return res
 
# A Binomial coefficient based function to
# find nth catalan number in O(n) time
def catalan(n):
    c = binomialCoefficient(2*n, n)
    return c/(n + 1)
 
for i in range (10):
    print (catalan(i),end=" ")
