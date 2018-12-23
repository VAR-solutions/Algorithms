# Python program to demonstrate Basic Euclidean Algorithm 
# Function to return gcd of a and b 
def gcd(a, b):  
    if a == 0 : 
        return b  
    return gcd(b%a, a) 
  
# example with 2 numbers which could be taken as input also
a = 10
b = 15
print(gcd(a, b)) 
