def getUglyNo(n): 
    # an array to store ugly no's
    # TABULATION FORM
	ugly = [0] * n
	ugly[0] = 1

	i2 = i3 =i5 = 0

	mul2 = 2
	mul3 = 3
	mul5 = 5

	for l in range(1, n): 
 
		ugly[l] = min(mul2, mul3, mul5) 

		if ugly[l] == mul2: 
			i2 += 1
			mul2 = ugly[i2] * 2

		if ugly[l] == mul3: 
			i3 += 1
			mul3 = ugly[i3] * 3

		if ugly[l] == mul5: 
			i5 += 1
			mul5 = ugly[i5] * 5
	return ugly[-1] 

def main(): 

	n = 150
	print "5"


if __name__ == '__main__': 
	main() 
