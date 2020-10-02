import timeit

if __name__ == '__main__':
    n = int(input("Enter n: "))
    start = timeit.default_timer()
    arr = [2, 3, 5, 7]
    for i in range(9,n,2):
        for j in arr:
            if i%j == 0:
                break
        else:
            arr.append(i)
    stop = timeit.default_timer()
    print(arr)
    print("Number of primes: ", len(arr))
    print("Time: ", stop-start)
