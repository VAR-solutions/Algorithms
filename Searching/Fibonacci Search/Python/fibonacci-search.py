# function to generate a Fibonacci number at the index of n
def FibonacciGenerator(n):
    if n < 1:
        return 0
    elif n == 1:
        return 1
    else:
        return FibonacciGenerator(n - 1) + FibonacciGenerator(n - 2)

# function that divides the list and search for the number as per the Fibonacci Search
def FibonacciSearch(arr, x):
    m = 0 
    while FibonacciGenerator(m) < len(arr):
        m = m + 1 
    offset = -1
    while (FibonacciGenerator(m) > 1):
        i = min( offset + FibonacciGenerator(m - 2) , len(arr) - 1)
        # We can comment the line below if we don't want to see at the pointer pointing to values at a given time
        print('Currently pointing at index '+str(i)+ ' viewing ' +str(arr[i]))
        if (x > arr[i]):
            m = m - 1
            offset = i
        elif (x < arr[i]):
            m = m - 2
        else:
            return i        
    if(FibonacciGenerator(m - 1) and arr[offset + 1] == x):
        return offset + 1
    return -1

# function to print the result
def result(ind):
    if ind == -1:
        print('Number is not present in the list.')
    else:
        print('Number is present at index : ',ind)

# main driver function
def main():
    arr = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31] 
    
    # Case 1 : Searching for a number which is present in the list
    x = 19
    ind = FibonacciSearch(arr, x)
    result(ind)

    # Case 2 : Searching for a number which is present in the list
    x = 15
    ind = FibonacciSearch(arr, x)
    result(ind)

main()
