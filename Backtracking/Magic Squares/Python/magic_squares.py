"""
Magic square is a square filled with numbers starting with one
in a way that the sum of each row, column and diagonal is the same.

The following algorithm uses a recursive approach, it could
be implemented iteratively but the algorithm would be way longer.

"""


import time

start = time.time()


def expected_row_sum(square_size):
    """Calculates the expected row sum based on square size."""
    return int(sum(range(1, square_size ** 2 + 1)) / square_size)


def get_column(square_size, square, i):
    """Returns an i-th column of a square."""
    expected_modulo = i % square_size
    col = []
    for i, item in enumerate(square):
        if i % square_size == expected_modulo:
            col.append(item)
    return col


def magic_squares(square_size, square=None, used=None, i=0):
    if square is None:
        square = [None for _ in range(square_size ** 2)]
    if used is None:
        used = [False for _ in range(square_size ** 2)]
    row_sum = expected_row_sum(square_size)
    if i == square_size ** 2:
        # left to right diagonal, for size 3, the indexes are 0, 4, 8 (increments by 4 to get the next field so that
        # is square_size + 1)
        d1_sum = 0
        for j in range(square_size):
                d1_sum += square[j * (square_size + 1)]
        # right to left diagonal, for size 3, the indexes are 2, 4, 6 (increments by 2 to get the next field so that
        # is square_size - 1. Also starts at 2 not 0.
        d2_sum = 0
        for j in range(square_size):
            d2_sum += square[(j + 1) * (square_size - 1)]

        if d1_sum == row_sum and d2_sum == row_sum:
            cp = list(square)
            yield [[cp.pop(0) for _ in range(square_size)] for __ in range(square_size)]
    else:
        # try to insert all possible numbers - backtracking
        for n in range(1, square_size ** 2 + 1):
            square[i] = n
            if not used[n - 1]:
                # check row sum after each row
                if (i + 1) % square_size == 0:
                    if sum(square[i - square_size + 1: i + 1]) != row_sum:
                        continue
                # if we are on the last line, check column
                if i >= square_size * (square_size - 1):
                    if sum(get_column(square_size, square, i)) != row_sum:
                        continue
                used[n - 1] = True

            else:
                continue

            # yield from gets the result from the lowest recursion level, works only in py 3.3+, slower alternative:
            # for s in magic_squares(square_size, square, used, i + 1):
            #    yield s
            yield from magic_squares(square_size, square, used, i + 1)
            # reset to the previous state
            used[n - 1] = False


number_of_solutions = 0
for sq in magic_squares(3):
    number_of_solutions += 1
    for line in sq:
        print(' '.join([str(x) for x in line]))
    print('\n')

print(number_of_solutions)

print('--- %s seconds ---' % (time.time() - start))
