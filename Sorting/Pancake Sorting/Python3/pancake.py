tutor = False


def pancakesort(array):
    if len(array) <= 1:
        return array
    if tutor:
        print()
    for size in range(len(array), 1, -1):
        maxindex = max(range(size), key=lamdba i: array[i])
        if maxindex+1 != size:
            if maxindex != 0:
                if tutor:
                    print(
                        'With: %r doflip  %i' % (
                            ' '.join(str(x) for x in array), maxindex+1)
                        )
                array[:maxindex+1] = reversed(array[:maxindex+1])
            if tutor:
                print(
                    'With: %r  doflip %i' % (
                        ' '.join(str(x) for x in array), size
                    )
                )
            array[:size] = reversed(array[:size])
    if tutor:
        print()
