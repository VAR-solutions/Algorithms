# bottom-up rod cutting dp method
def min_rod_cutting_cost(p, n):
    r = [0]*(n + 1)
    for i in range(1, n + 1):
        q = -1000000
        for j in range(1, i + 1):
            q = max(q, p[j - 1] + r[i - j])
        r[i] = q
    return r[n]

def extended_bottom_cut_rod(p, n):
    r, s = [0]*(n + 1), [0]*(n + 1)
    for i in range(1, n + 1):
        q = -1000000
        for j in range(1, i + 1):
            if q < (p[j - 1] + r[i - j]):
                q = (p[j - 1] + r[i - j])
                s[i] = j
        r[i] = q
    return (r, s)

def print_cut_rod(p, n):
    (r, s) = extended_bottom_cut_rod(p, n)
    while n > 0: # print steps
        print(s[n], end=" ")
        n -= s[n]

n = int(input())
p = [int(x) for x in input().split()]
print(min_rod_cutting_cost(p, n)) # minimum cut rod cost
print_cut_rod(p, n) # steps to reach minimum cost
