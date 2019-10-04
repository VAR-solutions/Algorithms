from bisect import bisect_left 

### Example ###
#### arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100] 
### n = len(arr) 
### x = 85
### print(f"Found at index: {fib_monaccianSearch(arr, x, n)}") 
### ### ### ###

def fib_monaccianSearch(arr, x, n):
    '''# Returns index of x if present, else returns -1 '''

	fib_0 = 0 
	fib_1 = 1 
	fib_m = fib_0 + fib_1

	while (fib_m < n): 
		fib_0 = fib_1 
		fib_1 = fib_m 
		fib_m = fib_0 + fib_1 

	offset = -1; 
	while (fib_m > 1): 
		i = min(offset+fib_0, n-1) 

		if (arr[i] < x): 
			fib_m = fib_1 
			fib_1 = fib_0 
			fib_0 = fib_m - fib_1 
			offset = i 

		elif (arr[i] > x): 
			fib_m = fib_0 
			fib_1 = fib_1 - fib_0  
			fib_0 = fib_m - fib_1 

		else : 
			return i 


	if(fib_1 and arr[offset+1] == x): 
		return offset+1; 
	return -1
