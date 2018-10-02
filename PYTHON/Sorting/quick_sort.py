def main():
    print("Result-> "+str(quicksort([2, 7, 9, 3, 1, 6, 5, 4])))

def quicksort(arr):
    pivot = arr[len(arr)-1]
    wall = 0

    for i in range(len(arr)):
        if arr[i] < pivot:
            swap_elements(arr, wall, i)
            wall += 1

    # switch the pivot with the first element on the right side of the wall
    if wall < len(arr)-1:
        swap_elements(arr, wall, len(arr)-1)
        wall+=1

    left = arr[:wall]
    right = arr[wall:]

    # Do not remove the if statements, else recursion hell :)
    if len(left) > 1:
        arr[:wall] = quicksort(left)
    if len(right) > 1:
        arr[wall:] = quicksort(right)

    return arr

    
def swap_elements(arr, wall, i):
    buffer = arr[wall]
    arr[wall] = arr[i]
    arr[i] = buffer


if __name__ == "__main__":
    main()