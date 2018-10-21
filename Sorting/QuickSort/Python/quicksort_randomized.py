import random

def partition3(a, l, r):
    x = a[l]
    i = l + 1
    lt = l
    gt = r
    while i <= r and lt <= gt:
        if a[i] < x:
            a[lt], a[i] = a[i], a[lt]
            lt += 1
            i += 1
        elif a[i] > x:
            a[gt], a[i] = a[i], a[gt]
            gt -= 1
        else:
            i += 1
    return lt, gt

def randomized_quick_sort(a, l, r):
    if l >= r:
        return
    k = random.randint(l, r)
    a[l], a[k] = a[k], a[l]
    lt, gt = partition3(a, l, r)
    randomized_quick_sort(a, l, lt - 1);
    randomized_quick_sort(a, gt + 1, r);

if __name__ == '__main__':
    n = int(input())
    a = [int(x) for x in input().split()]
    randomized_quick_sort(a, 0, n - 1)
    for x in a:
        print(x, end=' ')
