def main():
    print("Result-> "+str(tim_sort([2, 4, 9, 3, 1, 6, 5, 7])))
    
def tim_sort(arr):
    # Python's built in sorting algo is timsort.
    return sorted(arr)
    
if __name__ == "__main__":
    main()
