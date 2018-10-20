package main

import "fmt"

// example of Floyd-Warshall algorithm to find all-pair shortest paths
// more information on: https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
func main() {
	INF := 2000000000
	// distance between nodes
	dist := make([][]int, 5)
	for i := range dist {
		dist[i] = []int{INF, INF, INF, INF, INF}
		dist[i][i] = 0
	}
	dist[0][1] = 1
	dist[0][3] = 5
	dist[1][2] = 2
	dist[2][3] = 1
	dist[3][1] = 1
	dist[3][4] = 5
	dist[4][0] = 1
	dist[4][2] = 1

	// Floyd-Warshall implementation
	for k := 0; k < 5; k++ {
		for i := 0; i < 5; i++ {
			for j := 0; j < 5; j++ {
				if dist[i][k]+dist[k][j] < dist[i][j] {
					dist[i][j] = dist[i][k] + dist[k][j]
				}
			}
		}
	}

	// Printing out results
	for i := 0; i < 5; i++ {
		fmt.Println(fmt.Sprintf("Distance from node %v to:", i))
		for j := 0; j < 5; j++ {
			fmt.Println(fmt.Sprintf("  %v: %v", j, dist[i][j]))
		}
	}
}
