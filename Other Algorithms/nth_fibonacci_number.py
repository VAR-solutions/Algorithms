# This program takes n as input
# It will display the nth number in the fibonacci series
# It uses recursion

def Fibonacci(n):
    if n < 0:
        print("Please provide the value of n > 0")
    elif n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return Fibonacci(n-1) + Fibonacci(n-2)

print('''Welcome! This program takes \'n\' as input
and it will print the n-th number in the Fibonacci series...''')
n = int(input("Enter the value of n - "))
print(Fibonacci(n))
        
