# Uses python2
def edit_distance(s, t):
    m, n = len(s), len(t)
    dp = [[0]*(n + 1) for i in xrange(m + 1)]
    for i in xrange(m + 1):
    	for j in xrange(n + 1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            elif s[i - 1] == t[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
    			dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]))
    return dp[m][n]

if __name__ == "__main__":
    print(edit_distance(raw_input(), raw_input()))
