package main

import (
	"sort"
	"math"
	"fmt"
)

func jump_search(arr []int, x int) int{
	length := float64(len(arr))
	step := math.Sqrt(length)

	prev := 0
	for arr[int(math.Min(step, length) - 1)] < x {
		prev = int(step)
		step = step + math.Sqrt(length)
		if prev >= int(length) {
			return -1
		}
	}	

	for arr[int(prev)] < x {
		prev = prev + 1
		if prev == int(math.Min(step, length)) {
			return -1
		}
	}

	if arr[int(prev)] == x {
		return prev
	}

	return -1
}

func main() {
	length := 0
	x := 0
	fmt.Println("Enter the length of array")
	fmt.Scanln(&length)
	fmt.Println("Enter elements of array")
	array := make([]int, length)
    for i := 0; i < length; i++ {
        fmt.Scanln(&array[i])
	}
	fmt.Printf("Your array : %v \n", array)
	sort.Ints(array)
	fmt.Printf("Your sorted array : %v \n", array)
	fmt.Println("Enter elements you looking for")
	fmt.Scanln(&x)
	result := jump_search(array, x)
	fmt.Printf("%v is in array index %v", x, result)
}