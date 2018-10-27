num = int(input("Enter a number: "))
 
temp = num
rev = 0
 
while temp != 0:
    rev = (rev * 10) + (temp % 10)
    temp = temp // 10
 
if num == rev:
    print("number is palindrome")
else:
    print("number is not palindrome")
  
#slicing of string can also be used to get a reverse
#of the number to check whether it is palindrome or not.
