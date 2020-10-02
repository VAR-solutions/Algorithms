def search(input: List[Int], value: Int): Int = {
	var start = 0
	var end = input.length - 1

	while (start <= end) {
		val mid = (start + end) / 2

		if (input(mid) == value) return mid

		if (input(mid) > value) end = mid - 1
		else start = mid + 1
	}
	-1
}
