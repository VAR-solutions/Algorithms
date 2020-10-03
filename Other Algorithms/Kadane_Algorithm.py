// Kadane’s algorithm is a Dynamic Programming approach to solve “the largest contiguous elements in an array” with runtime of O(n).
// Kadane’s Algorithm, aka Maximum Sum of Subarray, is an interesting algorithm problem that can be used to solve Maximum Subarray Problem.


def max_subarray(A):
    max_so_far = A[0]
    elements_so_far = [A[0]]

    for x in A[1:]:
        if x > sum(elements_so_far + [x]):
            elements_so_far = [x]
        else:
            elements_so_far.append(x)

        max_so_far = max(max_so_far, sum(elements_so_far))

    return max_so_far
