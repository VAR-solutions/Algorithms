def largest_sum_contiguous_subarray(arr):
    max_now = 0
    max_next = 0
    for i in arr:
        max_next += i
        max_now = max(max_next, max_now)
        max_next = max(0, max_next)
    return max_now



arr = list(map(int,input().split()))
print('Maximum contiguous sum is', largest_sum_contiguous_subarray(arr))
