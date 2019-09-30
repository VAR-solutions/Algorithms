
# Count number of bits to be flipped 
# to convert A into B 
  
def countSetBits( n ): 
    count = 0
    while n: 
        count += n & 1
        n >>= 1
    return count 
      
def FlippedCount(a , b): 
    return countSetBits(a^b) 
  
a = 10
b = 20
print(FlippedCount(a, b)) 