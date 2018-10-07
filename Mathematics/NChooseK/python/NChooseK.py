
def bin_coeff(n, k):
	ans = 1

	if(k > (n-k)):
		k = n-k
	
	for i in range(k):
		ans *= (n - i)
		ans /= (i + 1)
	
	return ans
