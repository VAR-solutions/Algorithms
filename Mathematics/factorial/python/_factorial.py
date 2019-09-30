def factorial(number):
        fact = 1
        while number > 0:
                fact *= number
                number -= 1
        return fact

n = int(input("Enter the number: "))
print("%d! = %d" %(n, factorial(n)))
