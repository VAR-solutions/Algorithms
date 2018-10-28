def test_generate_array():
    """ Call generate_array() 10 times and check if array is sorted 

        Raise exception if test found any error
    """
    for i in range(10):
        array = generate_array()
        for j in range(1, len(array) - 1):
            if array[j] > array[j + 1]:
                raise "Error: array is not sorted"

def test_exponential_search():
    """ Call exponential_search() twice for each element, first time search element existing in array,
            second time search element not existing in array

        Raise exception if test find any error
    """

    array = generate_array()
    for element in array:
        position = exponential_search(array, element)
        if 0 > position or position >= len(array):
            raise "Error: element has to be found"

        position = exponential_search(array, max(array) + 1)
        if 0 < position < len(array):
            raise "Error: element hasn't to be found"

def test_binary_search():
    """ Call binary_search() twice for each element, first time search element existing in array,
            second time search element not existing in array

        Raise exception if test find any error
    """

    array = generate_array()
    for element in array:
        position = binary_search(array, 0, len(array) - 1, element)
        if 0 > position or position >= len(array):
            raise "Error: element has to be found"

        position = binary_search(array, 0, len(array) - 1, max(array) + 1)
        if 0 < position < len(array):
            raise "Error: element hasn't to be found"

def test():
    """ Exceute all tests """
    tests = [
        test_generate_array(),
        test_exponential_search(),
        test_binary_search()
    ]

    for test in tests:
        try:
            test()
        except:
            return False

    return True

def generate_array():
    """ Generate sorted array with 10 random integer numbers between 0 and 20 """
    
    # if this function was executed multiple times, python does not 
    #   import numpy after first time, to avoid memory duplicates
    import numpy as np

    array = np.random.randint(0, 20, 10)
    sorted_array = np.sort(array)
    return sorted_array

def exponential_search(array, key):
    """ Search for an element key in array 

    Params:
        array(np.ndarray): array with sorted integer numbers
        key(int): element to be search in array

    Returns:
        -1 if element key not found
        int: first key find in array
    """

    if array[0] == key:
        return 0

    i = 1
    while(i < len(array) and array[i] <= key):
        i = i * 2

    return binary_search(array, i//2, min(i, len(array) - 1), key)

def binary_search(array, left, right, key):
    """ Search for an element key in array 

    Params:
        array(np.ndarray): array with sorted integer numbers
        left(int): index array with lower limit of search space in array
        right(int): index array with upper limit of search space in array
        key(int): element to be search in array

    Returns:
        -1 if element key not found
        int: first key found in array
    """

    if right >= left :
        middle = left + (right - left) // 2

        if array[middle] == key:
            return middle

        if array[middle] > key:
            return binary_search(array, left, middle - 1, key)

        return binary_search(array, middle + 1, right, key)

    return -1

def main():
    # after execute this function all code works
    test()

    array = generate_array()
    element1 = max(array)
    element2 = -1

    print(f"array: {array}")
    print(f"search for: {element1}")
    print(f"    result: {exponential_search(array, element1)}")
    print(f"search for: {element2}")
    print(f"    result: {exponential_search(array, element2)}")

if __name__ == '__main__':
    main()