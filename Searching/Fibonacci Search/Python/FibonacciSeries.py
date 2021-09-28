arr = list(map(int, input("Enter the Array: ").rstrip().split()))
x=int(int(input("Enter the number you are looking for:" )))

def FibonacciSeries(n):
    if n < 1:
        return 0
    elif n == 1:
        return 1
    else:
        return FibonacciSeries(n - 1) + FibonacciSeries(n - 2)
        
def FibonacciSearch(arr, x):
    m = 0 
    while FibonacciSeries(m) < len(arr): 
        m = m + 1 
    offset = -1    
    while (FibonacciSeries(m) > 1):
        i = min( offset + FibonacciSeries(m - 2) , len(arr) - 1)
        if (x > arr[i]):
            m = m - 1
            offset = i
        elif (x < arr[i]):
            m = m - 2
        else:
            return i        
    if(FibonacciSeries(m - 1) and arr[offset + 1] == x):
        return offset + 1
    return -1
print('Number found at index : ',FibonacciSearch(arr, x))
