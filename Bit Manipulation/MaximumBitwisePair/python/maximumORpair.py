def maxORpair(arr, n):
    maxVal = max(arr)
    m = 0

    for i in range(n):
        m = max(m, (maxVal | arr[i]))
    
    return m

n = int(input())

arr = list(map(int, input().split()))

m = maxORpair(arr, n)

print(m)