# Minimum coins needed for a value
def get_change(m, c):
    n = len(c)
    s = [m]*(m + 1)
    s[0] = 0
    for i in xrange(1, m + 1):
    	for j in xrange(n):
    		if i >= c[j] and s[i - c[j]] + 1 < s[i]:
    			s[i] = s[i - c[j]] + 1
    return s[m]

if __name__ == '__main__':
    m = int(raw_input())
    # c = [1, 3, 4]
    c = map(int, raw_input().split())
    print(get_change(m, c))