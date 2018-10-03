# Builds a max heap in an array with the specified root
def heapify(array, size, root)
    left = 2*root + 1  # left child of the root
    right = 2*root + 2 # right child of the root 

    largest = root # set root to be the largest element

    if left < size and array[left] > array[largest]
        largest = left
    end
    if right < size and array[right] > array[largest]
        largest = right
    end

    # If root was not the largest element, reposition and build a max heap
    if largest != root
        array[largest], array[root] = array[root], array[largest]
        heapify(array, size, largest)
    end
end

# Sorts the array in assending order
def heap_sort(array)
    size = array.length
    i = (size/2) - 1
    # build a max heap from the array
    (size/2).times do
        heapify(array, size, i)
        i = i - 1
    end

    # extract elements from the heap one by one
    i = size-1
    size.times do
        array[0], array[i] = array[i], array[0] 
        # rebuild heap excluding elements that are placed correctly
        heapify(array, i, 0)
        i = i - 1
    end
end

# Dummy data for testing 
test_array = [7, 6, 5, 4, 3, 2, 1]
# Display unsorted array
puts "Unsorted Array:"
puts test_array.join(' ')
# Call heap sort on the array
heap_sort(test_array)
# Display the sorted results 
puts "Post Heap Sort"
puts test_array.join(' ')

