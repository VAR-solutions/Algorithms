package main

import "fmt"

func BinarySearch(slice []int, key int) int {
	pos := -1
	low := 0
	high := len(slice) - 1

	for low <= high {
		mid := (low + high) / 2
		if key < slice[mid] {
			high = mid - 1
		} else if key > slice[mid] {
			low = mid + 1
		} else {
			pos = mid
			break
		}
	}

	return pos
}

func main() {
	slice := []int{2, 7, 16, 41, 42, 82}
	key := 2
	fmt.Println(slice, key)
	fmt.Println(BinarySearch(slice, key))

	key = 91
	fmt.Println(slice, key)
	fmt.Println(BinarySearch(slice, key))
}
