# Python Program to Compute the Factorial of a Number

def factorial(num):
    if (num < 0):  #checking num is less than 0
        return
    if (num == 1):
        return 1   #return facyorial of 1
    return num * factorial(num - 1)         #recursive call

print("5! is" + str(factorial(5)))    #calling the function
print("10! is " + str(factorial(10)))
