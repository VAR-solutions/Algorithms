// Binary search is a method of searching through a
// list that assumes the list is sorted. It has O(log(n)) runtime
// because every search, you cut the list in half,
// eliminating the need to search through half the values

object BinarySearch {
	def search(input: List[Int], value: Int): Int = {
		var start = 0
		var end = input.length - 1

		while (start <= end) {
			val mid = (start + end) / 2 // middle point in the array

			if (input(mid) == value) return mid // return index if at value

			// move the search area to first half of current search area
			if (input(mid) > value) end = mid - 1

			// otherwise, move search area to second half
			else start = mid + 1
		}
		-1 // value not in list
	}

	// assumes input list is sorted, shouldn't handle malformed lists
	def test: Boolean = {
		// non-existant searches
		if (search(List(), 4) != -1) return false
		if (search(List(1, 2, 3), 4) != -1) return false
		if (search(List(1, 3, 5, 8, 9), 4) != -1) return false

		// existant searches
		if (search(List(1, 3, 5, 8, 9), 1) != 0) return false
		if (search(List(1, 3, 5, 8, 9), 9) != 4) return false
		if (search(List(1, 3, 5, 8, 9), 5) != 2) return false
		if (search(List(1, 10, 100, 1000, 10000, 100000, 1000000), 100000) != 5) return false
		true
	}
}