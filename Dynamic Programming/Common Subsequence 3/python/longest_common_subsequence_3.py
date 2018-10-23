# Longest Common Sequence of 3 Sequences
def lcs3(a, b, c):
	n, m, p = len(a), len(b), len(c)
	dp = [[[0]*(p + 1) for i in xrange(m + 1)] for j in xrange(n + 1)]
	for i in xrange(n + 1):
		for j in xrange(m + 1):
			for k in xrange(p + 1):
				if i == 0 or j == 0 or k == 0:
					dp[i][j][k] = 0
				elif a[i - 1] == b[j - 1] and a[i - 1] == c[k - 1]:
					dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1]
				else:
					dp[i][j][k] = max(dp[i][j][k - 1], max(dp[i][j - 1][k], dp[i - 1][j][k]))
	return dp[n][m][p]

if __name__ == '__main__':
	a, b, c = raw_input().split()
	print(lcs3(a, b, c))