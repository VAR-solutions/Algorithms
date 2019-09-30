from bisect import bisect_left
from heapq import merge


class Pile(list):
    def __lt__(self, num): return self[-1] < num[-1]

    def __eq__(self, num): return self[-1] == num[-1]


def patience_sort(array):
    piles = []
    for elem in array:
        curr = Pile([elem])
        i = bisect_left(piles, curr)
        if i != len(piles):
            piles[i].append(elem)
        else:
            piles.append(curr)

    return list(merge(*[reversed(pile) for pile in piles]))


if __name__ == "__main__":
    a = [4, 65, 2, -31, 0, 99, 83, 782, 1]
    print(patience_sort(a))
