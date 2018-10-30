package main

import "fmt"

var (
	visitedNode []int
	graph   [][]int
)

func dfs(actual int) {
	fmt.Printf("Current Visiting node %d\n", actual)
	visitedNode[actual] = 1
	for i := 0; i < len(graph[actual]); i++ {
		if visitedNode[graph[actual][i]] == 0 {
			dfs(graph[actual][i])
		}
	}
}

func main() {
	var n, e int
	fmt.Println("Enter number of nodes and edges in this format: \n5 4")
	fmt.Scanf("%d %d", &n, &e)
	visitedNode = make([]int, n)
	graph = make([][]int, n)
	for i := 0; i < n; i++ {
		graph[i] = make([]int, 0)
	}

	var x, y int
	for i := 0; i < e; i++ {
		fmt.Printf("add next edge, input nodes numbers separed by a space (beetwen 0 and %d), in this format: 0 1\n", n)
		fmt.Scanf("%d %d", &x, &y)
		graph[x] = append(graph[x], y)
		graph[y] = append(graph[y], x)
	}

	dfs(0)

}
