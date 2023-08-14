#Given an array of integers, every element appears twice except for one. Find that single one.

#Input : [1, 2, 2, 3, 1]
#Output : 3

#Solution explanation: take xor of all numbers, a number occuring twice will make the xor 0, therefore after adding xor of all the numbers the sum will be equal to the number occuring once.

def singleNumber(A):
        res=0
        for i in range( len(A)):
            res= res^A[i]
        return res

a = [int(x) for x in input().split()] 
print(singleNumber(a))
