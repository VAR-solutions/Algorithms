def cycle_sort(vector):
    "Sort a vector in place and return the number of writes."
    writes = 0

    for cycleStart, item in enumerate(vector):

        pos = cycleStart
        for item2 in vector[cycleStart + 1:]:
            if item2 < item:
                pos += 1

        if pos == cycleStart:
            continue

        while item == vector[pos]:
            pos += 1
        vector[pos], item = item, vector[pos]
        writes += 1

        while pos != cycleStart:

            pos = cycleStart
            for item2 in vector[cycleStart + 1:]:
                if item2 < item:
                    pos += 1

            while item == vector[pos]:
                pos += 1
            vector[pos], item = item, vector[pos]
            writes += 1

    return writes


if __name__ == '__main__':
    x = [0, 1, 2, 2, 2, 2, 1, 9, 3.5, 5, 8, 4, 7, 0, 6]
    xcopy = x[::]
    writes = cycle_sort(xcopy)
    if xcopy != sorted(x):
        print('Wrong order!')
    else:
        print('%r\nIs correctly sorted using cycleSort to'
              '\n%r\nUsing %i writes.' % (x, xcopy, writes))
