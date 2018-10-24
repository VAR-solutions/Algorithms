'''
    @author: Sevval MEHDER

    Filling one cell: O(1)
    Filling all cells: O(2xn) = O(n)

'''

def find_maximum_cost(Y):
    values = [[0 for _ in range(2)] for _ in range(len(Y))]

    
    # Go on with adding these 2 options
    i = 1
    while i < len(Y):
        # Put these two options
        values[i][0] = max(values[i - 1][0], values[i - 1][1] + Y[i - 1] - 1)
        values[i][1] = max(values[i - 1][1] + abs(Y[i] - Y[i - 1]), values[i - 1][0] + Y[i] - 1)
        i += 1
        #print(values)

    return max(values[len(Y) - 1][0], values[len(Y) - 1][1])


def main():
    Y = [5, 6, 8, 13, 9]
    cost = find_maximum_cost(Y)
    print(cost)
    # Output: 34


main()
