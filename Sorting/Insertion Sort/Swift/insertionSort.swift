func insertionSort(a: [Int]) -> [Int] {
    guard a.count > 1 else { return a } // If have 1 or less items, we're already finished
    
    var b = a
    for i in 1..<b.count {
        var y = i
        while y > 0 && b[y] < b[y - 1] {
            swap(&b[y - 1], &b[y])
            y -= 1
        }
    }
    return b
}
