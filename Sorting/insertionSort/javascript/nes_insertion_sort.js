/**
 * @param {array} array Array of number that you want to sort.
 * @returns {array} Array of number that sort by ascending order.
 * 
 * ---
 * Example videos https://www.youtube.com/watch?v=OGzPmgsI-pQ
 */
function InsertionSort(array) {
  let len = array.length     	// number of items in the array.
  let value                   // the value currently being compared.
  let i                       // index into unsorted section.
  let j                       // index into sorted section.

  for (i = 1; i < len; i++) {
    // store the current value.
    value = array[i]
    j = i - 1

    // Whenever the value in the sorted section is greater than the value
    // in the unsorted section, shift all items in the sorted section over
    // by one. This creates space in which to insert the value.
    while (j >= 0 && array[j] > value) {
      array[j + 1] = array[j]
      j--
    }
    array[j + 1] = value
  }
  return array
}

// expect result to equals [ 1, 2, 2, 3, 5, 7, 7, 8, 9 ]
console.log(InsertionSort([5, 2, 7, 2, 1, 3, 9, 8, 7]))
