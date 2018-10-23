''' 
    @author: Sevval MEHDER
    
    Analysis:
    Filling one cell cost is O(1)
    Filling all cells cost is O(n.m)
    
'''


def findMaxSubPath(integersInMatrix):
    # First values
    f_row = len(integersInMatrix)
    f_col = len(integersInMatrix[0])

    # Make a empty 2d list like integersInMatrix
    values = [[None for _ in range(f_col)] for _ in range(f_row)]

    # Fill the new values array right to left
    for col in range(f_col):
        for row in range(f_row):

            # If the end of the path
            if col == 0:
                values[row][col] = integersInMatrix[row][col]

            # On top there are just 2 move: left or left-down
            elif row == 0:
                values[row][col] = integersInMatrix[row][col] + max(values[row][col - 1],
                                                                 values[row + 1][col - 1])

            # On bottom there are just 2 move: left or left-up 
            elif row == f_row - 1:
                values[row][col] = integersInMatrix[row][col] + max(values[row - 1][col - 1],
                                                                 values[row][col - 1])

            #In the middle we have 3 move: left-up, left and left-down
            else:
                values[row][col] = integersInMatrix[row][col] + max(values[row - 1][col - 1],
                                                                 values[row][col - 1],
                                                                 values[row + 1][col - 1])

    # Return the maximum row in the first col
    return max([values[i][-1] for i in range(len(integersInMatrix))])


def main():
    integersInMatrix =  [[1, 3, 33, 5],
                        [5, 8, 17, 1],
                        [23, 10, 7, 8],
                        [14, 10, 9, 7]]

    res = findMaxSubPath(integersInMatrix)
    print(res)
    # Output: 69


main()
