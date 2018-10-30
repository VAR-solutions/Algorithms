import time

# Function that takes a list and sorts using radix sort implementation
def radixsort(toBeSorted):

    digit = 1
    atTheEnd = False
    r = 10  # The base of the numbers we choose to sort

    while not atTheEnd:
        # Only remains true if we are calculating for the highest significant digit.
        atTheEnd = True

        # Initialize the bins which are a series of lists
        bins = [list() for _ in range(r)]

        # Place items inside toBeSorted buffer into their respective bins
        for i in toBeSorted:
            temp = i / digit
            bins[temp % r].append(i)
            if temp > 0:
                atTheEnd = False

        # Put the items in the bins back into the toBeSorted buffer
        toBeSortedIndex = 0
        for i in range(r): # Goes through each bin
            bin = bins[i]
            for j in bin: # Goes through each element in a given bin
                toBeSorted[toBeSortedIndex] = j
                toBeSortedIndex = toBeSortedIndex + 1

        # Increment to sort by the next digit
        digit = digit * r

A = [201, 12, 1323, 32, 58, 91, 2, 1, 13, 13314, 21230, 1000, 1200]
print "Unsorted list: "
print A

start = time.time()
radixsort(A)
end = time.time()

print "Sorted list: "
print A
print "Time Taken: "
print str(end - start) + "ms"
