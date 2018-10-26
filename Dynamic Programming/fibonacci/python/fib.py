def Fib(n):
        n = int(input("Enter a value:"))
        if n == 1 or n == 2:
                return 1
        else:
                return(n-2) + (n-1)
print(Fib())
