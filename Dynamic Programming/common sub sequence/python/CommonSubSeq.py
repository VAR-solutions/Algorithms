#@Params: 2 strings
#@Returns: a set containing the longest common substring
def lcs(string1,string2):
    m = len(string1)
    n = len(string2)
    counter = [[0]*(n+1) for x in range(m+1)]
    longest = 0
    lcs_set = set()
    for i in range(m):
        for j in range(n):
            if string1[i] == string2[j]:
                c = counter[i][j] + 1
                counter[i+1][j+1] = c
                if c > longest:
                    lcs_set = set()
                    longest = c
                    lcs_set.add(string1[i-c+1:i+1])
                elif c == longest:
                    lcs_set.add(string1[i-c+1:i+1])

    return lcs_set
