# Author Shubham Bindal

def insertion_sort(array,n): 
    # base case 
    if n<=1: 
        return
      
    insertion_sort(array,n-1)
    
    last = array[n-1] 
    j = n-2
      
    while (j>=0 and array[j]>last): 
        array[j+1] = array[j] 
        j = j-1
  
    array[j+1]=last 
      
def print_arrayay(array,n): 
    for i in range(n): 
        print (array[i] , end=' ') 
  
array = list(map(int,input("Enter the numbers to be sorted\n").split())) 
n = len(array) 
insertion_sort(array, n) 
print_arrayay(array, n) 
