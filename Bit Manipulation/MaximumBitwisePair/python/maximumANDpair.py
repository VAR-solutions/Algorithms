def checkPair(currVal, arr, n):
    count = 0

    for i in range(n):
        if (currVal & arr[i]) == currVal:
            count += 1
    
    return count

def maxANDpair(arr, n):
    maxVal = 0

    for bit in range(31, -1, -1):
        count = checkPair(maxVal | (1 << bit), arr, n)

        if count >= 2:
            maxVal = maxVal | (1 << bit)
    
    return maxVal

n = int(input())

arr = list(map(int, input().split()))

m = maxANDpair(arr, n)

print(m)