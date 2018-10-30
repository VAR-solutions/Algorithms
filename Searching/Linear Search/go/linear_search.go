package main

import (
	"fmt"
	"strconv"
)

func main() {
	array := []int32{23, 42, 65, 75, 92, 75, 21, 56, 32, 93}
	status := search(array, 42)
	fmt.Println(status)
}

func search(array []int32, target int32) string {
	for i := range array {
		if array[i] == target {
			return "found at " + strconv.Itoa(i)
		}
	}
	return "not found"
}
