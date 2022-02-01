func selectionSort(_ arry: [Int]) -> [Int] {
    var arr = arry
  // Traverse through all array elements
  for iterationIndex in 0 ..< arr.count - 1 {
    var minIndex = iterationIndex
    
    // Find the minimum element in remaining
    // unsorted array
    for compareIndex in iterationIndex + 1 ..< arr.count {
      if arr[compareIndex] < arr[minIndex] {
        minIndex = compareIndex
      }
    }

    // Swap the found minimum element with
    // the first element
    arr.swapAt(iterationIndex, minIndex)
  }
    return arr
}

print(selectionSort([5,4,6,3,2,1]))

