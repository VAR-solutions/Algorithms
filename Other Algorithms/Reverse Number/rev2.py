#Python3 program to take a number as an input and display it reversed using string manipulation
num=input()
aux=str(num)
i=""
for character in aux:
    i=character+i
reverse=int(i)
print(reverse)
