package main

import (
	"fmt"
	"math"
)

func lis(arr []int64) int64 {
	var ans int64 = 0
	dp := make([]int64, len(arr))
	for i := 0; i < len(arr); i++ {
		dp[i] = 1
		for j := 0; j < i; j++ {
			if arr[j] < arr[i] {
				dp[i] = int64(math.Max(float64(dp[j]+1), float64(dp[i])))
			}
		}
		ans = int64(math.Max(float64(ans), float64(dp[i])))
	}
	return ans
}

func main() {
	arr := make([]int64, 25, 50)
	arr = []int64{10, 22, 9, 33, 21, 50, 41, 60, 80}
	fmt.Println(lis(arr))
}

