# Uses python3
def longest_increasing_subsequence(seq):
    """
    Returns the length of the longest 'strictly' increasing subsequence.
    If you want length of the longest non-decreasing, then modify this function,
    by adding equal operator while comparing 'seq' elements.
    :param seq: list of integers
    :return: length of the longest strictly increasing subsequence
    """
    if not seq:
        return 0

    n = len(seq)
    dp = [1] * n
    for i in range(1, len(seq)):
        for j in range(0, i):
            if seq[i] > seq[j]:
                dp[i] = max(dp[i], dp[j] + 1)

    ans = 1
    for i in range(0, n):
        ans = max(ans, dp[i])
    return ans


if __name__ == "__main__":

    # test case 1
    assert longest_increasing_subsequence([]) == 0, "ans should be 0"
    # test case 2
    assert longest_increasing_subsequence([1, 2, 3, 4, 5]) == 5, "ans should be 5"
    # test case 3
    assert longest_increasing_subsequence([5, 4, 3, 2, 1]) == 1, "ans should be 1"
    # test case 4
    assert longest_increasing_subsequence([5, 4, 1, 2, 4, 3, 0, 4]) == 4, "ans should be 4"
    # test case 5
    assert longest_increasing_subsequence([0, 4, 1, 2, 4, 3, 0, 4]) == 5, "ans should be 5"
    # test case 6
    assert longest_increasing_subsequence([4, 4, 4, 4]) == 1, "ans should be 1"

