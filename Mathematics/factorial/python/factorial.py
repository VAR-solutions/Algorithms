# Python Program to Compute the Factorial of a Number

def factorial(num):
    if (num < 0):
        return
    if (num == 1):
        return 1
    return num * factorial(num - 1)

print("5! is" + str(factorial(5)))
print("10! is " + str(factorial(10)))
