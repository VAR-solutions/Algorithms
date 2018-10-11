def get_majority(a):
    n = len(a)
    if n == 1:
        return a[0]
    k = n // 2
    left_major = get_majority(a[:k])
    right_major = get_majority(a[k:])
    if left_major == right_major:
        return left_major
    left_count = sum(1 for i in a if i == left_major)
    right_count = sum(1 for i in a if i == right_major)
    if left_count > k:
        return left_major
    elif right_count > k:
        return right_major
    else:
        return -1

n = int(input())
a = [int(x) for x in input().split()]
print(get_majority(a))
