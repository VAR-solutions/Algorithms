package main

import (
	"fmt"
)

func GnomeSort(slice []int) []int {
	pos := 0
	for pos < len(slice) {
		if pos == 0 || slice[pos] >= slice[pos-1] {
			pos++
		} else {
			tmp := slice[pos]
			slice[pos] = slice[pos-1]
			slice[pos-1] = tmp
			pos--
		}
	}

	return slice
}

func main() {
	slice := []int{43, 41, 82, 2, 16, 7}
	fmt.Println(slice)
	fmt.Println(GnomeSort(slice))
}
