
# Find politeness of number 
# Contributed by Nikita Tiwari  
# A function to count all odd prime factors 
# of a given number n 


def countOddPrimeFactors(n) : 
    result = 1; 
   
    # Eliminate all even prime factor of  
    # number of n 
    while (n % 2 == 0) : 
        n /= 2
   
    # n must be odd at this point, so iterate 
    # for only odd numbers till sqrt(n) 
    i = 3
    while i * i <= n : 
        divCount = 0
   
        # if i divides n, then start counting  
        # of Odd divisors 
        while (n % i == 0) : 
            n /= i 
            divCount = divCount + 1
         
        result = result * divCount + 1
        i = i + 2
   
    # If n odd prime still remains then count it 
    if (n > 2) : 
        result = result * 2
          
    return result 
      
   
def politness( n) : 
    return countOddPrimeFactors(n) - 1; 
    
n = int(input())
print "Politness of ", n, " = ", politness(n) 
  
