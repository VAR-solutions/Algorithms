# Author : Shubham Bindal


# Binary Search is better than Jump Search
# but Jump search has an advantage that we traverse back only once
#(Binary Search may require up to O(Log n) jumps
# consider a situation where the element to be search is the smallest element
# or smaller than the smallest).
# So in a systems where jumping back is costly, we use Jump Search.

import math

def jump_search( arr , x , n ): 
      
    block_size = int(math.sqrt(n))
    
    index = 0
    while arr[int(min(block_size, n)-1)] < x: 
        index = block_size 
        block_size += int(math.sqrt(n)) 
        if index >= n: 
            return -1
      
    # perform linear search for x in block beginning with index. 
    while arr[int(index)] < x: 
        index += 1
          
        if index == min(block_size, n): 
            return -1
       
    if arr[int(index)] == x: 
        return index 
      
    return -1

# driver code

# give elements in sorted order
print("Enter the elements of the sorted array in a single line: ")

arr = list(map(int,input().split()))
num = int(input("Enter the number you want to search\n"))

n = len(arr)

(jump_search(arr,num,n))
 
index = jump_search(arr, num, n)

print("Searched_number" , num, "is at index" ,"%.0f"%index) 
