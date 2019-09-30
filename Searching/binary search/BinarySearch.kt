fun <T: Comparable<T>> binarySearch(list: List<T>, key: T): Int? {
    var rangeStart = 0
    var rangeEnd = list.count()
    while (rangeStart < rangeEnd) {
        val midIndex = rangeStart + (rangeEnd - rangeStart)/2
        if (list[midIndex] == key) {
            return midIndex
        } else if (list[midIndex] < key) {
            rangeStart = midIndex + 1
        } else {
            rangeEnd = midIndex
        }
    }
    return null
}
