# Time complexity: O(nlogn)
def find_max_crossing_subarray(A, low, mid, high):
    sum, left_sum = 0, -1000000000000
    for i in range(mid, low - 1, -1):
        sum += A[i]
        if sum > left_sum:
            left_sum = sum
            max_left = i
    sum, right_sum = 0, -1000000000000
    for i in range(mid + 1, high + 1):
        sum += A[i]
        if sum > right_sum:
            right_sum = sum
            max_right = i
    return (max_left, max_right, left_sum + right_sum)

def find_max_subarray(A, low, high):
    if high == low:
        return (low, high, A[low])
    mid = (low + high) // 2
    left_low, left_high, left_sum = find_max_subarray(A, low, mid)
    right_low, right_high, right_sum = find_max_subarray(A, mid + 1, high)
    cross_low, cross_high, cross_sum = find_max_crossing_subarray(A, low, mid, high)
    if left_sum >= right_sum and left_sum >= cross_sum:
        return (left_low, left_high, left_sum)
    elif right_sum >= left_sum and right_sum >= cross_sum:
        return (right_low, right_high, right_sum)
    else:
        return (cross_low, cross_high, cross_sum)

n = int(input())
A = [int(x) for x in input().split()]
low, high, sum = find_max_subarray(A, 0, n - 1)
print(low, high, sum)
