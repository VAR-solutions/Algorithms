def insertionSort(arr): 
    for i in range(1, len(arr)): 
        key = arr[i] 
        j = i-1
        while j >=0 and key < arr[j] : 
                arr[j+1] = arr[j] 
                j -= 1
        arr[j+1] = key 

n = int(input())
arr = []
for _ in range(n):
    x = int(input())
    arr.append(x)    

insertionSort(arr) 
for i in range(len(arr)): 
    print ("%d" %arr[i]) 