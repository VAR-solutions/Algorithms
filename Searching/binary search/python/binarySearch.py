def binarySearch(A,num,l,r):
    mid = l + (r-l)//2
    if r >= l:
        if A[mid] == num:
          return("Found")
        elif A[mid] > num:
            return binarySearch(A,num,l,mid-1)
        elif A[mid] < num:
            return binarySearch(A,num,mid+1,r)
    else: 
        return("Not Found")
   

#this non recursive function will return index as well. e is the element to be searched
def non_recursive_binary_search(a,n,e):
    i,j=0,n-1
    while i<=j:
        m=(i+j)//2
        if a[m]==e:
            return 'found at index ' + str(m)

        #seach in the right half
        if e>a[m]:
            i=m+1

        #search in the left half
        else:
            j=m-1

    return 'Element not found'


print("Enter the elements of the array in a single line: ")
a = list(map(int,input().split()))
num = int(input("Enter the number you want to search"))
print(binarySearch(a,num,0,len(a)))

#test the non recursive function and see if both the functions yield the same result
print(non_recursive_binary_search(a,len(a),num))
