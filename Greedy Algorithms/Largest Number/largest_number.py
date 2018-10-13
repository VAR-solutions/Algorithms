def largest_number(a):
    res = ""
    while a:
        max_index = 0
        for i in range(1, len(a)):
            if int(str(a[i]) + str(a[max_index])) > int(str(a[max_index]) + str(a[i])):
                max_index = i
        res += str(a[max_index])
        del a[max_index]
    return res

if __name__ == '__main__':
    input = int(input()) # number of numbers in list
    a = [int(x) for x in input().split()] # input list of numbers
    print(largest_number(a))
