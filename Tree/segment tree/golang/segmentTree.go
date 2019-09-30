package main

import "fmt"
import "math"

var tree []int
var array []int

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func buildTree(node, start, end int) {
	if start == end {
		tree[node] = array[start]
		return
	}
	mid := (start + end) / 2
	buildTree(2*node, start, mid)
	buildTree(2*node+1, mid+1, end)
	tree[node] = min(tree[2*node], tree[2*node+1])
}

func update(node, start, end, pos, value int) {
	if start > pos || end < pos {
		return
	}
	if start == end {
		tree[node] = value
		return
	}
	mid := (start + end) / 2
	update(2*node, start, mid, pos, value)
	update(2*node+1, mid+1, end, pos, value)
	tree[node] = min(tree[2*node], tree[2*node+1])
}

func query(node, start, end, i, j int) int {
	if start >= i && end <= j {
		return tree[node]
	}
	if start > j || end < i {
		return math.MaxInt32
	}
	mid := (start + end) / 2
	return min(query(2*node, start, mid, i, j), query(2*node+1, mid+1, end, i, j))
}

func main() {
	array = []int{11, 2, 3, -1, 5, 0, 9, 7}
	tree = make([]int, 2*len(array))
	buildTree(1, 0, len(array)-1)

	fmt.Printf("Min [11, 2, 3, -1, 5, 0, 9, 7] = %d\n", query(1, 0, len(array)-1, 0, 7))
	fmt.Printf("Min 11, 2, 3, -1, 5, [0, 9, 7] = %d\n", query(1, 0, len(array)-1, 5, 7))

	update(1, 0, len(array)-1, 3, 4)

	fmt.Printf("Min [11, 2, 3, 4, 5, 0, 9, 7] = %d\n", query(1, 0, len(array)-1, 0, 7))
	fmt.Printf("Min [11, 2, 3, 4, 5], 0, 9, 7 = %d\n", query(1, 0, len(array)-1, 0, 4))
}

