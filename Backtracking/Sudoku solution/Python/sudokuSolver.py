#Written by PeeyushKumar

import os

grid = [[5, 3, 0,  0, 7, 0,  0, 0, 0],
        [0, 0, 0,  1, 0, 0,  0, 0, 0],
        [0, 9, 8,  0, 0, 0,  0, 6, 0],

        [8, 0, 0,  0, 6, 0,  0, 0, 3],
        [0, 0, 0,  0, 0, 0,  0, 0, 0],
        [0, 0, 0,  0, 0, 0,  0, 0, 0],

        [0, 6, 0,  0, 0, 0,  2, 0, 0],
        [0, 0, 9,  0, 1, 0,  0, 0, 0],
        [0, 0, 0,  0, 0, 0,  0, 7, 0]]


def show_grid(grid):
    for i in range(len(grid)):
        if i % 3 == 0 and i != 0:
            print('-------------------------------')
        for j in range(len(grid)):

            if j % 3 == 0 and j != 0:
                print('|  ', end='')

            if grid[i][j]:
                print(grid[i][j], ' ', end='')
            else:
                print(' ', ' ', end='')

            if j == 8:
                print()


def find_empty(grid):
    for i in range(len(grid)):
        for j in range(len(grid)):
            if grid[i][j] == 0:
                return (i, j)


def put_if_valid(pos, value, grid):
    row, col = pos
    for i in range(len(grid)):
        if grid[row][i] == value or grid[i][col] == value:
            return False

    subrow = 3*(row//3)
    subcol = 3*(col//3)
    for i in range(subrow, subrow+3):
        for j in range(subcol, subcol+3):
            if grid[i][j] == value:
                return False

    grid[row][col] = value
    return True


def solve(grid):
    show_grid(grid)
    pos = find_empty(grid)
    if not pos:
        return True

    for value in range(1, 10):
        if put_if_valid(pos, value, grid):
            os.system('clear')
            if solve(grid):
                return True
            grid[pos[0]][pos[1]] = 0

    return False


if solve(grid):
    os.system('clear')
    show_grid(grid)
else:
    print("Impossible")
