def ternary_search(ar, l, r, key):
 
    if (r >= l):
        # Find the mid1 and mid2
        mid1 = l + (r - l) //3
        mid2 = r - (r - l) //3
         
        if (ar[mid1] == key):  
            return mid1
        if (ar[mid2] == key):  
            return mid2
           
        if (key < ar[mid1]):  
            # The key lies in between l and mid1
            r = mid1 - 1
            return ternary_search(ar, l, r, key)
 
        elif (key > ar[mid2]):  
            # The key lies in between mid2 and r
            l = mid2 + 1
            return ternary_search(ar, l, r, key)
         
        else:  
            # The key lies in between mid1 and mid2
            l = mid1 + 1
            r = mid2 - 1
            return ternary_search(ar, l, r, key)
         
    return -1

# Driver Code
arr = [int(item) for item in input("Enter the array elements : ").split()]
key = int(input("Enter the number to be searched : "))
arr.sort()
l = 0
r = len(arr) - 1
print("Index of key is :",ternary_search(arr, l, r, key))
