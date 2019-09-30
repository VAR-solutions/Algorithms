

print("Type a number")
n = input()
a = 2
b = True


while a < int(n):
	if int(n) % a == 0 :
		print("n is not a prime number!")
		a = int(n)
		b = False
		
	a = a + 1


	
if b == True:
	print("n is a prime number!")
