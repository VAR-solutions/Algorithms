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


print("Enter the elements of the array in a single line: ")
a = list(map(int,input().split()))
num = int(input("Enter the number you want to search"))
print(binarySearch(a,num,0,len(a)))