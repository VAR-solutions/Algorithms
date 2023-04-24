#Find the smallest common multiple of the given parameters that can be evenly divided by both

num1 = int(input("Type an integer: "))
num2 = int(input("Type another integer: "))

if num1 > num2:
    x = num1
else:
    x = num2

for i in range(x):
    aux = num1 * i
    if (aux % num2) == 0:
        mmc = aux

print(mmc)