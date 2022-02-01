import timeit

TEXT = "but it's exactly these questions that allow me to find an answer fast if I'm just 'looking it up' on google."
print("TEXT:" , TEXT)
print("Pattern :")

PATTERN = input() # Enter the Pattern to be searched

def KMP(text, pattern):
    found_it = False
    match = False
    check_from  = 0
    sp_index = getIndex(pattern)
    for i in range(0, len(text)):
        for j in range( check_from, len(pattern)):
            if(text[i] == pattern[j]):
                match = True
                i+=1
            else:
                match = False
                break
        if match == False:
            check_from = sp_index[j -1]
        else:
            print("Found '" + str(pattern) + "' at Position " + str(i-j))
            found_it = True
            break

    if not found_it:
        print("No Match Found")

def getIndex(pattern):
    sp_index = [0,]
    j = 0
    for i in range(1, len(pattern)):
        if pattern[j] == pattern[i]:
            j += 1
            sp_index.append(j)
        else:
            while(j > 0):
                j = j-1
                j = sp_index[j]
                if pattern[j] == pattern[i]:
                    j += 1
                    break
            sp_index.append(j)
    return sp_index

start = timeit.timeit() # Start Time
#Start Search
KMP(TEXT, PATTERN)
end = timeit.timeit() # End Time
print("Time Taken:" + str(end))


