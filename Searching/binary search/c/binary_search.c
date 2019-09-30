int binary_search(int *arr, int size, int item) {
  int first = 0;
  int last = size - 1;
  int middle;

  while (first <= last) {
    middle = (last + first) / 2;
    if (arr[middle] == item) {
      return middle;
    }

    if (item < arr[middle]) {
      last = middle - 1;
    } else if (item > arr[middle]) {
      first = middle + 1;
    }
  };

  return -1;
}
