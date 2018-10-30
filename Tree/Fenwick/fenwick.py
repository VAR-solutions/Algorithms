
class fenwick:

	# Returns sum of arr[0..index]. This function assumes 
	# that the array is preprocessed and partial sums of 
	# array elements are stored in __Fenwick[]. 
	def getsum(i): 
	    s = 0 #initialize result 
	  
	    # index in __Fenwick[] is 1 more than the index in arr[] 
	    i = i+2
	  
	    # Traverse ancestors of __Fenwick[index] 
	    while i > 0: 
	  
		# Add current element of __Fenwick to sum 
		s += self.__Fenwick[i] 
	  
		# Move index to parent node in getSum View 
		i -= i & (-i) 
	    return s 
	

	# Updates a node in Fenwick tree at given index 
	# in __Fenwick. The given value 'val' is added to __Fenwick[i] and 
	# all of its ancestors in tree. 
	def updatebit(n , i ,v): 
	  
	    # index in __Fenwick[] is 1 more than the index in arr[] 
	    i += 2
	  
	    # Traverse all ancestors and add 'val' 
	    while i <= n: 
	  
		# Add 'val' to current node of fenwick Tree 
		self.__Fenwick[i] += v 
	  
		# Update index to that of parent in update View 
		i += i & (-i) 
	  

	  
	def construct(arr, n): 
	  
	    # Create and initialize __Fenwick[] as 0 
	    self.__Fenwick = [0]*(n+1) 
	  
	    # Store the actual values in __Fenwick[] using update() 
	    for i in range(n): 
		self.updatebit(n, i, arr[i]) 
