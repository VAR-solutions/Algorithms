"""
Here is the implementation of quicksort algorithm in python by Pramod Bharti
quick_sort() function takes an unsorted array and prints sorted array 
"""
def quick_sort(arr):
	if len(arr) <= 1:
		return arr
	pivot = arr[len(arr) // 2]
	left = [x for x in arr if x < pivot]
	middle = [x for x in arr if x == pivot]
	right = [x for x in arr if x > pivot]
	return quick_sort(left) + middle + quick_sort(right)

print (quick_sort([5,2,8,3,9,12,43])) # This will print [2,3,5,8,9,12,43]
