/**
 * Shell Sort
 * Shellsort, also known as Shell sort or Shell's method, is an in-place comparison sort. 
 * It can be seen as either a generalization of sorting by exchange or sorting by insertion. 
 * The method starts by sorting pairs of elements far apart from each other, then progressively reducing
 *  the gap between elements to be compared.
 * 
 * https://en.wikipedia.org/wiki/Shellsort
 * 
 */

#include <stdio.h>

void shellsort(int size, int *arr) {
    // start with a big gap and reduce it
    for (int gap = size/2; gap > 0; gap = gap/2) {
        for (int i = gap; i < size; i = i+1) {
            int temp = arr[i];

            int j;
            // shifting elements until the location for arr[i] is found
            for (j = i; j >= gap && arr[j-gap] > temp; j = j-gap) {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

// main function contains the driver code for testing. 
int main() {
    int arr_size = 6;
    int arr[6] = {10, 9, 8, 7, 6, 5 };
    shellsort(arr_size, arr);

    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
