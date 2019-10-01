# Python3 program to sort an array 
# using bucket sort 
			
def bucketSort(x): 
	arr = [] 
	slot_num = 10 # 10 means 10 slots, each 
				# slot's size is 0.1 
	for i in range(slot_num): 
		arr.append([]) 
		
	# Put array elements in different buckets 
	for j in x: 
		index_b = int(slot_num * j) 
		arr[index_b].append(j) 
	
	# Sort individual buckets 
	for i in range(slot_num): 
		arr[i] = insertionSort(arr[i]) 
		
	# concatenate the result 
	k = 0
	for i in range(slot_num): 
		for j in range(len(arr[i])): 
			x[k] = arr[i][j] 
			k += 1
	return x 

