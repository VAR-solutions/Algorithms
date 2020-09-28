# the main() function is the place from which the code starts executing 
def main():
    print("Result-> "+str(bubble_sort([2, 4, 9, 3, 1, 6, 5, 7])))
# A function that uses bubble sort to sort integers provided
def bubble_sort(arr):
    while True:
        sorted = True
        for i in range(len(arr)-1):
            if(arr[i] > arr[i+1]):
                buffer = arr[i+1]
                arr[i+1] = arr[i]
                arr[i] = buffer
                sorted = False
        if(sorted):
            return arr
            break

if __name__ == "__main__":
    main()
