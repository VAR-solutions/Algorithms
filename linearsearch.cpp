# Python3 code to linearly search x in arr[]. 
# If x is present then return its location, 
# otherwise return -1 

def search(arr, n, x): 

	for i in range (0, n): 
		if (arr[i] == x): 
			return i; 
	return -1; 

# Driver Code 
arr = [ 2, 3, 4, 10, 40 ]; 
x = 10; 
n = len(arr); 
result = search(arr, n, x) 
if(result == -1): 
	print("Element is not present in array") 
else: 
	print("Element is present at index", result); 
