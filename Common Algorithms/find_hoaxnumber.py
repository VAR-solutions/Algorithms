# code to check if a number is a hoax 
# number or not. 
# contributed by Manish Shaw


import math 
  
# Function to find distinct prime factors 
# of given number n 
def primeFactors(n) : 
    res = [] 
    if (n % 2 == 0) : 
        while (n % 2 == 0) : 
            n = int(n / 2) 
        res.append(2) 
  
    # n is odd at this point, since it is no 
    # longer divisible by 2. So we can test 
    # only for the odd numbers, whether they 
    # are factors of n 
    for i in range(3,int(math.sqrt(n)),2): 
        # Check if i is prime factor 
        if (n % i == 0) :  
            while (n % i == 0) : 
                n = int(n / i) 
            res.append(i) 
  
    # This condition is to handle the case 
    # when n is a prime number greater than 2 
    if (n > 2) : 
        res.append(n) 
    return res 
  
# Function to calculate sum of digits of 
# distinct prime factors of given number n 
# and sum of digits of number n and compare 
# the sums obtained 
def isHoax(n) : 
    # Distinct prime factors of n are being 
    # stored in vector pf 
    pf = primeFactors(n) 
      
    # If n is a prime number, it cannot be a 
    # hoax number 
    if (pf[0] == n) : 
        return False
      
    # Finding sum of digits of distinct prime 
    # factors of the number n 
    all_pf_sum = 0
    for i in range(0,len(pf)): 
  
        # Finding sum of digits in current 
        # prime factor pf[i].  
        pf_sum = 0
        while (pf[i] > 0): 
            pf_sum += pf[i] % 10
            pf[i] = int(pf[i] / 10) 
  
        all_pf_sum += pf_sum 
      
  
    # Finding sum of digits of number n 
    sum_n = 0; 
    while (n > 0): 
        sum_n += n % 10
        n = int(n / 10) 
  
    # Comparing the two calculated sums 
    return sum_n == all_pf_sum 
  
n = int(input()); 
if (isHoax(n)): 
    print ("A Hoax Number\n") 
else: 
    print ("Not a Hoax Number\n")
