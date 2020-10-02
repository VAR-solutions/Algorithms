# convert binary to decimal
 
# Function to convert binary to decimal

def binaryToDecimal(n):
    num = n
    dec = 0
    base = 1      # Initializing base value to 1, i.e 2 ^ 0

    temp = num
    while(temp):
        remainder = temp % 10
        temp = int(temp / 10)
         
        dec += remainder * base
        base = base * 2
    return dec
 
# Taking input and calling the binaryToDecimal function 

num = int(input())
res=binaryToDecimal(num)
print("Decimal Conversion of "+str(num)+" is: "+str(res))
 
