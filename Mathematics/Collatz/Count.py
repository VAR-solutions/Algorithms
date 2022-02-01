
#Print the number of operations (Collatz conjecture) until we get 1
#According to the conjecture, there is not gurrante that this function will end at 1.
#For more details - https://en.wikipedia.org/wiki/Collatz_conjecture
def Collatz_count(num):
    count =0
    val = num
    while (val!=1):
        count=count+1
        if (val%2==0):
            val = val/2
        else:
            val = (val *3)+1
    return count



#Basic tests
print Collatz_count(4) #2 (4->2->1)
print Collatz_count(3) #7  (3->10->5->16->8->4->2>1)
