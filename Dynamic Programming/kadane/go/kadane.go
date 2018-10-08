package main

import (
	"fmt"
	"math"
)

func kadane(arr []int64)int64{
	var currsum, maxsum int64 = 0, math.MinInt64
	for i := 0; i < len(arr); i++{
		currsum += arr[i]
		if currsum > maxsum {
			maxsum = currsum
		}
		if currsum < 0 {
			currsum = 0
		}
	}
	return maxsum
}

func main() {
	arr:= make([]int64, 25, 50)
	arr = []int64{-2, -3, 4, -1, -2, 1, 5, -3}
	fmt.Println(kadane(arr))
}

