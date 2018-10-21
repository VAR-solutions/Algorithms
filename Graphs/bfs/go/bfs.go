package main
import "fmt"

var nodes = map[int][]int{
     1: []int{2, 3, 4},
     2: []int{1, 5, 6},
     3: []int{1},
     4: []int{1, 7, 8},
     5: []int{2, 9, 10},
     6: []int{2},
     7: []int{4, 11, 12},
     8: []int{4},
     9: []int{5},
    10: []int{5},
    11: []int{7},
    12: []int{7},
}

func main() {
    visited := []int{}
    bfs(1, nodes, func (node int) {
        visited = append(visited, node)
    })
    fmt.Println(visited)
}

func bfs(start int, nodes map[int][]int, fn func (int)) {
    frontier := []int{start}
    visited := map[int]bool{}
    next := []int{}

    for 0 < len(frontier) {
        next = []int{}
        for _, node := range frontier {
            visited[node] = true
            fn(node)
            for _, n := range bfs_frontier(node, nodes, visited) {
                next = append(next, n)
            }
        }
        frontier = next
    }
}

func bfs_frontier(node int, nodes map[int][]int, visited map[int]bool) []int {
    next := []int{}
    iter := func (n int) bool { _, ok := visited[n]; return !ok }
    for _, n := range nodes[node] {
        if iter(n) {
            next = append(next, n)
        }
    }
    return next
}
