//a simple implementation of 0-1 Knapsack problem in Go

package Knapsack

import (
	"math"
	"fmt"
)

func max(a, b int) int{
	return int(math.Max(float64(a), float64(b)))
}

func solve(maxWeight int, weights, values []int) int {
	n := len(weights)
	m := maxWeight
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, m+1)
	}
	for i := 0; i < len(weights); i++ {
		for j := 0; j <= maxWeight; j++ {
			if weights[i] > j {
				dp[i+1][j] = dp[i][j]
			} else {
				dp[i+1][j] = max(dp[i][j-weights[i]]+values[i], dp[i][j])
			}
		}
	}
	return dp[n][m]
}


func main() {
	maxWeight := 50
	values := []int{
		60, 100, 120,
	}
	weights := []int{
		10, 20, 30,
	}
	maxProfit := solve(maxWeight, weights, values)
	fmt.Println(maxProfit)
}

/* 
Input:
maxWeight = 50
values = 60, 100, 120
weights = 10, 20, 30

Output:
220
*/
