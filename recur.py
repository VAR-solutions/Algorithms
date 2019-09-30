def main():
    print("Order = "+str(bubble_sort([9, 1, 2, 7, 4, 6, 5, 3])))

def bubble_sort(arr):
    while True:
        sorted = True
        for i in range(len(arr)-1):
            if(arr[i] > arr[i+1]):
                buff = arr[i+1]
                arr[i+1] = arr[i]
                arr[i] = buff
                sorted = False
        if(sorted):
            return arr
            break

if __name__ == "__main__":
    main()
