#Recursive Method
def Fibonacci(n): 
    if n<0: 
        print("Incorrect input") 
    # First Fibonacci number is 0 
    elif n==1: 
        return 0
    # Second Fibonacci number is 1 
    elif n==2: 
        return 1
    else: 
        return Fibonacci(n-1)+Fibonacci(n-2) 




#Dynamic Programming using Memoization
fib=[0,1]
def Fibonacci1(n): 
    if n<0: 
        print("Incorrect input") 
    # First Fibonacci number is 0 
    elif n==1: 
        return fib[0]
    # Second Fibonacci number is 1 
    elif n==2: 
        return fib[1]
    else: 
        for i in range(2,n): 
            fib.append(fib[-1]+fib[-2])
        return fib[-1]




#Dynamic Programming - Space Optimised
def Fibonacci2(n): 
    a = 0
    b = 1
    if n < 0: 
        print("Incorrect input") 
    # First Fibonacci number is 0 
    elif n==1: 
        return a
    # Second Fibonacci number is 1 
    elif n==2: 
        return b 
    else: 
        for i in range(2,n): 
            c = a + b 
            a = b 
            b = c 
        return b