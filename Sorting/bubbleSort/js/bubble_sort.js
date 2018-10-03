
/*
 * Bubble sort, sometimes referred to as sinking sort,
 * is a simple sorting algorithm that repeatedly steps through the list to be sorted,
 * compares each pair of adjacent items and swaps them if they are in the wrong order
 */ 


function bubble_sort(list) {
  sorted = false;
  while (!sorted) {
    sorted = true;
    for (var i = 0; i < list.length - 1; i++) {
      if (list[i] > list[i + 1]) {
        var temp = list[i + 1]
        list[i + 1] = list[i]
        list[i] = temp
        sorted = false
      }
    }
    if (sorted) {
      return list
    }
  }
}

/*
 * Example
 */

var sorted = bubble_sort([2, 4, -9, 3, 1, 6, 5, 7]);
console.log(sorted);