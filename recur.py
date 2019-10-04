def main():
    print("Order = "+str(bubble_sort([9, 1, 2, 7, 4, 6, 5, 3])))

def bubble_sort(ar):
    while True:
        sorted = True
        for i in range(len(ar)-1):
            if(ar[i] > ar[i+1]):
                buff = ar[i+1]
                ar[i+1] = ar[i]
                ar[i] = buff
                sorted = False
        if(sorted):
            return ar
            break

if __name__ == "__main__":
    main()
