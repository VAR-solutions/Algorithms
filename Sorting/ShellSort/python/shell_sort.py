def shellsort(arr,n):
    gap = n//2
    # increase with a large gap and decrease it slowly
    while gap>0:
        for i in range(gap,n):
            temp = arr[i]

            j = i
            while j >= gap and arr[j-gap] > temp:
                arr[j] = arr[j-gap]
                j -= gap

            arr[j] = temp
        gap = gap//2

    return arr

# driver code
def main():
    arr = [15,14,13,12,11,10] 
    arr = shellsort(arr,len(arr))
    print(arr)


if __name__ == '__main__':
    main()
